/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** update Game
*/

#include "States/Game/game_state.h"

int game_update(state_t *state, float dt)
{
    game_struct_update((game_t *)state->state_datas, dt);
    game_update_texts(state);
    game_progress_bar_update(state);
    guis_update(state->gui, dt);
    my_map_clear(state->gui->data_map);
    return 0;
}