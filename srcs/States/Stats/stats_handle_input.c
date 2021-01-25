/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** handle menu inputs
*/

#include "States/Stats/stats_state.h"
#include "My/my_convert.h"

static void change_level(state_t *state)
{
    textfield_t *field = GET_ITEM(state->gui, textfield_t, STATS_LEVEL_FIELD);
    int level_id = my_get_number_pass(sfText_getString(field->text), NULL) - 1;
    wchar_t *wstr;

    if (level_id < 0) {
        level_id = 0;
        textfield_setstr(field, (sfUint32 *)L"1");
    }
    if (level_id >= NB_MAP) {
        level_id = NB_MAP - 1;
        wstr = my_itowstr(NB_MAP);
        textfield_setstr(field, (sfUint32 *)wstr);
        free(wstr);
    }
    update_level_texts((global_stats_t *)state->game_data->datas, \
    state, level_id);
}

static void handle_guis_outputs(game_data_t *data, \
gui_manager_t *manager, state_t *state)
{
    struct gui_output **outputs = manager->outputs;
    size_t nb_outputs = my_vector_get_size((size_t *)outputs);

    for (size_t i = 0; i < nb_outputs; i++){
        if (outputs[i]->tag == STATS_QUIT_BTN) {
            end_state(data, STATS_STATE);
            return;
        }
        if (outputs[i]->tag == STATS_LEVEL_FIELD) {
            change_level(state);
        }
    }
}

static int handle_key(sfEvent event, state_t *state)
{
    textfield_t *field = GET_ITEM(state->gui, textfield_t, STATS_LEVEL_FIELD);

    switch (event.key.code) {
    case sfKeyEscape:
        play_sound(state->game_data->audio, "mouse_click");
        end_state(state->game_data, STATS_STATE);
        return 1;
    case sfKeyL:
        play_sound(state->game_data->audio, "mouse_click");
        field->gui_item->selected = 1;
        return 0;
    default:
        return 0;
    }
}

int stats_handle_input(state_t *state)
{
    game_data_t *data = state->game_data;
    sfEvent event;

    while (sfRenderWindow_pollEvent(data->window, &event)){
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(data->window);
        if (event.type == sfEvtKeyReleased && handle_key(event, state))
            return 1;
        guis_handle_input(state->gui, (size_t)&event);
    }
    if (state->gui->outputs != NULL)
        handle_guis_outputs(data, state->gui, state);
    return 1;
}