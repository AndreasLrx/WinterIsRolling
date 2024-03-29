/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** destroy game_pause
*/

#include "States/Pause/game_pause_state.h"

int game_pause_destroy(state_t *state, int from)
{
    size_t nb_layers = my_vector_get_size((size_t *)state->draw_layers);

    for (size_t i = 0; i < nb_layers; i++){
        destroy_draw_layer(state->draw_layers[i]);
        my_map_free(&state->draw_layers[i]);
    }
    my_vector_free((size_t **)&state->draw_layers);
    sfRenderTexture_destroy((sfRenderTexture *)state->state_datas);
    gui_manager_destroy(state->gui);
    free(state);
    return 0;
}