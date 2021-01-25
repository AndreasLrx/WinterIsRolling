/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** menu - init drawables
*/

#include "States/Menu/menu_state.h"

static void init_background(state_t *state)
{
    drawable_t *draw = malloc(sizeof(drawable_t));
    background_t *bg = background_init(\
    get_texture(state->game_data->assets, "parallax_bg_menu"), \
    (sfVector2f){1800, 893}, 4, (sfVector2f){SCL(state) * 1.21, \
        SCL(state) * 1.21});

    draw->bg = bg;
    my_map_insert(state->draw_layers[0], \
    MENU_BACKGROUND_TAG, (size_t)create_data_d(draw, D_BG));
}

static void init_title(state_t *state)
{
    drawable_t *draw = malloc(sizeof(drawable_t));
    sfText *title = sfText_create();

    sfText_setFont(title, get_font(state->game_data->assets, "title_font"));
    sfText_setPosition(title, (sfVector2f){482 * SCL(state), 50 * SCL(state)});
    sfText_setCharacterSize(title, 150 * SCL(state));
    sfText_setString(title, "Winter  is  Rolling");
    sfText_setFillColor(title, sfColor_fromRGB(120, 182, 216));
    sfText_setOutlineColor(title, sfWhite);
    sfText_setOutlineThickness(title, 2 * SCL(state));
    draw->text = title;
    my_map_insert(state->draw_layers[0], \
    MENU_TITLE_TAG, (size_t)create_data_d(draw, D_TEXT));
}

void menu_init_drawables(state_t *state)
{
    init_background(state);
    init_title(state);
}