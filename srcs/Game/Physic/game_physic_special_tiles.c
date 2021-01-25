/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Game special Tiles
*/

#include "Game/game_struct.h"

static void create_snowflake(pe_world_t *world, pe_vec2f_t pos)
{
    pe_body_t *body = pe_body_init(STATIC, 1, 0);
    pe_fixture_t *sensor = pe_fixture_init();

    sensor->is_sensor = 1;
    sensor->collision_filter.category = SNOWFLAKE;
    pe_shape_init_circle(&sensor->shape, 0.5f, VEC2F(0, 0));
    body->pos = VEC2F(pos.x + 0.5f, pos.y + 0.5f);
    pe_body_add_fixture(body, sensor);
    pe_world_add_body(world, body);
}

static void create_water_ice(pe_world_t *world, pe_vec2f_t pos, \
int tile_type, int tile)
{
    pe_body_t *body = pe_body_init(STATIC, 1, 0);
    pe_fixture_t *sensor = pe_fixture_init();
    pe_vec2f_t size = {1, (tile <= 38) ? 0.643 : 1};

    body->pos = VEC2F(pos.x + 0.5f, pos.y + 0.5f);
    sensor->is_sensor = (tile_type == WATER);
    sensor->collision_filter.category = tile_type;
    pe_shape_init_rect(&sensor->shape, VEC2F(0, 0.5 - size.y / 2.f), size);
    pe_body_add_fixture(body, sensor);
    pe_world_add_body(world, body);
}

static void create_spike(pe_world_t *world, pe_vec2f_t pos, int tile)
{
    pe_body_t *body = pe_body_init(STATIC, 1, 0);
    pe_fixture_t *sensor = pe_fixture_init();
    pe_vec2f_t size = {1, 0.5};
    int down = (tile >= 45 && tile <= 47);

    body->pos = VEC2F(pos.x + 0.5f, pos.y + 0.5f);
    sensor->is_sensor = 1;
    sensor->collision_filter.category = SPIKE;
    pe_shape_init_rect(&sensor->shape, VEC2F(0, 0.25 * (down ? 1 : -1)), size);
    pe_body_add_fixture(body, sensor);
    pe_world_add_body(world, body);
}

int create_special_tile(pe_world_t *world, int value, pe_vec2f_t pos)
{
    int tile_type = game_struct_get_tile_type(value);

    if (tile_type == GROUND)
        return 0;
    switch (tile_type) {
    case SNOWFLAKE:
        create_snowflake(world, pos);
        break;
    case WATER:
        create_water_ice(world, pos, WATER, M_TILE(value));
        break;
    case ICE:
        create_water_ice(world, pos, ICE, M_TILE(value));
        break;
    case SPIKE:
        create_spike(world, pos, M_TILE(value));
        break;
    default:
        break;
    }
    return 1;
}