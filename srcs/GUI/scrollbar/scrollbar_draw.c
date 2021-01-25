/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GUI - scrollbar
*/

#include "GUI/gui_head.h"

struct gui_output *scrollbar_draw(size_t bar_adr, sfRenderWindow *window)
{
    scrollbar_t *bar = (scrollbar_t *)bar_adr;

    sfRenderWindow_drawRectangleShape(window, bar->bar_rects[0], NULL);
    if (bar->infos->fill)
        sfRenderWindow_drawRectangleShape(window, bar->bar_rects[1], NULL);
    button_draw((size_t)bar->cursor, window);
    return NULL;
}

struct gui_output *scrollbar_draw_texture(size_t bar_adr, \
sfRenderTexture *texture)
{
    scrollbar_t *bar = (scrollbar_t *)bar_adr;

    sfRenderTexture_drawRectangleShape(texture, bar->bar_rects[0], NULL);
    if (bar->infos->fill)
        sfRenderTexture_drawRectangleShape(texture, bar->bar_rects[1], NULL);
    button_draw_texture((size_t)bar->cursor, texture);
    return NULL;
}