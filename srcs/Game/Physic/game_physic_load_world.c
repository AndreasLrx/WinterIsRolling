/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** game physic - load world
*/

#include "Game/game_struct.h"

int resolve_two_missing(pe_vec2f_t *vertices, sfImage *image, \
int tile_size, pe_vec2f_t tile_pos);
int resolve_one_missing(pe_vec2f_t *vertices, sfImage *image, \
int tile_size, pe_vec2f_t tile_pos);
int fill_corners(pe_vec2f_t *vertices, sfImage *image, \
int tile_size, pe_vec2f_t tile_pos);
int create_special_tile(pe_world_t *world, int value, pe_vec2f_t pos);

static pe_fixture_t *create_fixture(pe_vec2f_t *vertices, int triangle)
{
    pe_fixture_t *fixture = pe_fixture_init();
    pe_vec2f_t *v_alloc = malloc(sizeof(pe_vec2f_t) * (4 - triangle));
    int v_count = 0;

    for (int i = 0; i < 4; i++) {
        if (vertices[i].x >= 0)
            v_alloc[v_count++] = VEC2F_SUB1(vertices[i], 0.5f);
    }
    fixture->collision_filter.category = GROUND;
    pe_shape_init_polygon(&fixture->shape, VEC2F(0, 0), v_alloc, 4 - triangle);
    return fixture;
}

static pe_fixture_t *find_tile_shape(int tile_value, \
config_t *cfg, sfImage **images)
{
    int id_set = M_SET(tile_value);
    tileset_t *set = cfg->tilesets[id_set];
    pe_vec2f_t vertices[4] = {{-1, -1}, {-1, -1}, {-1, -1}, {-1, -1}};
    pe_vec2f_t tile_pos = {T_X(M_TILE(tile_value), set), \
        T_Y(M_TILE(tile_value), set)};
    int nb_corners = fill_corners(vertices, images[id_set], \
    set->tile_size - 1, tile_pos);
    int triangle = 0;

    if (nb_corners == 3)
        triangle = resolve_one_missing(vertices, images[id_set], \
        set->tile_size - 1, tile_pos);
    if (nb_corners == 2)
        triangle = resolve_two_missing(vertices, images[id_set], \
        set->tile_size - 1, tile_pos);
    return create_fixture(vertices, triangle);
}

static void create_body(pe_world_t *world, pe_vec2f_t pos, pe_fixture_t *fix)
{
    pe_body_t *body = pe_body_init(STATIC, 2, 0);

    body->pos = pos;
    pe_body_add_fixture(body, fix);
    pe_world_add_body(world, body);
}

static void test_tile(tilemap_t *map, int pos, \
void *world_cfg_ptrs[2], sfImage **images)
{
    int x = M_X(pos, map);
    int y = M_Y(pos, map);
    pe_fixture_t *fix;

    if (!map->map[1][pos] || create_special_tile(world_cfg_ptrs[0], \
        map->map[map->nb_layers / 2][pos], VEC2F(x, y)))
        return;
    if (((x == 0) || (map->map[1][M_POS(x - 1, y, map)] == 0)) || \
    ((x == (map->size.x - 1)) || (map->map[1][M_POS(x + 1, y, map)] == 0)) || \
    ((y == 0) || (map->map[1][M_POS(x, y - 1, map)] == 0)) || \
    ((y == (map->size.y - 1)) || (map->map[1][M_POS(x, y + 1, map)] == 0))) {
        fix = find_tile_shape(map->map[1][M_POS(x, y, map)], \
        world_cfg_ptrs[1], images);
        create_body(world_cfg_ptrs[0], VEC2F(x + 0.5, y + 0.5), fix);
    }
}

void game_load_world(pe_world_t *world, tilemap_t *map, config_t *cfg)
{
    void *world_cfg_ptrs[2] = {world, cfg};
    sfImage *images[cfg->nb_sets];

    for (int i = 0; i < cfg->nb_sets; i++)
        images[i] = sfTexture_copyToImage(cfg->tilesets[i]->texture);
    for (int x = 0; x < map->size.x; x++) {
        for (int y = 0; y < map->size.y; y++)
            test_tile(map, M_POS(x, y, map), world_cfg_ptrs, images);
    }
    for (int i = 0; i < cfg->nb_sets; i++)
        sfImage_destroy(images[i]);
}