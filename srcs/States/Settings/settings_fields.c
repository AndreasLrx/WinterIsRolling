/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** settings state - init textfields (number input)
*/

#include "States/Settings/settings_state.h"
#include "My/my_convert.h"

static struct textfield_infos_t *settings_init_number_input(state_t *state, \
sfVector2f pos, wchar_t const *str, float width)
{
    struct textfield_infos_t *infos = malloc(sizeof(struct textfield_infos_t));

    infos->font = get_font(state->game_data->assets, "roboto_font");
    infos->pos = pos;
    infos->size = (sfVector2f){width * SCL(state), 50 * SCL(state)};
    infos->str = (sfUint32 *)str;
    infos->color = sfWhite;
    infos->char_size = 50 * SCL(state);
    infos->is_ascii = 1;
    infos->whitelist = L"0123456789";
    infos->audio = state->game_data->audio;
    infos->select_sound = "mouse_click";
    return infos;
}

static void set_field_texts(state_t *state, int tag, int value)
{
    wchar_t *str = my_itowstr(value);
    textfield_t *field = GET_ITEM(state->gui, textfield_t, tag);

    textfield_setstr(field, (sfUint32 *)str);
    free(str);
}

void settings_update_fields(state_t *state)
{
    set_field_texts(state, SIZE_FIELD_X, \
    ((game_settings_t *)state->state_datas)->wind_size.x);
    set_field_texts(state, SIZE_FIELD_Y, \
    ((game_settings_t *)state->state_datas)->wind_size.y);
    set_field_texts(state, FRAMERATE_FIELD, \
    state->game_data->settings->limit_framerate);
}

void settings_init_fields(state_t *state)
{
    gui_manager_add_item(state->gui, &textfield_init, \
    (size_t)(settings_init_number_input(state, \
    (sfVector2f){1007 * SCL(state), 600 * SCL(state)}, \
    L"1280", 120)), SIZE_FIELD_X);
    gui_manager_add_item(state->gui, &textfield_init, \
    (size_t)(settings_init_number_input(state, \
    (sfVector2f){1177 * SCL(state), 600 * SCL(state)}, \
    L"720", 120)), SIZE_FIELD_Y);
    gui_manager_add_item(state->gui, &textfield_init, \
    (size_t)(settings_init_number_input(state, \
    (sfVector2f){1105 * SCL(state), 700 * SCL(state)}, \
    L"60", 90)), FRAMERATE_FIELD);
    settings_update_fields(state);
}