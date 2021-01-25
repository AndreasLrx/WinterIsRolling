/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Game - init / update texts
*/

#include "States/Game/game_state.h"
#include "Drawables/drawable_create.h"
#include "My/my_strings.h"

static char *get_time_str(int value)
{
    int seconds = value % 60;
    int minutes = (value / 60) % 60;
    char *str = malloc(sizeof(char) * 6);

    str[0] = minutes / 10 + '0';
    str[1] = minutes % 10 + '0';
    str[2] = ':';
    str[3] = seconds / 10 + '0';
    str[4] = seconds % 10 + '0';
    str[5] = 0;
    return str;
}

void game_update_text(state_t *state, unsigned char tag, \
int new_value, int nb_digits)
{
    int nb_back = new_value;
    sfText *text = ((draw_elmt_t *)my_map_find(\
    state->draw_layers[0], tag))->draw->text;
    char *str;

    if (tag == G_TIME_TEXT)
        str = get_time_str(new_value);
    else {
        str = malloc(sizeof(char) * (nb_digits + 1));
        my_strnset(str, '0', nb_digits);
        str[nb_digits] = 0;
        for (int i = 1; nb_back >= 1 && i <= nb_digits; i++){
            str[nb_digits - i] = nb_back % 10 + '0';
            nb_back /= 10;
        }
    }
    sfText_setString(text, str);
    free(str);
}

void game_update_texts(state_t *state)
{
    game_stats_t *stats = &((game_t *)state->state_datas)->stats;

    game_update_text(state, G_SCORE_TEXT, stats->score, 5);
    game_update_text(state, G_TIME_TEXT, (int)stats->time, 3);
    game_update_text(state, G_SNOWFLAKE_TEXT, \
    ((game_t *)state->state_datas)->stats.snowflakes, 3);
}

static void init_text(state_t *state, wchar_t const *str, \
sfVector2f pos, unsigned char tag)
{
    drawable_t *draw = malloc(sizeof(drawable_t));
    sfText *text = create_text(get_font(state->game_data->assets, \
    "roboto_font"), str, 50 * SCL(state), pos);

    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 1 * SCL(state));
    draw->text = text;
    my_map_insert(state->draw_layers[0], (size_t)tag, \
    (size_t)create_data_d(draw, D_TEXT));
}

void game_init_texts(state_t *state)
{
    init_text(state, L"Score :", \
    (sfVector2f){20 * SCL(state), 20 * SCL(state)}, G_SCORE_TEXT_DESC);
    init_text(state, L"00000", \
    (sfVector2f){200 * SCL(state), 20 * SCL(state)}, G_SCORE_TEXT);
    init_text(state, L"000", \
    (sfVector2f){120 * SCL(state), 110 * SCL(state)}, G_SNOWFLAKE_TEXT);
    init_text(state, L"000", \
    (sfVector2f){1450 * SCL(state), 85 * SCL(state)}, G_TIME_TEXT);
}