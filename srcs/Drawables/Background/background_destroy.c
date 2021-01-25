/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** parallax background - destroy
*/

#include <stdlib.h>
#include "Drawables/background.h"

void background_destroy(background_t **bg_adr)
{
    background_t *bg = *bg_adr;

    for (int i = 0; i < bg->nb_axes; i++)
        sfRectangleShape_destroy(bg->rects[i]);
    free(bg->rects);
    free(bg);
    *bg_adr = NULL;
}