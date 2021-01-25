/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** update Pause
*/

#include "States/Pause/game_pause_state.h"

int game_pause_update(state_t *state, float dt)
{
    guis_update(state->gui, dt);
    my_map_clear(state->gui->data_map);
    return 0;
}