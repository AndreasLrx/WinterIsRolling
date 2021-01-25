/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** game init
*/

#include "States/Game/game_state.h"

int game_init(state_t *state)
{
    game_init_rects(state);
    game_init_texts(state);
    game_init_progress_bar(state);
    gui_manager_add_item(state->gui, &button_init, \
    (size_t)init_iced_btn(state, PAUSE, \
    (sfVector2f){1740 * SCL(state), 50 * SCL(state)}), PAUSE_BUTTON);
    return 0;
}