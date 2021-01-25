/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** settings - init sound/music scrollbar
*/

#include "States/Settings/settings_state.h"

struct scrollbar_infos_t *init_scrolls_infos(game_data_t *data, sfVector2f pos)
{
    struct scrollbar_infos_t *infos = malloc(sizeof(struct scrollbar_infos_t));

    infos->pos = pos;
    infos->bar_size = (sfVector2f){500 * data->settings->scale, \
        15 * data->settings->scale};
    infos->cursor_size = (sfVector2f){60 * data->settings->scale, \
        60 * data->settings->scale};
    infos->min_len = (sfVector2f){0, 100};
    infos->min_max_cursor_pos = (sfVector2f){0, 1};
    infos->update_type = GUI_TEXTURED;
    infos->fill_colors = malloc(sizeof(sfColor) * 2);
    infos->fill_colors[0] = sfWhite;
    infos->fill_colors[1] = sfCyan;
    infos->textures = malloc(sizeof(sfTexture *) * 2);
    infos->textures[0] = get_texture(data->assets, "scroll_cursor_normal");
    infos->textures[1] = get_texture(data->assets, "scroll_cursor_clicked");
    infos->vertical = 0;
    infos->nb_states = 2;
    infos->fill = 1;
    return infos;
}

void settings_update_scrolls_value(state_t *state)
{
    scrollbar_set_value(GET_ITEM(state->gui, scrollbar_t, \
    MUSIC_SCROLLBAR), state->game_data->settings->music_volume);
    scrollbar_set_value(GET_ITEM(state->gui, scrollbar_t, \
    SOUND_SCROLLBAR), state->game_data->settings->sound_volume);
}

void settings_init_scrolls(state_t *state)
{
    gui_manager_add_item(state->gui, &scrollbar_init, \
    (size_t)init_scrolls_infos(state->game_data, \
    (sfVector2f){891 * SCL(state), 400 * SCL(state)}), MUSIC_SCROLLBAR);
    gui_manager_add_item(state->gui, &scrollbar_init, \
    (size_t)init_scrolls_infos(state->game_data, \
    (sfVector2f){895 * SCL(state), 500 * SCL(state)}), SOUND_SCROLLBAR);
    settings_update_scrolls_value(state);
}