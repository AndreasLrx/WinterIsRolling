/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** parallax background
*/

#ifndef PARALLAX_BACKGROUND_H
#define PARALLAX_BACKGROUND_H

#include <SFML/Graphics.h>

typedef struct background_t {
    sfTexture *texture;
    sfVector2f size;
    sfRectangleShape **rects;
    int nb_axes;
    float offset;
    sfVector2f scale;
} background_t;

background_t *background_init(sfTexture *texture, sfVector2f size, \
int nb_axes, sfVector2f scale);
void background_update(background_t *bg, float offset);
void background_draw(background_t *bg, sfRenderWindow *window);
void background_draw_texture(background_t *bg, sfRenderTexture *texture);
void background_destroy(background_t **bg_adr);

#endif /* !PARALLAX_BACKGROUND_H */