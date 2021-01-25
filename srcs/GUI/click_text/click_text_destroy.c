/*
** EPITECH PROJECT, 2020
** My Runner
** File description:
** GUI - click text destroy
*/

#include "GUI/gui_head.h"

struct gui_output *click_text_destroy(size_t *click_text_adr)
{
    click_text_t *text = (click_text_t *)*click_text_adr;

    if (text->infos->update_type & GUI_COLORED)
        free(text->infos->fill_colors);
    if (text->infos->update_type & GUI_OUTCOLORED)
        free(text->infos->out_colors);
    free(text->infos);
    sfText_destroy(text->texte);
    free(text);
    *click_text_adr = 0;
    return NULL;
}