/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GUI - button
*/

#include "GUI/gui_head.h"

static void play_click(button_t *btn)
{
    if (btn->infos->audio == NULL)
        return;
    play_sound(btn->infos->audio, btn->infos->click_sound);
}

static sfVector2f get_mouse_pos(sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed || \
        event.type == sfEvtMouseButtonReleased)
        return (sfVector2f){event.mouseButton.x, event.mouseButton.y};
    if (event.type == sfEvtMouseMoved)
        return (sfVector2f){event.mouseMove.x, event.mouseMove.y};
    return (sfVector2f){0, 0};
}

static void update_btn_state(button_t *btn, sfEvent event)
{
    sfVector2f mouse_pos = get_mouse_pos(event);
    int in_btn;
    int state = btn->state;

    in_btn = is_in_bounds(mouse_pos, btn->infos->pos, btn->infos->size);
    if (!is_btn_clicked(btn)){
        if (!in_btn)
            state = GUI_NORMAL;
        else
            state = GUI_HOVER;
    }
    if (in_btn && event.type == sfEvtMouseButtonPressed && \
        event.mouseButton.button == sfMouseLeft)
        state = GUI_CLICKED;
    if (state != btn->state) {
        btn->state = state;
        if (state == GUI_CLICKED)
            play_click(btn);
    }
}

struct gui_output *button_handle_input(size_t btn_adr, size_t event_)
{
    button_t *btn = (button_t *)btn_adr;
    sfEvent *event = (sfEvent *)event_;

    if (event->type == sfEvtMouseMoved || \
    event->type == sfEvtMouseButtonPressed){
        update_btn_state(btn, *event);
    }
    if (event->type == sfEvtMouseButtonReleased && \
    event->mouseButton.button == sfMouseLeft){
        if (is_btn_clicked(btn)){
            btn->state--;
            update_btn_state(btn, *event);
            return make_gui_output(btn->gui_item, 1);
        }
    }
    return NULL;
}