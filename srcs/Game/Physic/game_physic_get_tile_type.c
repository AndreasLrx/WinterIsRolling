/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** game physic get tile type
*/

#include "Game/game_struct.h"

static int is_tile_water(int set, int tile)
{
    return (tile == 35 || tile == 36 || tile == 49 || tile == 50);
}

static int is_tile_spike(int set, int tile)
{
    return ((tile >= 42 && tile <= 47) || tile == 59);
}

static int is_tile_ice(int set, int tile)
{
    return (tile == 37 || tile == 38 || tile == 51 || tile == 52);
}

int game_struct_get_tile_type(int tile_value)
{
    int set = M_SET(tile_value);
    int tile = M_TILE(tile_value);

    if (set == 0)
        return (tile == 82) ? SNOWFLAKE : GROUND;
    if (set != 1)
        return NONE;
    if (is_tile_water(set, tile))
        return WATER;
    if (is_tile_spike(set, tile))
        return SPIKE;
    if (is_tile_ice(set, tile))
        return ICE;
    return NONE;
}