/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** handle level_select inputs
*/

#include "States/LevelSelect/level_select_state.h"

int game_create(game_data_t *data, state_t *state, size_t datas);

static int handle_grid_inputs(game_data_t *data, \
level_grid_t *grid, sfEvent *event)
{
    for (int i = 0; i < grid->nb_availables; i++){
        if (grid->buttons[i]->handle_inputs(\
        grid->buttons[i]->item, (size_t)event) != NULL) {
            add_state(data, &game_create, 1, i);
            return 1;
        }
    }
    return 0;
}

static void handle_guis_outputs(game_data_t *data, gui_manager_t *manager)
{
    struct gui_output **outputs = manager->outputs;
    size_t nb_outputs = my_vector_get_size((size_t *)outputs);

    for (size_t i = 0; i < nb_outputs; i++){
        if (outputs[i]->tag == LS_QUIT_BTN && outputs[i]->data == 1)
            end_state(data, LEVEL_SELECT_STATE);
    }
}

static int handle_key(sfEvent event, state_t *state)
{
    switch (event.key.code) {
    case sfKeyEscape:
        play_sound(state->game_data->audio, "mouse_click");
        end_state(state->game_data, LEVEL_SELECT_STATE);
        return 1;
    default:
        return 0;
    }
}

int level_select_handle_input(state_t *state)
{
    game_data_t *data = state->game_data;
    sfEvent event;

    while (sfRenderWindow_pollEvent(data->window, &event)){
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(data->window);
        if (event.type == sfEvtKeyReleased && handle_key(event, state))
            return 1;
        guis_handle_input(state->gui, (size_t)&event);
        if (handle_grid_inputs(state->game_data, \
            (level_grid_t *)state->state_datas, &event))
            return 1;
    }
    if (state->gui->outputs != NULL)
        handle_guis_outputs(data, state->gui);
    return 1;
}