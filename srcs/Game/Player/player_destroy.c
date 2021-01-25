/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** player destroy
*/

#include "Game/game_struct.h"

void player_destroy(player_t *player)
{
    sfRectangleShape_destroy(player->shape);
}