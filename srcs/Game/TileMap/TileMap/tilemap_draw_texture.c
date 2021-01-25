/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Tilemap draw texture
*/

#include "Game/TileMap/tilemap_head.h"
#include "my_containers/my_map.h"
#include "functions.h"

void player_draw_texture(struct player_t *player, sfRenderTexture *texture);

static void draw_column(tilemap_t *map, sfVector2i layer_x, \
sfRenderTexture *texture, sfVector2i min_max)
{
    for (int y = min_max.x; y < min_max.y; y++) {
        if (map->map[layer_x.x][M_POS(layer_x.y, y, map)] != 0)
            sfRenderTexture_drawRectangleShape(texture, \
            (sfRectangleShape *)my_map_find(map->draw_map[layer_x.x], \
            M_POS(layer_x.y, y, map)), NULL);
    }
}

static void draw_map(tilemap_t *map, sfVector2i min_pos, \
sfVector2i max_pos, sfRenderTexture *texture)
{
    int mid_layer = map->nb_layers / 2;
    sfVector2i min_max_y = {min_pos.y, max_pos.y};

    for (int layer = 0; layer < mid_layer; layer++) {
        for (int x = min_pos.x; x < max_pos.x; x++)
            draw_column(map, (sfVector2i){layer, x}, texture, min_max_y);
    }
    player_draw_texture(map->player, texture);
    for (int layer = mid_layer; layer < map->nb_layers; layer++) {
        for (int x = min_pos.x; x < max_pos.x; x++)
            draw_column(map, (sfVector2i){layer, x}, texture, min_max_y);
    }
}

void tilemap_draw_texture(tilemap_t *map, sfRenderTexture *texture)
{
    sfVector2f top_left = sfRenderWindow_mapPixelToCoords(map->window, \
    (sfVector2i){map->pos.x, map->pos.y}, map->view);
    sfVector2f bottom_right = sfRenderWindow_mapPixelToCoords(map->window, \
    (sfVector2i){map->pos.x + map->view_size.x, \
        map->pos.y + map->view_size.y}, map->view);
    sfVector2i min_pos = {MAX(top_left.x / map->tile_size, 0), \
        MAX(top_left.y / map->tile_size, 0)};
    sfVector2i max_pos = {MIN(bottom_right.x / map->tile_size + 1, \
        map->size.x), MIN(bottom_right.y / \
        map->tile_size + 1, map->size.y)};
    const sfView *base_view = sfRenderTexture_getDefaultView(texture);

    sfRenderTexture_setView(texture, map->view);
    draw_map(map, min_pos, max_pos, texture);
    sfRenderTexture_setView(texture, base_view);
}