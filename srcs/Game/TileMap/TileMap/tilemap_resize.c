/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** TIlemap resize
*/

#include "Game/TileMap/tilemap_head.h"
#include "my_containers/my_map.h"
#include "My/my_memory.h"

static void clear_pos(tilemap_t *map, int pos)
{
    for (int lyr = 0; lyr < map->nb_layers; lyr++) {
        if (map->map[lyr][pos] != 0) {
            sfRectangleShape_destroy((sfRectangleShape *)\
            my_map_find(map->draw_map[lyr], pos));
            my_map_erase_key(map->draw_map[lyr], pos);
            map->map[lyr][pos] = 0;
        }
    }
}

static void delete_rects(tilemap_t *map, sfVector2u new_size)
{
    for (int x = new_size.x; x < map->size.x; x++) {
        for (int y = 0; y < map->size.y; y++)
            clear_pos(map, M_POS(x, y, map));
    }
    for (int x = 0; x < map->size.x; x++) {
        for (int y = new_size.y; y < map->size.y; y++)
            clear_pos(map, M_POS(x, y, map));
    }
}

static void copy_int(tilemap_t *map, int pos, int **new_map)
{
    for (int layer = 0; layer < map->nb_layers; layer++)
        new_map[layer][pos] = map->map[layer][pos];
}

static void copy_ints(tilemap_t *map, sfVector2u new_size, int **new_map)
{
    for (int x = 0; x < map->size.x; x++) {
        for (int y = 0; y < map->size.y; y++) {
            copy_int(map, M_POS(x, y, map), new_map);
        }
    }
}

void tilemap_resize(tilemap_t *map, sfVector2u new_size, int only_up)
{
    int **new_map;

    if (new_size.x == map->size.x && new_size.y == map->size.y)
        return;
    if (only_up && new_size.x <= map->size.x && new_size.y <= map->size.y)
        return;
    delete_rects(map, new_size);
    new_map = malloc(sizeof(int *) * map->nb_layers);
    for (int i = 0; i < map->nb_layers; i++)
        new_map[i] = my_calloc(sizeof(int) * new_size.x * new_size.y, 0);
    copy_ints(map, new_size, new_map);
    free(map->map);
    map->map = new_map;
}