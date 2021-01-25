/*
** EPITECH PROJECT, 2021
** My runner
** File description:
** game struct restart
*/

#include "Game/game_struct.h"

void game_struct_restart(game_t *game)
{
    player_respawn(game->player);
    game->player->respawn_left = PLAYER_LIVES;
}