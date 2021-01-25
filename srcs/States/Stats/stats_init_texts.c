/*
** EPITECH PROJECT, 2021
** My runner
** File description:
** Stats init texts
*/

#include "States/Stats/stats_state.h"
#include "Drawables/drawable_create.h"
#include "My/my_strings.h"
#include "My/my_convert.h"
#include "My/my_memory.h"

wchar_t *create_wstr(wchar_t *prefix, wchar_t *suffix, int value)
{
    int size_str = my_wstrlen(prefix) + my_wstrlen(suffix) + \
    my_number_len(value);
    wchar_t *str = my_calloc(sizeof(wchar_t) * (size_str + 1), 0);
    wchar_t *istr = my_itowstr(value);

    my_wstrcat(str, prefix);
    my_wstrcat(str, istr);
    my_wstrcat(str, suffix);
    str[size_str] = 0;
    free(istr);
    return str;
}

static wchar_t *create_time_str(wchar_t *prefix, wchar_t *suffix, int value)
{
    int pre_len = my_wstrlen(prefix);
    int size_str = pre_len + my_wstrlen(suffix) + 8;
    wchar_t *str = my_calloc(sizeof(wchar_t) * (size_str + 1), 0);

    my_wstrcat(str, prefix);
    str[pre_len] = (value / 3600) / 10 + L'0';
    str[pre_len + 1] = (value / 3600) % 10 + L'0';
    str[pre_len + 2] = L'h';
    str[pre_len + 3] = ((value % 3600) / 60) / 10 + L'0';
    str[pre_len + 4] = ((value % 3600) / 60) % 10 + L'0';
    my_wstrcat(str, L"min");
    str[size_str] = 0;
    return str;
}

static void init_text(state_t *state, wchar_t *str, \
sfVector2f pos, unsigned char tag)
{
    drawable_t *draw = malloc(sizeof(drawable_t));
    sfText *text = create_text(get_font(state->game_data->assets, \
    "roboto_font"), str, 50 * SCL(state), pos);

    sfText_setOutlineColor(text, sfColor_fromRGB(35, 63, 122));
    sfText_setOutlineThickness(text, SCL(state) * 3);
    free(str);
    draw->text = text;
    my_map_insert(state->draw_layers[0], \
    tag, (size_t)create_data_d(draw, D_TEXT));
}

static void init_level_texts(state_t *state)
{
    init_text(state, create_wstr(L"Level     ", L"     Stats :", 0), \
    (sfVector2f){1160 * SCL(state), 250 * SCL(state)}, STATS_LEVEL_TEXT);
    init_text(state, NULL, (sfVector2f){1160 * SCL(state), \
        350 * SCL(state)}, STATS_HIGHEST_PERCENT);
    init_text(state, NULL, (sfVector2f){1160 * SCL(state), \
        450 * SCL(state)}, STATS_HIGHEST_SCORE);
    init_text(state, NULL, (sfVector2f){1160 * SCL(state), \
        550 * SCL(state)}, STATS_LEVEL_PLAYED);
    init_text(state, NULL, (sfVector2f){1160 * SCL(state), \
        650 * SCL(state)}, STATS_LEVEL_SUCCESS);
}

void stats_init_texts(state_t *state)
{
    global_stats_t *stats = (global_stats_t *)state->game_data->datas;

    init_text(state, create_wstr(L"Snowflakes : ", NULL, \
    stats->snowflakes_gathered), (sfVector2f){200 * SCL(state), \
        250 * SCL(state)}, STATS_FLAKES);
    init_text(state, create_time_str(L"Time Played : ", NULL, \
    stats->total_time), (sfVector2f){200 * SCL(state), \
        350 * SCL(state)}, STATS_TIME);
    init_text(state, create_wstr(L"Number of Jump : ", NULL, stats->nb_jumps), \
    (sfVector2f){200 * SCL(state), 450 * SCL(state)}, STATS_JUMP);
    init_text(state, create_wstr(L"Distance Rolled : ", L"m", \
    stats->distance_rolled), (sfVector2f){200 * SCL(state), \
        550 * SCL(state)}, STATS_DIST);
    init_text(state, create_wstr(L"Number of Game Played : ", NULL, \
    stats->lvl_played), (sfVector2f){200 * SCL(state), \
        650 * SCL(state)}, STATS_GAME_PLAYED);
    init_level_texts(state);
    update_level_texts(stats, state, 0);
}