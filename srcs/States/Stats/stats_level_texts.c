/*
** EPITECH PROJECT, 2021
** My runner
** File description:
** stats level text
*/

#include "States/Stats/stats_state.h"
#include "Drawables/drawable_create.h"

void update_level_texts(global_stats_t *stats, state_t *state, int level_id)
{
    level_stats_t *levels = stats->levels;

    sfText_setUnicodeString(((draw_elmt_t *)my_map_find(state->draw_layers[0], \
    STATS_HIGHEST_PERCENT))->draw->text, (sfUint32 *)create_wstr(\
    L"Highest Progression : ", L"%", levels[level_id].highest_percent));
    sfText_setUnicodeString(((draw_elmt_t *)my_map_find(state->draw_layers[0], \
    STATS_HIGHEST_SCORE))->draw->text, (sfUint32 *)create_wstr(\
    L"Highest Score : ", NULL, levels[level_id].highest_score));
    sfText_setUnicodeString(((draw_elmt_t *)my_map_find(state->draw_layers[0], \
    STATS_LEVEL_PLAYED))->draw->text, (sfUint32 *)create_wstr(\
    L"Time Played : ", NULL, levels[level_id].nb_played));
    sfText_setUnicodeString(((draw_elmt_t *)my_map_find(state->draw_layers[0], \
    STATS_LEVEL_SUCCESS))->draw->text, (sfUint32 *)create_wstr(\
    L"Time Successed : ", NULL, levels[level_id].nb_success));
}

static void create_field(state_t *state)
{
    struct textfield_infos_t *infos = malloc(sizeof(struct textfield_infos_t));

    infos->font = get_font(state->game_data->assets, "roboto_font");
    infos->pos = (sfVector2f){1315 * SCL(state), 252 * SCL(state)};
    infos->size = (sfVector2f){60 * SCL(state), 50 * SCL(state)};
    infos->str = (sfUint32 *)L"1";
    infos->color = sfWhite;
    infos->char_size = 50 * SCL(state);
    infos->is_ascii = 1;
    infos->whitelist = L"0123456789";
    infos->audio = state->game_data->audio;
    infos->select_sound = "mouse_click";
    gui_manager_add_item(state->gui, &textfield_init, \
    (size_t)infos, STATS_LEVEL_FIELD);
}

void stats_init_level_field(state_t *state)
{
    drawable_t *draw = malloc(sizeof(drawable_t));
    sfRectangleShape *box = create_rect_shape(\
    get_texture(state->game_data->assets, "framerate_box"), \
    (sfVector2f){90, 50}, (sfVector2f){1295 * SCL(state), \
        255 * SCL(state)}, (sfVector2f){SCL(state) * 1.2, SCL(state) * 1.2});

    draw->rect = box;
    my_map_insert(state->draw_layers[0], \
    (size_t)STATS_LEVEL_BOX, (size_t)create_data_d(draw, D_RECT));
    create_field(state);
}