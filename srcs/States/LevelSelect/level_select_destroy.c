/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** destroy level_select
*/

#include "States/LevelSelect/level_select_state.h"

static void destroy_grid(level_grid_t *grid)
{
    for (int i = 0; i < grid->nb_buttons; i++) {
        grid->buttons[i]->destroy((size_t *)&grid->buttons[i]->item);
    }
    free(grid->buttons);
    free(grid);
}

int level_select_destroy(state_t *state, int from)
{
    size_t nb_layers = my_vector_get_size((size_t *)state->draw_layers);

    if (from != LEVEL_SELECT_STATE)
        stop_musics(state->game_data->audio);
    for (size_t i = 0; i < nb_layers; i++){
        destroy_draw_layer(state->draw_layers[i]);
        my_map_free(&state->draw_layers[i]);
    }
    destroy_grid((level_grid_t *)state->state_datas);
    my_vector_free((size_t **)&state->draw_layers);
    gui_manager_destroy(state->gui);
    free(state);
    return 0;
}