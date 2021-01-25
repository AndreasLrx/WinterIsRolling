/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GUI - text_button
*/

#include "GUI/gui_head.h"

static void update_btn_text(text_button_t *btn, int state)
{
    if (btn->infos->text_update_type & GUI_COLORED)
        sfText_setFillColor(btn->text, \
        btn->infos->fill_colors[state]);
    if (btn->infos->text_update_type & GUI_OUTCOLORED){
        sfText_setOutlineColor(btn->text, \
        btn->infos->out_colors[state]);
    }
}

struct gui_output *text_button_handle_input(size_t btn_adr, size_t event_)
{
    text_button_t *btn = (text_button_t *)btn_adr;
    sfEvent *event = (sfEvent *)event_;
    int state_bef = *btn->state;

    button_handle_input((size_t)btn->btn, event_);
    if (*btn->state != state_bef)
        update_btn_text(btn, *btn->state);
    if (event->type == sfEvtMouseButtonReleased && \
    event->mouseButton.button == sfMouseLeft){
        if (*btn->state != state_bef){
            return make_gui_output(btn->gui_item, 1);
        }
    }
    return NULL;
}