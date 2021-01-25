/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Game struct update
*/

#include "Game/game_struct.h"

static void move_map(game_t *game)
{
    sfVector2f player_pos = sfRectangleShape_getPosition(game->player->shape);
    sfVector2f view_pos = sfView_getCenter(game->map->view);
    sfVector2f offset = {player_pos.x - view_pos.x, player_pos.y - \
        (view_pos.y - 400 * SCL(game->state))};

    tilemap_move(game->map, offset);
    sfView_move(game->map->view, (sfVector2f){0, -400 * SCL(game->state)});
    background_update(game->background, \
    (sfView_getCenter(game->map->view).x - view_pos.x) * 0.5f);
}

void game_struct_update(game_t *game, float dt)
{
    game->stats.time += dt / 1000.f;
    game->stats.score += 0.1;
    pe_world_update(game->world, dt);
    player_update(game->player, dt);
    move_map(game);
}