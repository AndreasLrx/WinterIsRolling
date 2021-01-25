/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Menu - init clickable texts
*/

#include "States/Menu/menu_state.h"


struct click_text_infos_t *init_text_infos(state_t *state, \
wchar_t const *str, sfVector2f pos)
{
    struct click_text_infos_t *infos = \
    malloc(sizeof(struct click_text_infos_t));

    infos->font = get_font(state->game_data->assets, "roboto_font");
    infos->text = str;
    infos->pos = pos;
    infos->character_size = 70 * SCL(state);
    infos->update_type = (GUI_COLORED | GUI_OUTCOLORED);
    infos->fill_colors = malloc(sizeof(sfColor) * 3);
    infos->fill_colors[0] = sfWhite;
    infos->fill_colors[1] = sfColor_fromRGB(190, 190, 190);
    infos->fill_colors[2] = sfColor_fromRGB(90, 90, 90);
    infos->out_colors = malloc(sizeof(sfColor) * 3);
    infos->out_colors[0] = sfBlack;
    infos->out_colors[1] = sfBlack;
    infos->out_colors[2] = sfBlack;
    infos->out_thickness = 2 * SCL(state);
    infos->nb_states = 3;
    infos->audio = state->game_data->audio;
    infos->click_sound = "mouse_click";
    return infos;
}

void menu_init_texts(state_t *state)
{
    gui_manager_add_item(state->gui, &click_text_init, \
    (size_t)init_text_infos(state, L"PLAY", \
    (sfVector2f){880 * SCL(state), 300 * SCL(state)}), CLICK_TEXT_PLAY_TAG);
    gui_manager_add_item(state->gui, &click_text_init, \
    (size_t)init_text_infos(state, L"SETTINGS", \
    (sfVector2f){804 * SCL(state), 480 * SCL(state)}), CLICK_TEXT_SETTINGS_TAG);
    gui_manager_add_item(state->gui, &click_text_init, \
    (size_t)init_text_infos(state, L"STATISTICS", \
    (sfVector2f){777 * SCL(state), 660 * SCL(state)}), CLICK_TEXT_STATS_TAG);
    gui_manager_add_item(state->gui, &click_text_init, \
    (size_t)init_text_infos(state, L"QUIT", \
    (sfVector2f){885 * SCL(state), 840 * SCL(state)}), CLICK_TEXT_QUIT_TAG);
}