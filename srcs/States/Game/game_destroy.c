/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** destroy game
*/

#include "States/Game/game_state.h"

int game_destroy(state_t *state, int from)
{
    size_t nb_layers = my_vector_get_size((size_t *)state->draw_layers);

    stop_musics(state->game_data->audio);
    for (size_t i = 0; i < nb_layers; i++){
        destroy_draw_layer(state->draw_layers[i]);
        my_map_free(&state->draw_layers[i]);
    }
    game_struct_destroy((game_t **)&state->state_datas);
    my_vector_free((size_t **)&state->draw_layers);
    gui_manager_destroy(state->gui);
    free(state);
    return 0;
}