/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** parallax background - draw
*/

#include "Drawables/background.h"
#include <stdio.h>

void background_draw(background_t *bg, sfRenderWindow *window)
{
    for (int i = 0; i < bg->nb_axes; i++){
        sfRenderWindow_drawRectangleShape(window, bg->rects[i], NULL);
    }
}

void background_draw_texture(background_t *bg, sfRenderTexture *texture)
{
    for (int i = 0; i < bg->nb_axes; i++){
        sfRenderTexture_drawRectangleShape(texture, bg->rects[i], NULL);
    }
}