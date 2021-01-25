/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** tilemap move
*/

#include "Game/TileMap/tilemap_head.h"

void tilemap_correct_pos(tilemap_t *map)
{
    sfVector2f top_left = sfRenderWindow_mapPixelToCoords(map->window, \
    (sfVector2i){map->pos.x, map->pos.y}, map->view);
    sfVector2f bottom_right = sfRenderWindow_mapPixelToCoords(map->window, \
    (sfVector2i){map->pos.x + map->view_size.x, \
        map->pos.y + map->view_size.y}, map->view);
    sfVector2f offset = {((top_left.x < 0) ? -top_left.x : 0), \
        ((top_left.y < 0) ? -top_left.y : 0)};

    if (offset.x == 0 && bottom_right.x > (map->size.x * map->tile_size))
        offset.x = (map->size.x * map->tile_size) - bottom_right.x;
    if (offset.y == 0 && bottom_right.y > (map->size.y * map->tile_size))
        offset.y = (map->size.y * map->tile_size) - bottom_right.y;
    sfView_move(map->view, offset);
}

void tilemap_move(tilemap_t *map, sfVector2f offset)
{
    sfView_move(map->view, offset);
    tilemap_correct_pos(map);
}