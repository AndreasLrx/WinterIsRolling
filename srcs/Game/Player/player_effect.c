/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** player effect
*/

#include "Game/game_struct.h"

void player_kill(player_t *player, int from)
{
    if (player->die_clock != 0)
        return;
    if (from == WATER)
        play_sound(player->game->state->game_data->audio, "splash");
    if (from == SPIKE || from == GROUND || from == -1)
        play_sound(player->game->state->game_data->audio, "hit");
    player_set_animation(player, DIE);
    player->die_clock = 1;
}

void player_land(player_t *player, pe_manifold_t *contact, pe_fixture_t *other)
{
    int ice = other->collision_filter.category == ICE;

    player->jump_sensor.normal = contact->normal;
    player->jump_sensor.lifetime = 10;
    if (ice) {
        pe_body_add_force(player->body, VEC2F(50, 0));
        player->jump_sensor.lifetime = -1;
    }
    if (player->fly_time > 100) {
        player_set_animation(player, LANDING);
        if (!ice)
            play_sound(player->game->state->game_data->audio, "land");
    }
    player->fly_time = 0;
}

void player_collect_snowflake(player_t *player, pe_fixture_t *flake)
{
    tilemap_t *map = player->game->map;
    pe_vec2f_t body_pos = flake->body->pos;
    int value = player->game->map->map[M_ACTIVE_LAYER(map)]\
    [M_POS((int)body_pos.x, (int)body_pos.y, map)];

    if (value > 0) {
        player->game->map->map[M_ACTIVE_LAYER(map)][M_POS((int)body_pos.x, \
        (int)body_pos.y, map)] *= -1;
        player->game->stats.snowflakes++;
        play_sound(player->game->state->game_data->audio, "snowflake_collect");
        player->game->global_stats->snowflakes_gathered++;
        player->game->stats.score += 100;
    }
}