/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Create menu state
*/

#include "States/Stats/stats_state.h"

int stats_create(game_data_t *data, state_t *state, size_t datas)
{
    state->init = &stats_init;
    state->resume = &stats_resume;
    state->handle_input = &stats_handle_input;
    state->update = &stats_update;
    state->draw = &stats_draw;
    state->pause = &stats_pause;
    state->destroy = &stats_destroy;
    state->state_id = STATS_STATE;
    state->game_data = data;
    state->state_datas = NULL;
    state->gui = init_gui_manager();
    state->draw_layers = (my_map_t **)my_vector_init(sizeof(my_map_t *), \
    STATS_DRAW_LAYERS);
    for (int i = 0; i < STATS_DRAW_LAYERS; i++)
        my_vector_push((size_t **)&state->draw_layers, \
        (size_t)my_map(unsigned char, draw_elmt_t *, my_map_charcmp, 0, 0));
    return MENU_STATE;
}