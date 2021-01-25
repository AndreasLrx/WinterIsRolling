/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Draw level_end
*/

#include "States/LevelEnd/level_end_state.h"

int level_end_draw(state_t *state, float dt)
{
    sfRenderStates blur_state;
    blur_state.texture = NULL;
    blur_state.blendMode = sfBlendNone;
    blur_state.transform = sfTransform_fromMatrix(1, 0, 0, 0, 1, 0, 0, 0, 1);
    blur_state.shader = get_shader(state->game_data->assets, "blur");
    sfRenderWindow *window = state->game_data->window;
    size_t nb_layers = my_vector_get_size((size_t *)state->draw_layers);

    sfRenderWindow_clear(window, sfColor_fromRGB(18, 18, 18));
    sfRenderWindow_drawRectangleShape(window, \
    ((draw_elmt_t *)my_map_at(state->draw_layers[0], 0))->draw->rect, \
    &blur_state);
    for (size_t layer = 1; layer < nb_layers; layer++){
        draw_map(state->draw_layers[layer], window);
    }
    guis_draw(state->gui, window);
    sfRenderWindow_display(window);
    return 1;
}