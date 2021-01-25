/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** settings state
*/

#ifndef SETTINGS_STATE_H
#define SETTINGS_STATE_H

#include "GameEngine/game_head.h"
#include "GUI/gui_head.h"
#include "functions.h"
#include "States/Settings/settings_cst.h"
#include "Drawables/drawable_create.h"

int settings_create(game_data_t *data, state_t *state, size_t datas);
int settings_init(state_t *state);
int settings_resume(state_t *state, int last_state);
int settings_handle_input(state_t *state);
int settings_update(state_t *state, float dt);
int settings_draw(state_t *state, float dt);
int settings_pause(state_t *state, int new_state);
int settings_destroy(state_t *state, int from);

void settings_init_scrolls(state_t *state);
void settings_init_texts(state_t *state);
void settings_init_fields(state_t *state);
void settings_init_buttons(state_t *state);

void settings_save_changes(state_t *state);
void settings_update_fields(state_t *state);
void settings_update_scrolls_value(state_t *state);

#endif /* !SETTINGS_STATE_H */