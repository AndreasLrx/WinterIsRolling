/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** handle game inputs
*/

#include "States/Game/game_state.h"

int game_pause_create(game_data_t *data, state_t *state, size_t datas);
int level_end_create(game_data_t *data, state_t *state, size_t datas);

static void handle_guis_outputs(state_t *state, \
game_data_t *data, gui_manager_t *manager)
{
    struct gui_output **outputs = manager->outputs;
    size_t nb_outputs = my_vector_get_size((size_t *)outputs);

    for (size_t i = 0; i < nb_outputs; i++){
        if (outputs[i]->tag == PAUSE_BUTTON){
            add_state(data, &game_pause_create, 0, (size_t)state->state_datas);
            return;
        }
    }
}

static void level_complete_stats_update(state_t *state, int complete)
{
    game_t *game = (game_t *)state->state_datas;
    global_stats_t *stats = (global_stats_t *)state->game_data->datas;
    level_stats_t *lvl_stats = &stats->levels[game->stats.level_id];

    lvl_stats->nb_played--;
    if (complete)
        lvl_stats->nb_success++;
    stats->lvl_played--;
}

static void create_end_level_state(state_t *state)
{
    int end_level = 0;
    int complete = 1;

    if (GET_ITEM(state->gui, scrollbar_t, PROGRESS_BAR)->value >= 100)
        end_level = 1;
    if (((game_t *)state->state_datas)->player->respawn_left <= 0) {
        end_level = 1;
        complete = 0;
    }
    if (end_level) {
        add_state(state->game_data, &level_end_create, 0, complete);
        if (complete)
            player_respawn(((game_t *)state->state_datas)->player);
        level_complete_stats_update(state, complete);
        ((game_t *)state->state_datas)->player->respawn_left = PLAYER_LIVES;
    }
}

static int handle_key(sfEvent event, state_t *state)
{
    switch (event.key.code) {
    case sfKeyEscape:
        play_sound(state->game_data->audio, "mouse_click");
        add_state(state->game_data, &game_pause_create, 0, (size_t)state->state_datas);
        return 1;
    case sfKeyR:
        game_struct_restart((game_t *)state->state_datas);
        return 0;
    default:
        return 0;
    }
}

int game_handle_input(state_t *state)
{
    game_data_t *data = state->game_data;
    sfEvent event;

    while (sfRenderWindow_pollEvent(data->window, &event)){
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(data->window);
            return 1;
        }
        if (event.type == sfEvtKeyReleased && handle_key(event, state))
            return 1;
        game_struct_handle_input((game_t *)state->state_datas, event);
        guis_handle_input(state->gui, (size_t)&event);
    }
    if (state->gui->outputs != NULL)
        handle_guis_outputs(state, data, state->gui);
    create_end_level_state(state);
    return 1;
}