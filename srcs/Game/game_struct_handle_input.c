/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Game struct handle input
*/

#include "Game/game_struct.h"

void game_struct_handle_input(game_t *game, sfEvent event)
{
    player_handle_input(game->player, event);
}