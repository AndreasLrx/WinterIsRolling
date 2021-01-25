/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** tilemap destroy
*/

#include "Game/TileMap/tilemap_head.h"
#include "my_containers/my_map.h"

static void destroy_layer(tilemap_t *map, int layer)
{
    size_t size_layer = my_map_size(map->draw_map[layer]);

    for (size_t i = 0; i < size_layer; i++)
        sfRectangleShape_destroy((sfRectangleShape *)\
        my_map_at(map->draw_map[layer], i));
}

void tilemap_destroy(tilemap_t **map_adr)
{
    tilemap_t *map = *map_adr;

    sfView_destroy(map->view);
    free(map->map);
    for (int i = 0; i < map->nb_layers; i++) {
        destroy_layer(map, i);
        my_map_free(&map->draw_map[i]);
    }
    free(map->draw_map);
    free(map);
    *map_adr = NULL;
}