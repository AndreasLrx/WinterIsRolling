/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Level select - init title & background
*/

#include "States/LevelSelect/level_select_state.h"
#include "Drawables/drawables_head.h"

static void init_bg(state_t *state)
{
    drawable_t *draw = malloc(sizeof(drawable_t));
    sfRectangleShape *rect = create_rect_shape(\
    get_texture(state->game_data->assets, "ls_bg"), \
    (sfVector2f){1920 * SCL(state), 1280 * SCL(state)}, \
    (sfVector2f){0, 0}, (sfVector2f){1, 1});

    sfRectangleShape_setOutlineColor(rect, sfColor_fromRGB(62, 168, 228));
    sfRectangleShape_setOutlineThickness(rect, 5 * SCL(state));
    draw->rect = rect;
    my_map_insert(state->draw_layers[0], LS_BACKGROUND, \
    (size_t)create_data_d(draw, D_RECT));
}

static void init_title(state_t *state)
{
    drawable_t *draw = malloc(sizeof(drawable_t));
    sfText *title = create_text(\
    get_font(state->game_data->assets, "roboto_font"), \
    L"Level Selection", 120 * SCL(state), \
    (sfVector2f){565 * SCL(state), 40 * SCL(state)});

    sfText_setOutlineColor(title, sfColor_fromRGB(35, 63, 122));
    sfText_setOutlineThickness(title, SCL(state) * 5);
    draw->text = title;
    my_map_insert(state->draw_layers[0], LS_TITLE_TAG, \
    (size_t)create_data_d(draw, D_TEXT));
}

void level_select_init_title(state_t *state)
{
    init_bg(state);
    init_title(state);
}