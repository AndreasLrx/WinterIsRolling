/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** update LevelSelect
*/

#include "States/LevelSelect/level_select_state.h"

int level_select_update(state_t *state, float dt)
{
    guis_update(state->gui, dt);
    my_map_clear(state->gui->data_map);
    return 0;
}