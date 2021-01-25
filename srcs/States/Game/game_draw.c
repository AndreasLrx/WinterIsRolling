/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Draw game
*/

#include "States/Game/game_state.h"

int game_draw(state_t *state, float dt)
{
    sfRenderWindow *window = state->game_data->window;
    size_t nb_layers = my_vector_get_size((size_t *)state->draw_layers);

    sfRenderWindow_clear(window, sfColor_fromRGB(18, 18, 18));
    game_struct_draw((game_t *)state->state_datas, window);
    for (size_t layer = 0; layer < nb_layers; layer++){
        draw_map(state->draw_layers[layer], window);
    }
    guis_draw(state->gui, window);
    sfRenderWindow_display(window);
    return 1;
}

int game_draw_render_texture(state_t *state, sfRenderTexture *texture)
{
    size_t nb_layers = my_vector_get_size((size_t *)state->draw_layers);

    sfRenderTexture_clear(texture, sfColor_fromRGB(18, 18, 18));
    game_struct_draw_texture((game_t *)state->state_datas, texture);
    for (size_t layer = 0; layer < nb_layers; layer++){
        draw_map_texture(state->draw_layers[layer], texture);
    }
    guis_draw_texture(state->gui, texture);
    sfRenderTexture_display(texture);
    return 1;
}