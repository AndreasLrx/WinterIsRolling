/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GUI - button
*/

#include "GUI/gui_head.h"

struct gui_output *button_draw(size_t btn_adr, sfRenderWindow *window)
{
    button_t *btn = (button_t *)btn_adr;
    int state = btn->state;

    if (btn->infos->nb_states == 2 && state == GUI_CLICKED)
        state--;
    sfRenderWindow_drawRectangleShape(window, btn->rect[state], NULL);
    return NULL;
}

struct gui_output *button_draw_texture(size_t btn_adr, sfRenderTexture *texture)
{
    button_t *btn = (button_t *)btn_adr;
    int state = btn->state;

    if (btn->infos->nb_states == 2 && state == GUI_CLICKED)
        state--;
    sfRenderTexture_drawRectangleShape(texture, btn->rect[state], NULL);
    return NULL;
}