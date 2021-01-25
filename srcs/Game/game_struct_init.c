/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Game struct init
*/

#include "Game/game_struct.h"
#include "Game/TileMap/tilemap_head.h"

game_t *game_struct_init(state_t *state, int level_id)
{
    game_t *game = malloc(sizeof(game_t));

    game->global_stats = (global_stats_t *)state->game_data->datas;
    game->background = background_init(\
    get_texture(state->game_data->assets, "parallax_bg"), \
    (sfVector2f){1800, 893}, 4, (sfVector2f){SCL(state) * 1.21, \
        SCL(state) * 1.21});
    game->state = state;
    game->stats = (game_stats_t){0, 0, 0, level_id};
    game->cfg = config_init("config.cfg");
    game->map = tilemap_init((sfIntRect){0, 0, \
        1920 * SCL(state), 1080 * SCL(state)}, \
    (sfVector2u){1, 1}, game->cfg->tile_size, 3);
    tilemap_open(game->map, MAP_NAMES[level_id], game->cfg);
    game->world = pe_world_init(VEC2F(0, 9.81), \
    (game->map->size.x * game->map->size.y) / 10);
    game->player = player_init(game, (sfVector2i){1, -5}, \
    game->world, game->map->tile_size);
    game->map->window = state->game_data->window;
    game_load_world(game->world, game->map, game->cfg);
    return game;
}