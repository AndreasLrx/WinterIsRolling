/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Game pause text fcts
*/

#include "States/Game/game_cst.h"
#include "States/Pause/game_pause_state.h"
#include "My/my_convert.h"
#include "My/my_strings.h"
#include "Drawables/drawable_create.h"

static wchar_t *create_str(int progress)
{
    int size_str = my_number_len(progress) + 22;
    wchar_t *istr = my_itowstr(progress);
    wchar_t *str = malloc(sizeof(wchar_t) * (size_str));

    my_wstrnset(str, 0, size_str);
    my_wstrcat(str, L"Level is ");
    my_wstrcat(str, istr);
    my_wstrcat(str, L"% complete !");
    free(istr);
    return str;
}

void game_pause_init_texts(state_t *state)
{
    state_t *game_state = \
    (state_t*)my_vector_top((size_t *)state->game_data->states);
    int progress = (int)GET_ITEM(game_state->gui, \
    scrollbar_t, PROGRESS_BAR)->value;
    wchar_t *str = create_str(progress);
    drawable_t *draw = malloc(sizeof(drawable_t));
    sfText *text = create_text(\
    get_font(state->game_data->assets, "roboto_font"), str, 80 * \
    SCL(state), (sfVector2f){0, 0});

    sfText_setPosition(text, (sfVector2f){(960 * SCL(state) - \
        (sfText_getGlobalBounds(text).width / 2.f)), 500 * SCL(state)});
    draw->text = text;
    my_map_insert(state->draw_layers[1], GP_TEXT, \
    (size_t)create_data_d(draw, D_TEXT));
}