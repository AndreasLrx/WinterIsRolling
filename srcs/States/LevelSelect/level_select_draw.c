/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Draw level_select
*/

#include "States/LevelSelect/level_select_state.h"

static void draw_grid(level_grid_t *grid, sfRenderWindow *wind)
{
    for (int i = 0; i < grid->nb_buttons; i++){
        grid->buttons[i]->draw(grid->buttons[i]->item, wind);
    }
}

int level_select_draw(state_t *state, float dt)
{
    sfRenderWindow *window = state->game_data->window;
    size_t nb_layers = my_vector_get_size((size_t *)state->draw_layers);

    sfRenderWindow_clear(window, sfColor_fromRGB(18, 18, 18));
    for (size_t layer = 0; layer < nb_layers; layer++){
        draw_map(state->draw_layers[layer], window);
    }
    guis_draw(state->gui, window);
    draw_grid((level_grid_t *)state->state_datas, window);
    sfRenderWindow_display(window);
    return 1;
}