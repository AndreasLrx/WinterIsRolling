/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** player handle input
*/

#include "Game/game_struct.h"

static void player_jump(player_t *player)
{
    if (player->jump_sensor.lifetime < 0 || player->die_clock != 0)
        return;
    player->jump_sensor.lifetime = -1;
    player_set_animation(player, JUMP);
    player->body->velocity.y += -0.80 * player->body->mass.mass;
    play_sound(player->game->state->game_data->audio, "land");
    player->game->global_stats->nb_jumps++;
}

void player_handle_input(player_t *player, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace) {
        player_jump(player);
    }
}