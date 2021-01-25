/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** level_end state
*/

#ifndef LEVEL_END_STATE_H
#define LEVEL_END_STATE_H

#include "GameEngine/game_head.h"
#include "Game/game_struct.h"
#include "GUI/gui_head.h"
#include "functions.h"
#include "States/LevelEnd/level_end_cst.h"
#include "Drawables/background.h"

int level_end_create(game_data_t *data, state_t *state, size_t datas);
int level_end_init(state_t *state);
int level_end_resume(state_t *state, int last_state);
int level_end_handle_input(state_t *state);
int level_end_update(state_t *state, float dt);
int level_end_draw(state_t *state, float dt);
int level_end_pause(state_t *state, int new_state);
int level_end_destroy(state_t *state, int from);

void level_end_init_texts(state_t *state);

#endif /* !LEVEL_END_STATE_H */