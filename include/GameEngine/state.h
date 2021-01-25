/*
** EPITECH PROJECT, 2020
** Game Engine
** File description:
** Game State
*/

#ifndef GE_STATE_H
#define GE_STATE_H

enum STATE_ID{NONE, MENU_STATE, SETTINGS_STATE, GAME_STATE, \
GAME_PAUSE_STATE, LEVEL_SELECT_STATE, LEVEL_END_STATE, STATS_STATE};

struct game_data_t;
struct drawable_list_t;
struct gui_manager_t;

typedef struct state_t{
    int (*init)(struct state_t *);
    int (*pause)(struct state_t *, int);
    int (*resume)(struct state_t *, int);
    int (*handle_input)(struct state_t *);
    int (*update)(struct state_t *, float);
    int (*draw)(struct state_t *, float);
    int (*destroy)(struct state_t *, int);
    struct game_data_t *game_data;
    struct my_map_t **draw_layers;
    struct gui_manager_t *gui;
    int state_id;
    size_t *state_datas;
} state_t;

void end_state(game_data_t *data, int from);
void add_state(game_data_t *data, int (*state_setfcts)(game_data_t *, \
state_t *, size_t), int replace, size_t datas);

#endif