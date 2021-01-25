/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** game struct - draw
*/

#include "Game/game_struct.h"

void game_struct_draw(game_t *game, sfRenderWindow *window)
{
    background_draw(game->background, window);
    tilemap_draw(game->map);
}

void game_struct_draw_texture(game_t *game, sfRenderTexture *texture)
{
    background_draw_texture(game->background, texture);
    tilemap_draw_texture(game->map, texture);
}