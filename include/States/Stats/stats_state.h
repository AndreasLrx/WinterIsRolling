/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** menu state
*/

#ifndef MENU_STATE_H
#define MENU_STATE_H

#include "GameEngine/game_head.h"
#include "GUI/gui_head.h"
#include "functions.h"
#include "States/Stats/stats_cst.h"
#include "Drawables/background.h"
#include "Stats/stats.h"

int stats_create(game_data_t *data, state_t *state, size_t datas);
int stats_init(state_t *state);
int stats_resume(state_t *state, int last_state);
int stats_handle_input(state_t *state);
int stats_update(state_t *state, float dt);
int stats_draw(state_t *state, float dt);
int stats_pause(state_t *state, int new_state);
int stats_destroy(state_t *state, int from);

void stats_init_texts(state_t *state);
void stats_init_level_field(state_t *state);
void update_level_texts(global_stats_t *stats, state_t *state, int level_id);
wchar_t *create_wstr(wchar_t *prefix, wchar_t *suffix, int value);

#endif /* !MENU_STATE_H */