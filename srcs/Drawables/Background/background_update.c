/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Parallax background - update
*/

#include <stdio.h>
#include "Drawables/background.h"
#include "My/my_maths.h"

void background_update(background_t *bg, float offset)
{
    bg->offset += offset * bg->scale.x;

    for (int i = 0; i < bg->nb_axes; i++){
        sfRectangleShape_setTextureRect(bg->rects[i], \
        (sfIntRect){bg->offset / my_pow(2, (bg->nb_axes - 1 - i)), \
            bg->size.y * i, bg->size.x, bg->size.y});
    }
}