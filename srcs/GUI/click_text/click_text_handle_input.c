/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GUI - click text handle input
*/

#include "GUI/gui_head.h"

static void play_click(click_text_t *text)
{
    if (text->infos->audio == NULL)
        return;
    play_sound(text->infos->audio, text->infos->click_sound);
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

static void update_text_colors(click_text_t *text)
{
    if (text->infos->update_type & GUI_COLORED)
        sfText_setFillColor(text->texte, \
        text->infos->fill_colors[text->state - (text->infos->nb_states != 3)]);
    if (text->infos->update_type & GUI_OUTCOLORED)
        sfText_setOutlineColor(text->texte, \
        text->infos->out_colors[text->state - (text->infos->nb_states != 3)]);
}

static void update_text_state(click_text_t *text, sfEvent event)
{
    sfVector2f mouse_pos = get_mouse_pos(event);
    int in_text;
    int state = text->state;

    in_text = is_in_rect(mouse_pos, sfText_getGlobalBounds(text->texte));
    if (!is_text_clicked(text)){
        if (!in_text)
            state = GUI_NORMAL;
        else
            state = GUI_HOVER;
    }
    if (in_text && event.type == sfEvtMouseButtonPressed && \
        event.mouseButton.button == sfMouseLeft)
        state = GUI_CLICKED;
    if (state != text->state){
        text->state = state;
        update_text_colors(text);
        if (state == GUI_CLICKED)
            play_click(text);
    }
}

struct gui_output *click_text_handle_input(size_t text_adr, size_t event_)
{
    click_text_t *text = (click_text_t *)text_adr;
    sfEvent *event = (sfEvent *)event_;

    if (event->type == sfEvtMouseMoved || \
        event->type == sfEvtMouseButtonPressed)
        update_text_state(text, *event);
    if (event->type == sfEvtMouseButtonReleased && \
    event->mouseButton.button == sfMouseLeft){
        if (is_text_clicked(text)){
            text->state--;
            update_text_state(text, *event);
            update_text_colors(text);
            return make_gui_output(text->gui_item, 1);
        }
    }
    return NULL;
}