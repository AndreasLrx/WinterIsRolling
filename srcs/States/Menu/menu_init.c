/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** menu init
*/

#include "States/Menu/menu_state.h"

int menu_init(state_t *state)
{
    menu_init_drawables(state);
    menu_init_texts(state);
    return 0;
}