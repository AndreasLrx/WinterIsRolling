/*
** EPITECH PROJECT, 2020
** My Runner
** File description:
** GUI - button destroy
*/

#include "GUI/gui_head.h"

struct gui_output *button_destroy(size_t *btn_adr)
{
    button_t *btn = (button_t *)*btn_adr;

    for (int i = 0; i < btn->infos->nb_states; i++)
        sfRectangleShape_destroy(btn->rect[i]);
    if (btn->infos->update_type & GUI_COLORED)
        free(btn->infos->fill_colors);
    if (btn->infos->update_type & GUI_OUTCOLORED)
        free(btn->infos->out_colors);
    if (btn->infos->update_type & (GUI_TEXTURED | GUI_TEXTURED_RECT))
        free(btn->infos->textures);
    if (btn->infos->update_type & GUI_TEXTURED_RECT)
        free(btn->infos->text_rects);
    free(btn->infos);
    free(btn->rect);
    free(btn);
    *btn_adr = 0;
    return NULL;
}