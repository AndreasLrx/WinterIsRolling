/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** update Settings
*/

#include "States/Settings/settings_state.h"

int settings_update(state_t *state, float dt)
{
    guis_update(state->gui, dt);
    my_map_clear(state->gui->data_map);
    return 0;
}