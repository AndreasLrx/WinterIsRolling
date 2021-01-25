/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** game struct destrouy
*/

#include "Game/game_struct.h"

void game_struct_destroy(game_t **game_adr)
{
    game_t *game = *game_adr;

    background_destroy(&game->background);
    player_destroy(game->player);
    pe_world_destroy(game->world);
    *game_adr = NULL;
}