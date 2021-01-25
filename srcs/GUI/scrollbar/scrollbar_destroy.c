/*
** EPITECH PROJECT, 2020
** My Runner
** File description:
** GUI - scrollbar destroy
*/

#include "GUI/gui_head.h"

static void free_textures_colors(scrollbar_t *bar)
{
    if (bar->infos->update_type & GUI_COLORED)
        free(bar->infos->fill_colors);
    if (bar->infos->update_type & GUI_OUTCOLORED)
        free(bar->infos->out_colors);
    if (bar->infos->update_type & (GUI_TEXTURED | GUI_TEXTURED_RECT))
        free(bar->infos->textures);
    if (bar->infos->update_type & GUI_TEXTURED_RECT)
        free(bar->infos->text_rects);
}

struct gui_output *scrollbar_destroy(size_t *bar_adr)
{
    scrollbar_t *bar = (scrollbar_t *)*bar_adr;

    sfRectangleShape_destroy(bar->bar_rects[0]);
    if (bar->infos->fill)
        sfRectangleShape_destroy(bar->bar_rects[1]);
    for (int i = 0; i < bar->infos->nb_states; i++)
        sfRectangleShape_destroy(bar->cursor->rect[i]);
    free_textures_colors(bar);
    free(bar->cursor->infos);
    free(bar->cursor->rect);
    free(bar->cursor);
    free(bar->bar_rects);
    free(bar->infos);
    free(bar);
    *bar_adr = 0;
    return NULL;
}