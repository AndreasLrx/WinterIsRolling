/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** update Menu
*/

#include "States/Menu/menu_state.h"

int menu_update(state_t *state, float dt)
{
    background_update(((draw_elmt_t *)my_map_find(state->draw_layers[0], \
    (size_t)MENU_BACKGROUND_TAG))->draw->bg, 80 * (dt / 1000.f));
    guis_update(state->gui, dt);
    my_map_clear(state->gui->data_map);
    return 0;
}