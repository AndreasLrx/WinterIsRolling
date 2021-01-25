/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** tilemap place tile
*/

#include "Game/TileMap/tilemap_head.h"
#include "my_containers/my_map.h"

void tilemap_place_tile(tilemap_t *map, sfVector2i pos, \
tileset_t *set, int tile_value)
{
    sfRectangleShape *rect = sfRectangleShape_create();
    int tile = M_TILE(tile_value);

    if (M_X(pos.y, map) >= map->size.x || M_Y(pos.y, map) >= map->size.y)
        return;
    sfRectangleShape_setPosition(rect, \
    (sfVector2f){M_X(pos.y, map) * map->tile_size, \
        M_Y(pos.y, map) * map->tile_size});
    sfRectangleShape_setTexture(rect, set->texture, 1);
    sfRectangleShape_setTextureRect(rect, (sfIntRect)\
    {(tile % set->size.x) * set->tile_size, \
        (tile / set->size.x) * set->tile_size, \
        set->tile_size, set->tile_size});
    sfRectangleShape_setSize(rect, \
    (sfVector2f){map->tile_size, map->tile_size});
    my_map_insert(map->draw_map[pos.x], (size_t)pos.y, (size_t)rect);
    map->map[pos.x][pos.y] = tile_value;
}

void tilemap_change_tile(tilemap_t *map, sfVector2i pos, \
tileset_t *set, int tile_value)
{
    sfRectangleShape *rect;
    int tile = M_TILE(tile_value);

    if (M_X(pos.y, map) >= map->size.x || M_Y(pos.y, map) >= map->size.y)
        return;
    if (map->map[pos.x][pos.y] == 0) {
        tilemap_place_tile(map, pos, set, tile_value);
        return;
    }
    rect = (sfRectangleShape *)\
    my_map_find(map->draw_map[pos.x], pos.y);
    sfRectangleShape_setTexture(rect, set->texture, 1);
    sfRectangleShape_setTextureRect(rect, \
    (sfIntRect){(tile % set->size.x) * set->tile_size, \
        (tile / set->size.x) * set->tile_size, \
        set->tile_size, set->tile_size});
    map->map[pos.x][pos.y] = tile_value;
}

void tilemap_remove_tile(tilemap_t *map, sfVector2i pos)
{
    if (M_X(pos.y, map) >= map->size.x || M_Y(pos.y, map) >= map->size.y)
        return;
    if (!map->map[pos.x][pos.y])
        return;
    sfRectangleShape_destroy((sfRectangleShape *)\
    my_map_find(map->draw_map[pos.x], pos.y));
    map->map[pos.x][pos.y] = 0;
}