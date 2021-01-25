/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Game - resume
*/

#include "States/Game/game_state.h"

int game_resume(state_t *state, int last_state)
{
    if (last_state == NONE)
        play_music(state->game_data->audio, "game_music", 1);
    return 0;
}