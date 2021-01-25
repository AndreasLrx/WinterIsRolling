/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Menu - resume
*/

#include "States/Menu/menu_state.h"

int menu_resume(state_t *state, int last_state)
{
    if (last_state == NONE || last_state == GAME_STATE)
        play_music(state->game_data->audio, "menu_music", 1);
    return 0;
}