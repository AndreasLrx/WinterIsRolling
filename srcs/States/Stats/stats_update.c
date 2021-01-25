/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** update Menu
*/

#include "States/Stats/stats_state.h"

int stats_update(state_t *state, float dt)
{
    guis_update(state->gui, dt);
    my_map_clear(state->gui->data_map);
    return 0;
}