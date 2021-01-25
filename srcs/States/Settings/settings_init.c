/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** settings init
*/

#include "States/Settings/settings_state.h"

void settings_add_bg(state_t *state)
{
    drawable_t *draw = malloc(sizeof(drawable_t));
    sfRectangleShape *bg = create_rect_shape(\
    get_texture(state->game_data->assets, "ls_bg"), \
    (sfVector2f){1280, 720}, \
    (sfVector2f){0, 0}, \
    (sfVector2f){SCL(state) * 1.5, SCL(state) * 1.5});

    draw->rect = bg;
    my_map_insert(state->draw_layers[0], \
    (size_t)SETTINGS_BACKGROUND_TAG, (size_t)create_data_d(draw, D_RECT));
}

void settings_add_boxes(state_t *state)
{
    drawable_t *draw = malloc(sizeof(drawable_t));
    sfRectangleShape *box = create_rect_shape(\
    get_texture(state->game_data->assets, "size_box"), \
    (sfVector2f){340, 50}, (sfVector2f){950 * SCL(state), \
        600 * SCL(state)}, (sfVector2f){SCL(state) * 1.2, SCL(state) * 1.2});

    draw->rect = box;
    my_map_insert(state->draw_layers[0], \
    (size_t)SIZE_BOX, (size_t)create_data_d(draw, D_RECT));
    draw = malloc(sizeof(drawable_t));
    box = create_rect_shape(\
    get_texture(state->game_data->assets, "framerate_box"), \
    (sfVector2f){90, 50}, (sfVector2f){1090 * SCL(state), \
        700 * SCL(state)}, (sfVector2f){SCL(state) * 1.2, SCL(state) * 1.2});
    draw->rect = box;
    my_map_insert(state->draw_layers[0], \
    (size_t)FRAMERATE_BOX, (size_t)create_data_d(draw, D_RECT));
}

int settings_init(state_t *state)
{
    settings_add_bg(state);
    settings_add_boxes(state);
    settings_init_scrolls(state);
    settings_init_texts(state);
    settings_init_fields(state);
    settings_init_buttons(state);
    return 0;
}