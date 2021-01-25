/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** handle settings inputs
*/

#include "States/Settings/settings_state.h"

static void reset_settings(state_t *state, game_data_t *data)
{
    ((game_settings_t *)(state->state_datas))->wind_size = \
    (sfVector2u){1280, 720};
    data->settings->sound_volume = 100;
    data->settings->music_volume = 100;
    data->settings->limit_framerate = 60;
    settings_update_fields(state);
    settings_update_scrolls_value(state);
    settings_save_changes(state);
}

static void handle_guis_outputs(state_t *state, \
game_data_t *data, gui_manager_t *manager)
{
    struct gui_output **outputs = manager->outputs;
    size_t nb_outputs = my_vector_get_size((size_t *)outputs);

    for (size_t i = 0; i < nb_outputs; i++){
        if (outputs[i]->tag == SAVE_BUTTON)
            settings_save_changes(state);
        if (outputs[i]->tag == RESET_BUTTON)
            reset_settings(state, data);
        if (outputs[i]->tag == QUIT_BUTTON) {
            end_state(state->game_data, SETTINGS_STATE);
            return;
        }
    }
}

static int handle_key(sfEvent event, state_t *state)
{
    switch (event.key.code) {
    case sfKeyEscape:
        play_sound(state->game_data->audio, "mouse_click");
        end_state(state->game_data, SETTINGS_STATE);
        return 1;
    case sfKeyV:
        play_sound(state->game_data->audio, "mouse_click");
        settings_save_changes(state);
        return 1;
    case sfKeyR:
        play_sound(state->game_data->audio, "mouse_click");
        reset_settings(state, state->game_data);
        return 1;
    default:
        return 0;
    }
}

int settings_handle_input(state_t *state)
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
        handle_guis_outputs(state, data, state->gui);
    return 1;
}