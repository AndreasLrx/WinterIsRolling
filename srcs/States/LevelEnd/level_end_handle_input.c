/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** handle level_end inputs
*/

#include "States/LevelEnd/level_end_state.h"
#include "States/Game/game_state.h"

static void handle_right(game_data_t *data, state_t *state)
{
    state_t *game_state;
    game_t *game;
    global_stats_t *stats;
    level_stats_t *lvl_stats;
    int is_level_complete = state->state_datas[1];
    int level_id;

    end_state(data, LEVEL_END_STATE);
    game_state = (state_t *)my_vector_top((size_t *)data->states);
    game = (game_t *)game_state->state_datas;
    level_id = game->stats.level_id;
    if (is_level_complete) {
        //end_state(data, (level_id < 2) ? NONE : LEVEL_END_STATE);
        if (level_id < 2)
            add_state(data, &game_create, 1, level_id + 1);
        else
            end_state(data, LEVEL_END_STATE);
    } else {
        stats = (global_stats_t *)game_state->game_data->datas;
        lvl_stats = &stats->levels[level_id];
        lvl_stats->nb_played++;
        stats->lvl_played++;
    }
}

static void handle_left(game_data_t *data, state_t *state)
{
    int is_level_complete = state->state_datas[1];

    end_state(data, LEVEL_END_STATE);
    if (!is_level_complete)
        end_state(data, LEVEL_END_STATE);
}

static void handle_guis_outputs(game_data_t *data, \
gui_manager_t *manager, state_t *state)
{
    struct gui_output **outputs = manager->outputs;
    size_t nb_outputs = my_vector_get_size((size_t *)outputs);

    for (size_t i = 0; i < nb_outputs; i++){
        if (outputs[i]->tag == LE_LEFT_BUTTON) {
            handle_left(data, state);
            return;
        }
        if (outputs[i]->tag == LE_RIGHT_BUTTON) {
            handle_right(data, state);
            return;
        }
    }
}

int level_end_handle_input(state_t *state)
{
    game_data_t *data = state->game_data;
    sfEvent event;

    while (sfRenderWindow_pollEvent(data->window, &event)){
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(data->window);
            return 1;
        }
        guis_handle_input(state->gui, (size_t)&event);
    }
    if (state->gui->outputs != NULL)
        handle_guis_outputs(data, state->gui, state);
    return 1;
}