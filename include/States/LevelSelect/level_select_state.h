/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** level_select state
*/

#ifndef LEVEL_SELECT_STATE_H
#define LEVEL_SELECT_STATE_H

#include "GameEngine/game_head.h"
#include "GUI/gui_head.h"
#include "functions.h"
#include "States/LevelSelect/level_select_cst.h"
#include "Drawables/background.h"

typedef struct level_grid_t {
    sfVector2f pos;
    int nb_buttons;
    int nb_columns;
    int spacing;
    int margin;
    int nb_availables;
    gui_item_t **buttons;
} level_grid_t;

int level_select_create(game_data_t *data, state_t *state, size_t datas);
int level_select_init(state_t *state);
int level_select_resume(state_t *state, int last_state);
int level_select_handle_input(state_t *state);
int level_select_update(state_t *state, float dt);
int level_select_draw(state_t *state, float dt);
int level_select_pause(state_t *state, int new_state);
int level_select_destroy(state_t *state, int from);

void level_select_init_title(state_t *state);

#endif /* !LEVEL_SELECT_STATE_H */