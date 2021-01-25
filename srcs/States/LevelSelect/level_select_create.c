/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Create level_select state
*/

#include "States/LevelSelect/level_select_state.h"

int level_select_create(game_data_t *data, state_t *state, size_t datas)
{
    state->init = &level_select_init;
    state->resume = &level_select_resume;
    state->handle_input = &level_select_handle_input;
    state->update = &level_select_update;
    state->draw = &level_select_draw;
    state->pause = &level_select_pause;
    state->destroy = &level_select_destroy;
    state->state_id = LEVEL_SELECT_STATE;
    state->game_data = data;
    state->state_datas = NULL;
    state->gui = init_gui_manager();
    state->draw_layers = (my_map_t **)my_vector_init(sizeof(my_map_t *), \
    LEVEL_SELECT_DRAW_LAYERS);
    for (int i = 0; i < LEVEL_SELECT_DRAW_LAYERS; i++)
        my_vector_push((size_t **)&state->draw_layers, \
        (size_t)my_map(unsigned char, draw_elmt_t *, my_map_charcmp, 0, 0));
    return LEVEL_SELECT_STATE;
}