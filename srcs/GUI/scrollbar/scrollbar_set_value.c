/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Scrollbar - set value
*/

#include "GUI/gui_head.h"

void scrollbar_update_fill(scrollbar_t *bar)
{
    sfVector2f size = bar->infos->bar_size;

    if (!bar->infos->fill)
        return;
    if (bar->infos->vertical) {
        size.y = bar->cursor->infos->pos.y - \
        bar->infos->pos.y + bar->infos->cursor_size.y / 2.f;
    } else {
        size.x = bar->cursor->infos->pos.x - \
        bar->infos->pos.x + bar->infos->cursor_size.x / 2.f;
    }
    sfRectangleShape_setSize(bar->bar_rects[1], size);
}

void scrollbar_set_value(scrollbar_t *bar, float value)
{
    float max = bar->infos->min_len.x + bar->infos->min_len.y;
    float new_value = BTWN(value, bar->infos->min_len.x, max);
    float factor = (new_value - bar->infos->min_len.x) / bar->infos->min_len.y;
    sfVector2f new_pos = bar->cursor->infos->pos;

    if (bar->infos->vertical) {
        new_pos.y = (bar->infos->bar_size.y - \
        bar->infos->cursor_size.y) * factor + bar->infos->pos.y;
    } else {
        new_pos.x = (bar->infos->bar_size.x - \
        bar->infos->cursor_size.x) * factor + bar->infos->pos.x;
    }
    bar->value = new_value;
    bar->cursor->infos->pos = new_pos;
    for (int i = 0; i < bar->infos->nb_states; i++)
        sfRectangleShape_setPosition(bar->cursor->rect[i], new_pos);
    scrollbar_update_fill(bar);
}