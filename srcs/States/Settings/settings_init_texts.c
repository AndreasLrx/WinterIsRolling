/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Settings - init texts
*/

#include "States/Settings/settings_state.h"
#include "Drawables/drawable_create.h"

static void init_title(state_t *state)
{
    drawable_t *draw = malloc(sizeof(drawable_t));
    sfText *title = create_text(get_font(state->game_data->assets, \
    "roboto_font"), L"Settings", 120 * SCL(state), \
    (sfVector2f){743 * SCL(state), 50 * SCL(state)});

    sfText_setOutlineColor(title, sfColor_fromRGB(35, 63, 122));
    sfText_setOutlineThickness(title, SCL(state) * 5);
    draw->text = title;
    my_map_insert(state->draw_layers[0], \
    SETTINGS_TITLE_TAG, (size_t)create_data_d(draw, D_TEXT));
}

static void init_text(state_t *state, wchar_t const *str, \
sfVector2f pos, int tag)
{
    drawable_t *draw = malloc(sizeof(drawable_t));
    sfText *title = create_text(get_font(state->game_data->assets, \
    "roboto_font"), str, 50 * SCL(state), pos);

    sfText_setOutlineColor(title, sfBlack);
    sfText_setOutlineThickness(title, 1 * SCL(state));
    draw->text = title;
    my_map_insert(state->draw_layers[0], \
    tag, (size_t)create_data_d(draw, D_TEXT));
}

void settings_init_texts(state_t *state)
{
    init_title(state);
    init_text(state, L"Music Volume :", \
    (sfVector2f){529 * SCL(state), 375 * SCL(state)}, MUSIC_TEXT);
    init_text(state, L"Sound Volume :", \
    (sfVector2f){525 * SCL(state), 475 * SCL(state)}, SOUND_TEXT);
    init_text(state, L"Window Size :", \
    (sfVector2f){623 * SCL(state), 600 * SCL(state)}, SIZE_TEXT);
    init_text(state, L"Framerate limit :", \
    (sfVector2f){725 * SCL(state), 700 * SCL(state)}, FRAMERATE);
}