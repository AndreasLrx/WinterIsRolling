/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** game_pause state
*/

#ifndef GAME_PAUSE_STATE_H
#define GAME_PAUSE_STATE_H

#include "GameEngine/game_head.h"
#include "Game/game_struct.h"
#include "GUI/gui_head.h"
#include "functions.h"
#include "States/Pause/game_pause_cst.h"
#include "Drawables/background.h"

int game_pause_create(game_data_t *data, state_t *state, size_t datas);
int game_pause_init(state_t *state);
int game_pause_resume(state_t *state, int last_state);
int game_pause_handle_input(state_t *state);
int game_pause_update(state_t *state, float dt);
int game_pause_draw(state_t *state, float dt);
int game_pause_pause(state_t *state, int new_state);
int game_pause_destroy(state_t *state, int from);

void game_pause_init_texts(state_t *state);

#endif /* !GAME_PAUSE_STATE_H */