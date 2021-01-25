/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** game_pause init
*/

#include "States/Pause/game_pause_state.h"
#include "Drawables/drawable_create.h"

int game_draw_render_texture(state_t *state, sfRenderTexture *texture);

static void copy_background(state_t *state, sfRenderWindow *window)
{
    sfVector2u wind_size = state->game_data->settings->wind_size;
    sfRenderTexture *render_texture = \
    sfRenderTexture_create(wind_size.x, wind_size.y, 0);
    state_t *game_state = \
    (state_t *)my_vector_top((size_t *)state->game_data->states);
    drawable_t *draw = malloc(sizeof(drawable_t));
    sfRectangleShape *rect = create_rect_shape(NULL, \
    (sfVector2f){wind_size.x, wind_size.y}, (sfVector2f){0, 0}, \
    (sfVector2f){1, 1});

    game_draw_render_texture(game_state, render_texture);
    sfRectangleShape_setTexture(rect, \
    sfRenderTexture_getTexture(render_texture), 1);
    draw->rect = rect;
    my_map_insert(state->draw_layers[0], GP_BLUR_LAYER, \
    (size_t)create_data_d(draw, D_RECT));
    state->state_datas = (size_t *)render_texture;
}

static void init_rect_frame(state_t *state)
{
    drawable_t *draw = malloc(sizeof(drawable_t));
    sfRectangleShape *rect = create_rect_shape(NULL, \
    (sfVector2f){1280 * SCL(state), 720 * SCL(state)}, \
    (sfVector2f){320 * SCL(state), 180 * SCL(state)}, (sfVector2f){1, 1});

    sfRectangleShape_setFillColor(rect, sfColor_fromRGBA(39, 70, 135, 170));
    sfRectangleShape_setOutlineColor(rect, sfColor_fromRGB(39, 63, 122));
    sfRectangleShape_setOutlineThickness(rect, 10 * SCL(state));
    draw->rect = rect;
    my_map_insert(state->draw_layers[1], GP_RECT, \
    (size_t)create_data_d(draw, D_RECT));
}

static void init_title(state_t *state)
{
    drawable_t *draw = malloc(sizeof(drawable_t));
    sfText *text = create_text(\
    get_font(state->game_data->assets, "roboto_font"), \
    L"GAME PAUSED", 85 * SCL(state), \
    (sfVector2f){674 * SCL(state), 210 * SCL(state)});

    sfText_setOutlineColor(text, sfBlack);
    sfText_setOutlineThickness(text, 4 * SCL(state));
    sfText_setStyle(text, sfTextBold);
    draw->text = text;
    my_map_insert(state->draw_layers[1], GP_TITLE, \
    (size_t)create_data_d(draw, D_TEXT));
}

int game_pause_init(state_t *state)
{
    init_rect_frame(state);
    game_pause_init_texts(state);
    copy_background(state, state->game_data->window);
    init_title(state);
    gui_manager_add_item(state->gui, &button_init, \
    (size_t)init_iced_btn(state, PLAY, \
    (sfVector2f){1450 * SCL(state), 200 * SCL(state)}), PLAY_BUTTON);
    gui_manager_add_item(state->gui, &button_init, \
    (size_t)init_iced_btn(state, HOME, \
    (sfVector2f){340 * SCL(state), 200 * SCL(state)}), GP_QUIT_BUTTON);
    gui_manager_add_item(state->gui, &button_init, \
    (size_t)init_iced_btn(state, SETTINGS, \
    (sfVector2f){1300 * SCL(state), 200 * SCL(state)}), GP_SETTINGS_BUTTON);
    gui_manager_add_item(state->gui, &button_init, \
    (size_t)init_iced_btn(state, RESET, \
    (sfVector2f){490 * SCL(state), 200 * SCL(state)}), GP_RESTART_BUTTON);
    return 0;
}