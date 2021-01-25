/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** tilemap draw
*/

#include "Game/TileMap/tilemap_head.h"
#include "my_containers/my_map.h"
#include "GameEngine/game.h"
#include "functions.h"
#include "Game/Player/player.h"

void player_draw(struct player_t *player, sfRenderWindow *window);

static void draw_column(tilemap_t *map, int layer, int x, sfVector2i min_max)
{
    for (int y = min_max.x; y < min_max.y; y++) {
        if (map->map[layer][M_POS(x, y, map)] > 0)
            sfRenderWindow_drawRectangleShape(map->window, \
            (sfRectangleShape *)my_map_find(map->draw_map[layer], \
            M_POS(x, y, map)), NULL);
    }
}

static void draw_map(tilemap_t *map, sfVector2i min_pos, \
sfVector2i max_pos, sfVector2i min_max_y)
{
    int mid_layer = map->nb_layers / 2;

    for (int layer = 0; layer < mid_layer; layer++) {
        for (int x = min_pos.x; x < max_pos.x; x++)
            draw_column(map, layer, x, min_max_y);
    }
    player_draw(map->player, map->window);
    for (int layer = mid_layer; layer < map->nb_layers; layer++) {
        for (int x = min_pos.x; x < max_pos.x; x++)
            draw_column(map, layer, x, min_max_y);
    }
}

void tilemap_draw(tilemap_t *map)
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
    const sfView *base_view = sfRenderWindow_getDefaultView(map->window);

    sfRenderWindow_setView(map->window, map->view);
    draw_map(map, min_pos, max_pos, (sfVector2i){min_pos.y, max_pos.y});
    sfRenderWindow_setView(map->window, base_view);
}