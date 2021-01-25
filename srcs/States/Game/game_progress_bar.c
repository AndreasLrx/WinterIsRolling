/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Game - progress bar fcts
*/

#include "States/Game/game_state.h"

void game_progress_bar_update(state_t *state)
{
    game_t *gm = (game_t *)state->state_datas;
    scrollbar_t *bar = GET_ITEM(state->gui, scrollbar_t, PROGRESS_BAR);
    float value = (100 * gm->player->body->pos.x) / \
    ((float)gm->map->size.x - 10);

    scrollbar_set_value(bar, value);
    if (value > gm->global_stats->levels[gm->stats.level_id].highest_percent)
        gm->global_stats->levels[gm->stats.level_id].highest_percent = value;
}

static void init_p_bar_colors(struct scrollbar_infos_t *infos)
{
    infos->fill_colors = malloc(sizeof(sfColor) * 5);
    infos->fill_colors[0] = sfWhite;
    infos->fill_colors[1] = sfColor_fromRGB(101, 180, 255);
    infos->fill_colors[2] = sfWhite;
    infos->fill_colors[3] = sfWhite;
    infos->fill_colors[4] = sfWhite;
    infos->out_colors = malloc(sizeof(sfColor) * 4);
    infos->out_colors[0] = sfBlack;
    infos->out_colors[1] = sfBlack;
    infos->out_colors[2] = sfBlack;
    infos->out_colors[3] = sfBlack;
}

static struct scrollbar_infos_t *init_p_bar(state_t *state)
{
    struct scrollbar_infos_t *infos = malloc(sizeof(struct scrollbar_infos_t));

    infos->pos = (sfVector2f){610 * SCL(state), 50 * SCL(state)};
    infos->bar_size = (sfVector2f){700 * SCL(state), \
        40 * SCL(state)};
    infos->cursor_size = (sfVector2f){0, 0};
    infos->min_len = (sfVector2f){0, 100};
    infos->min_max_cursor_pos = (sfVector2f){0, 1};
    infos->update_type = GUI_COLORED | GUI_OUTCOLORED;
    init_p_bar_colors(infos);
    infos->out_thickness = 3 * SCL(state);
    infos->vertical = 0;
    infos->nb_states = 2;
    infos->fill = 1;
    return infos;
}

void game_init_progress_bar(state_t *state)
{
    gui_manager_add_item(state->gui, &scrollbar_init, \
    (size_t)init_p_bar(state), PROGRESS_BAR);
    gui_manager_enable_item(state->gui, PROGRESS_BAR, 0);
}