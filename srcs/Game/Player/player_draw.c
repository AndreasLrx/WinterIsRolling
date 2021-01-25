/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Player draw
*/

#include "Game/game_struct.h"

void player_draw(player_t *player, sfRenderWindow *wind)
{
    sfRenderWindow_drawRectangleShape(wind, player->shape, NULL);
}

void player_draw_texture(player_t *player, sfRenderTexture *texture)
{
    sfRenderTexture_drawRectangleShape(texture, player->shape, NULL);
}