/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GUI - textfield draw
*/

#include "GUI/gui_head.h"

struct gui_output *textfield_draw(size_t field_adr, sfRenderWindow *window)
{
    textfield_t *field = (textfield_t *)field_adr;

    sfRenderWindow_drawText(window, field->text, NULL);
    return NULL;
}

struct gui_output *textfield_draw_texture(size_t field_adr, \
sfRenderTexture *texture)
{
    textfield_t *field = (textfield_t *)field_adr;

    sfRenderTexture_drawText(texture, field->text, NULL);
    return NULL;
}