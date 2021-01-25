/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** tile map init
*/

#include <stdlib.h>
#include "Game/TileMap/tilemap_head.h"
#include "My/my_memory.h"
#include "my_containers/my_map.h"
#include "functions.h"
#include "GameEngine/game.h"

tilemap_t *tilemap_init(sfIntRect rect, sfVector2u size, \
int tile_size, int nb_layers)
{
    tilemap_t *map = malloc(sizeof(tilemap_t));

    map->size = size;
    map->pos = (sfVector2f){rect.left, rect.top};
    map->view_size = (sfVector2f){rect.width, rect.height};
    map->tile_size = tile_size;
    map->nb_layers = nb_layers;
    map->current_zoom = 1;
    map->view = sfView_create();
    map->map = malloc(sizeof(int *) * nb_layers);
    map->draw_map = my_calloc(sizeof(my_map_t *) * nb_layers, 0);
    for (int i = 0; i < nb_layers; i++) {
        map->map[i] = my_calloc(sizeof(int) * size.x * size.y, 0);
        map->draw_map[i] = my_map_init(sizeof(int), \
        sizeof(sfRectangleShape *), &my_map_intcmp, 0);
    }
    sfView_setSize(map->view, (sfVector2f){1280, 720});
    sfView_setCenter(map->view, (sfVector2f){640, 360});
    sfView_move(map->view, (sfVector2f){-map->pos.x, -map->pos.y});
    return map;
}

static void tilemap_regen_pos(tilemap_t *map, int pos)
{
    if (map->map[M_ACTIVE_LAYER(map)][pos] < 0)
        map->map[M_ACTIVE_LAYER(map)][pos] *= -1;
}

void tilemap_regen(tilemap_t *map)
{
    for (int x = 0; x < map->size.x; x++) {
        for (int y = 0; y < map->size.y; y++) {
            tilemap_regen_pos(map, M_POS(x, y, map));
        }
    }
}