/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** update Pause
*/

#include "States/LevelEnd/level_end_state.h"

int level_end_update(state_t *state, float dt)
{
    guis_update(state->gui, dt);
    my_map_clear(state->gui->data_map);
    return 0;
}