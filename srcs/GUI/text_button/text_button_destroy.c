/*
** EPITECH PROJECT, 2020
** My Runner
** File description:
** GUI - text_button destroy
*/

#include "GUI/gui_head.h"

struct gui_output *text_button_destroy(size_t *btn_adr)
{
    text_button_t *btn = (text_button_t *)*btn_adr;

    button_destroy((size_t *)&btn->btn);
    if (btn->infos->text_update_type & GUI_COLORED)
        free(btn->infos->fill_colors);
    if (btn->infos->text_update_type & GUI_OUTCOLORED)
        free(btn->infos->out_colors);
    sfText_destroy(btn->text);
    free(btn->infos);
    free(btn);
    *btn_adr = 0;
    return NULL;
}