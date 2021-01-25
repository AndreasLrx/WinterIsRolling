/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** tilemap zoom
*/

#include "Game/TileMap/tilemap_head.h"
#include "functions.h"

static int verif_zoom(tilemap_t *map, float zoom)
{
    float new_size = map->tile_size / (map->current_zoom * zoom);

    if (new_size <= 10 || new_size > \
        (MIN(map->view_size.x, map->view_size.y) / 2.f))
        return 0;
    return 1;
}

void tilemap_zoom(tilemap_t *map, sfVector2i mouse_pos, float zoom)
{
    sfVector2f bef_coo = \
    sfRenderWindow_mapPixelToCoords(map->window, mouse_pos, map->view);
    sfVector2f aft_coo;
    sfVector2f offset;

    if (!verif_zoom(map, zoom))
        return;
    map->current_zoom *= zoom;
    sfView_zoom(map->view, zoom);
    aft_coo = sfRenderWindow_mapPixelToCoords(map->window, \
    mouse_pos, map->view);
    offset = (sfVector2f){bef_coo.x - aft_coo.x, bef_coo.y - aft_coo.y};
    sfView_move(map->view, offset);
    tilemap_correct_pos(map);
}