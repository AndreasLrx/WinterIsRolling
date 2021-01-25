/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Create level_end state
*/

#include "States/LevelEnd/level_end_state.h"

int level_end_create(game_data_t *data, state_t *state, size_t datas)
{
    state->init = &level_end_init;
    state->resume = &level_end_resume;
    state->handle_input = &level_end_handle_input;
    state->update = &level_end_update;
    state->draw = &level_end_draw;
    state->pause = &level_end_pause;
    state->destroy = &level_end_destroy;
    state->state_id = GAME_PAUSE_STATE;
    state->game_data = data;
    state->state_datas = malloc(sizeof(size_t) * 2);
    state->state_datas[1] = datas;
    state->gui = init_gui_manager();
    state->draw_layers = (my_map_t **)my_vector_init(sizeof(my_map_t *), \
    LEVEL_END_DRAW_LAYERS);
    for (int i = 0; i < LEVEL_END_DRAW_LAYERS; i++)
        my_vector_push((size_t **)&state->draw_layers, \
        (size_t)my_map(unsigned char, draw_elmt_t *, my_map_charcmp, 0, 0));
    return GAME_PAUSE_STATE;
}