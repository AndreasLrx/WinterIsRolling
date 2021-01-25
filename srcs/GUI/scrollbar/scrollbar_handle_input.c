/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GUI - scrollbar
*/

#include <stdio.h>
#include "GUI/gui_head.h"

static float get_pos(struct scrollbar_infos_t *infos, int pos)
{
    float min;
    float max;
    float btn_size = ((infos->vertical) ? infos->cursor_size.y : \
    infos->cursor_size.x);
    float len = (infos->vertical) ? infos->bar_size.y : infos->bar_size.x;
    float start = (infos->vertical) ? infos->pos.y : infos->pos.x;

    len -= btn_size;
    min = start + infos->min_max_cursor_pos.x * len;
    max = start + infos->min_max_cursor_pos.y * len;
    return MAX(MIN(max, pos - btn_size / 2.f), min);
}

static void update_cursor_pos(scrollbar_t *bar, sfEvent event)
{
    sfVector2f mouse_pos = (sfVector2f){event.mouseMove.x, event.mouseMove.y};
    sfVector2f new_pos = bar->cursor->infos->pos;

    if (bar->infos->vertical) {
        new_pos.y = get_pos(bar->infos, mouse_pos.y);
        bar->value = ((new_pos.y - bar->infos->pos.y) / \
        (bar->infos->bar_size.y - bar->infos->cursor_size.y)) * \
        bar->infos->min_len.y + bar->infos->min_len.x;
    } else {
        new_pos.x = get_pos(bar->infos, mouse_pos.x);
        bar->value = ((new_pos.x - bar->infos->pos.x) / \
        (bar->infos->bar_size.x - bar->infos->cursor_size.x)) * \
        bar->infos->min_len.y + bar->infos->min_len.x;
    }
    bar->last_pos = mouse_pos;
    bar->cursor->infos->pos = new_pos;
    for (int i = 0; i < bar->infos->nb_states; i++)
        sfRectangleShape_setPosition(bar->cursor->rect[i], new_pos);
    scrollbar_update_fill(bar);
}

struct gui_output *scrollbar_handle_input(size_t bar_adr, size_t event_)
{
    scrollbar_t *bar = (scrollbar_t *)bar_adr;
    sfEvent *evt = (sfEvent *)event_;
    int state = *bar->state;

    button_handle_input((size_t)bar->cursor, event_);
    if (evt->type == sfEvtMouseButtonPressed && \
        evt->mouseButton.button == sfMouseLeft && \
        state != *bar->state)
        bar->last_pos = (sfVector2f){evt->mouseButton.x, evt->mouseButton.y};
    if (evt->type == sfEvtMouseMoved && is_btn_clicked(bar->cursor)){
        update_cursor_pos(bar, *evt);
    }
    if (evt->type == sfEvtMouseButtonReleased && \
    state != *bar->state){
        return make_gui_output(bar->gui_item, (size_t)bar->value);
    }
    return NULL;
}