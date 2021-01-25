/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Game init rectshapes
*/

#include "States/Game/game_state.h"
#include "Drawables/drawable_create.h"

static void init_rect(state_t *state, char const *text_name, \
sfVector2f pos, int tag)
{
    drawable_t *draw = malloc(sizeof(drawable_t));
    sfRectangleShape *rect = create_rect_shape(\
    get_texture(state->game_data->assets, text_name), \
    (sfVector2f){80 * SCL(state), 80 * SCL(state)}, pos, (sfVector2f){1, 1});

    draw->rect = rect;
    my_map_insert(state->draw_layers[0], tag, \
    (size_t)create_data_d(draw, D_RECT));
}

void game_init_rects(state_t *state)
{
    init_rect(state, "clock", \
    (sfVector2f){1600 * SCL(state), 75 * SCL(state)}, G_TIME_ICON);
    init_rect(state, "snowflake", \
    (sfVector2f){20 * SCL(state), 100 * SCL(state)}, G_SNOWFLAKE);
}