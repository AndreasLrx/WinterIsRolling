/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** menu init
*/

#include "States/Stats/stats_state.h"
#include "Drawables/drawable_create.h"
static void add_bg(state_t *state)
{
    drawable_t *draw = malloc(sizeof(drawable_t));
    sfRectangleShape *bg = create_rect_shape(\
    get_texture(state->game_data->assets, "ls_bg"), \
    (sfVector2f){1280, 720}, \
    (sfVector2f){0, 0}, \
    (sfVector2f){SCL(state) * 1.5, SCL(state) * 1.5});

    draw->rect = bg;
    my_map_insert(state->draw_layers[0], \
    (size_t)STATS_BACKGROUND_TAG, (size_t)create_data_d(draw, D_RECT));
}

static void init_title(state_t *state)
{
    drawable_t *draw = malloc(sizeof(drawable_t));
    sfText *title = create_text(get_font(state->game_data->assets, \
    "roboto_font"), L"Statistics", 120 * SCL(state), \
    (sfVector2f){712 * SCL(state), 50 * SCL(state)});

    sfText_setOutlineColor(title, sfColor_fromRGB(35, 63, 122));
    sfText_setOutlineThickness(title, SCL(state) * 5);
    draw->text = title;
    my_map_insert(state->draw_layers[0], \
    STATS_TITLE_TAG, (size_t)create_data_d(draw, D_TEXT));
}

int stats_init(state_t *state)
{
    add_bg(state);
    init_title(state);
    stats_init_texts(state);
    gui_manager_add_item(state->gui, &button_init, \
    (size_t)init_iced_btn(state, RETURN, \
    (sfVector2f){50 * SCL(state), 50 * SCL(state)}), STATS_QUIT_BTN);
    stats_init_level_field(state);
    return 0;
}