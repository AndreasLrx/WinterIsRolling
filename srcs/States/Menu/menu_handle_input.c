/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** handle menu inputs
*/

#include "States/Menu/menu_state.h"

int settings_create(game_data_t *data, state_t *state, size_t datas);
int level_select_create(game_data_t *data, state_t *state, size_t datas);
int stats_create(game_data_t *data, state_t *state, size_t datas);

static void handle_guis_outputs(game_data_t *data, gui_manager_t *manager)
{
    struct gui_output **outputs = manager->outputs;
    size_t nb_outputs = my_vector_get_size((size_t *)outputs);

    for (size_t i = 0; i < nb_outputs; i++){
        if (outputs[i]->tag == CLICK_TEXT_PLAY_TAG && outputs[i]->data == 1)
            add_state(data, &level_select_create, 0, 0);
        if (outputs[i]->tag == CLICK_TEXT_SETTINGS_TAG && outputs[i]->data == 1)
            add_state(data, &settings_create, 0, 0);
        if (outputs[i]->tag == CLICK_TEXT_STATS_TAG && outputs[i]->data == 1)
            add_state(data, &stats_create, 0, 0);
        if (outputs[i]->tag == CLICK_TEXT_QUIT_TAG && outputs[i]->data == 1)
            sfRenderWindow_close(data->window);
    }
}

int menu_handle_input(state_t *state)
{
    game_data_t *data = state->game_data;
    sfEvent event;

    while (sfRenderWindow_pollEvent(data->window, &event)){
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(data->window);
        guis_handle_input(state->gui, (size_t)&event);
    }
    if (state->gui->outputs != NULL)
        handle_guis_outputs(data, state->gui);
    return 1;
}