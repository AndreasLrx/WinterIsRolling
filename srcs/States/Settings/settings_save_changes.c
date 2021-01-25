/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** settings state - save changes
*/

#include "States/Settings/settings_state.h"
#include "My/my_convert.h"

void settings_save_changes(state_t *state)
{
    game_settings_t *settings = (game_settings_t *)state->state_datas;

    settings->limit_framerate = my_get_number_adv(sfText_getString(\
    GET_ITEM(state->gui, textfield_t, FRAMERATE_FIELD)->text), NULL, 0, 1);
    settings->wind_size.x = my_get_number_adv(sfText_getString(\
    GET_ITEM(state->gui, textfield_t, SIZE_FIELD_X)->text), NULL, 0, 1);
    settings->wind_size.y = my_get_number_adv(sfText_getString(\
    GET_ITEM(state->gui, textfield_t, SIZE_FIELD_Y)->text), NULL, 0, 1);
    settings->music_volume = GET_ITEM(state->gui, \
    scrollbar_t, MUSIC_SCROLLBAR)->value;
    settings->sound_volume = GET_ITEM(state->gui, \
    scrollbar_t, SOUND_SCROLLBAR)->value;
    game_settings_save(settings);
    state->game_data->settings->sound_volume = settings->sound_volume;
    state->game_data->settings->music_volume = settings->music_volume;
    state->game_data->settings->limit_framerate = settings->limit_framerate;
    sfRenderWindow_setFramerateLimit(state->game_data->window, \
    settings->limit_framerate);
    settings_update_fields(state);
    audio_manager_update_volumes(state->game_data->audio);
}