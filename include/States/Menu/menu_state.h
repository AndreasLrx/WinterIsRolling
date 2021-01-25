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
#include "States/Menu/menu_cst.h"
#include "Drawables/background.h"

int menu_create(game_data_t *data, state_t *state, size_t datas);
int menu_init(state_t *state);
int menu_resume(state_t *state, int last_state);
int menu_handle_input(state_t *state);
int menu_update(state_t *state, float dt);
int menu_draw(state_t *state, float dt);
int menu_pause(state_t *state, int new_state);
int menu_destroy(state_t *state, int from);

void menu_init_texts(state_t *state);
void menu_init_drawables(state_t *state);

#endif /* !MENU_STATE_H */