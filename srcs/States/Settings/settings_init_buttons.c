/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Settings - init buttons
*/

#include "States/Settings/settings_state.h"

void settings_init_buttons(state_t *state)
{
    gui_manager_add_item(state->gui, &button_init, \
    (size_t)init_iced_btn(state, RETURN, \
    (sfVector2f){50 * SCL(state), 50 * SCL(state)}), QUIT_BUTTON);
    gui_manager_add_item(state->gui, &button_init, \
    (size_t)init_iced_btn(state, VALID, \
    (sfVector2f){1570 * SCL(state), 50 * SCL(state)}), SAVE_BUTTON);
    gui_manager_add_item(state->gui, &button_init, \
    (size_t)init_iced_btn(state, RESET, \
    (sfVector2f){1740 * SCL(state), 50 * SCL(state)}), RESET_BUTTON);
}