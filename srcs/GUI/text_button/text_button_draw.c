/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GUI - text_button
*/

#include "GUI/gui_head.h"

struct gui_output *text_button_draw(size_t txt_btn_adr, sfRenderWindow *window)
{
    text_button_t *btn = (text_button_t *)txt_btn_adr;

    button_draw((size_t)btn->btn, window);
    sfRenderWindow_drawText(window, btn->text, NULL);
    return NULL;
}

struct gui_output *text_button_draw_texture(size_t txt_btn_adr, \
sfRenderTexture *texture)
{
    text_button_t *btn = (text_button_t *)txt_btn_adr;

    button_draw_texture((size_t)btn->btn, texture);
    sfRenderTexture_drawText(texture, btn->text, NULL);
    return NULL;
}