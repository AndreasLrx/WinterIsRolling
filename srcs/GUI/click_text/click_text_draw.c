/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GUI - click text draw
*/

#include <stdio.h>
#include "GUI/gui_head.h"

struct gui_output *click_text_draw(size_t click_text_adr, \
sfRenderWindow *window)
{
    click_text_t *text = (click_text_t *)click_text_adr;

    sfRenderWindow_drawText(window, text->texte, NULL);
    return NULL;
}

struct gui_output *click_text_draw_texture(size_t click_text_adr, \
sfRenderTexture *texture)
{
    click_text_t *text = (click_text_t *)click_text_adr;

    sfRenderTexture_drawText(texture, text->texte, NULL);
    return NULL;
}