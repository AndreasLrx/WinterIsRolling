/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Create game_pause state
*/

#include "States/Pause/game_pause_state.h"

int game_pause_create(game_data_t *data, state_t *state, size_t datas)
{
    state->init = &game_pause_init;
    state->resume = &game_pause_resume;
    state->handle_input = &game_pause_handle_input;
    state->update = &game_pause_update;
    state->draw = &game_pause_draw;
    state->pause = &game_pause_pause;
    state->destroy = &game_pause_destroy;
    state->state_id = GAME_PAUSE_STATE;
    state->game_data = data;
    state->state_datas = (size_t *)datas;
    state->gui = init_gui_manager();
    state->draw_layers = (my_map_t **)my_vector_init(sizeof(my_map_t *), \
    GAME_PAUSE_DRAW_LAYERS);
    for (int i = 0; i < GAME_PAUSE_DRAW_LAYERS; i++)
        my_vector_push((size_t **)&state->draw_layers, \
        (size_t)my_map(unsigned char, draw_elmt_t *, my_map_charcmp, 0, 0));
    return GAME_PAUSE_STATE;
}