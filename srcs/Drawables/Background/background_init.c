/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** parallax background init
*/

#include <stdlib.h>
#include "Drawables/background.h"

static void init_rect_shapes(background_t *bg)
{
    sfRectangleShape *rect;

    for (int i = 0; i < bg->nb_axes; i++){
        rect = sfRectangleShape_create();
        sfRectangleShape_setSize(rect, bg->size);
        sfRectangleShape_setTexture(rect, bg->texture, 1);
        sfRectangleShape_setTextureRect(rect, (sfIntRect){0, bg->size.y * i, \
            bg->size.x, bg->size.y});
        sfRectangleShape_setScale(rect, bg->scale);
        bg->rects[i] = rect;
    }
}

background_t *background_init(sfTexture *texture, sfVector2f size, \
int nb_axes, sfVector2f scale)
{
    background_t *background = malloc(sizeof(background_t));

    sfTexture_setRepeated(texture, 1);
    background->nb_axes = nb_axes;
    background->texture = texture;
    background->scale = scale;
    background->size = size;
    background->offset = 0;
    background->rects = malloc(sizeof(sfRectangleShape *) * nb_axes);
    init_rect_shapes(background);
    return background;
}