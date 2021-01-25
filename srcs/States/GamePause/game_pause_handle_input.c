/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** handle game_pause inputs
*/

#include "States/Pause/game_pause_state.h"

int settings_create(game_data_t *data, state_t *state, size_t datas);

static void restart_game(game_data_t *data)
{
    state_t *game_state;

    end_state(data, GAME_PAUSE_STATE);
    game_state = (state_t *)my_vector_top((size_t *)data->states);
    game_struct_restart((game_t *)game_state->state_datas);
}

static void handle_guis_outputs(game_data_t *data, \
gui_manager_t *manager, state_t *state)
{
    struct gui_output **outputs = manager->outputs;
    size_t nb_outputs = my_vector_get_size((size_t *)outputs);

    for (size_t i = 0; i < nb_outputs; i++){
        if (outputs[i]->tag == GP_SETTINGS_BUTTON) {
            add_state(data, &settings_create, 0, 0);
        }
        if (outputs[i]->tag == GP_RESTART_BUTTON)
            restart_game(data);
        if (outputs[i]->tag == PLAY_BUTTON) {
            end_state(data, GAME_PAUSE_STATE);
            return;
        }
        if (outputs[i]->tag == GP_QUIT_BUTTON) {
            end_state(data, GAME_PAUSE_STATE);
            end_state(data, GAME_PAUSE_STATE);
            return;
        }
    }
}

static int handle_key(sfEvent event, state_t *state)
{
    switch (event.key.code) {
    case sfKeyEscape:
        end_state(state->game_data, GAME_PAUSE_STATE);
        return 1;
    case sfKeyR:
        restart_game(state->game_data);
        return 1;
    case sfKeyH:
        play_sound(state->game_data->audio, "mouse_click");
        end_state(state->game_data, GAME_PAUSE_STATE);
        end_state(state->game_data, GAME_PAUSE_STATE);
        return 1;
    case sfKeyP:
        play_sound(state->game_data->audio, "mouse_click");
        end_state(state->game_data, GAME_PAUSE_STATE);
        return 1;
    case sfKeyS:
        add_state(state->game_data, &settings_create, 0, 0);
        return 1;
    default:
        return 0;
    }
}

int game_pause_handle_input(state_t *state)
{
    game_data_t *data = state->game_data;
    sfEvent event;

    while (sfRenderWindow_pollEvent(data->window, &event)){
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(data->window);
            return 1;
        }
        if (event.type == sfEvtKeyReleased && handle_key(event, state))
            return 1;
        guis_handle_input(state->gui, (size_t)&event);
    }
    if (state->gui->outputs != NULL)
        handle_guis_outputs(data, state->gui, state);
    return 1;
}