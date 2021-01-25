/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** tilemap coords conversions
*/

#include "Game/TileMap/tilemap_head.h"

sfVector2i tilemap_pixel_to_tile(tilemap_t *map, \
sfVector2i pos)
{
    sfVector2f coords = sfRenderWindow_mapPixelToCoords(\
    map->window, pos, map->view);
    sfVector2i tile_pos = {coords.x / map->tile_size, \
        coords.y / map->tile_size};

    if (coords.x < 0)
        tile_pos.x--;
    if (coords.y < 0)
        tile_pos.y--;
    return tile_pos;
}