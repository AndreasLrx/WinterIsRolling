/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Game pause text fcts
*/

#include "States/Game/game_cst.h"
#include "States/LevelEnd/level_end_state.h"
#include "My/my_convert.h"
#include "My/my_strings.h"
#include "Drawables/drawable_create.h"

static wchar_t *create_str(int flakes)
{
    int size_str = my_number_len(flakes) + 23;
    wchar_t *istr = my_itowstr(flakes);
    wchar_t *str = malloc(sizeof(wchar_t) * (size_str));

    my_wstrnset(str, 0, size_str);
    my_wstrcat(str, istr);
    my_wstrcat(str, L" Snowflakes collected!");
    free(istr);
    return str;
}

void level_end_init_texts(state_t *state)
{
    state_t *game_state = \
    (state_t*)my_vector_top((size_t *)state->game_data->states);
    int snowflakes = ((game_t *)game_state->state_datas)->stats.snowflakes;
    wchar_t *str = (state->state_datas[1]) ? \
create_str(snowflakes) : L"Keep trying ?";
    drawable_t *draw = malloc(sizeof(drawable_t));
    sfText *text = create_text(\
    get_font(state->game_data->assets, "roboto_font"), str, 80 * \
    SCL(state), (sfVector2f){0, 0});

    sfText_setPosition(text, (sfVector2f){(960 * SCL(state) - \
        (sfText_getGlobalBounds(text).width / 2.f)), 500 * SCL(state)});
    draw->text = text;
    my_map_insert(state->draw_layers[1], LE_TEXT, \
    (size_t)create_data_d(draw, D_TEXT));
}