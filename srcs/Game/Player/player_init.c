/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** player init
*/

#include "Game/game_struct.h"
#include "Physics/physics.h"

static void init_body(player_t *player, sfVector2i pos, pe_world_t *world)
{
    pe_body_t *body = pe_body_init(DYNAMIC, 5, 5);
    pe_fixture_t *fixture = pe_fixture_init();
    pe_fixture_t *sensor = pe_fixture_init();

    body->can_sleep = 0;
    body->pos = VEC2F(pos.x, pos.y);
    body->linear_damping = -1;
    body->fixed_rotation = 1;
    fixture->restitution = 0.2;
    fixture->collision_filter.category = PLAYER;
    sensor->is_sensor = 1;
    pe_shape_init_circle(&sensor->shape, PLAYER_TILE_RADIUS * 1.1, VEC2F(0, 0));
    fixture->density = 3;
    pe_shape_init_circle(&fixture->shape, PLAYER_TILE_RADIUS, VEC2F(0, 0));
    pe_body_add_fixture(body, fixture);
    pe_body_add_fixture(body, sensor);
    pe_world_add_body(world, body);
    player->body = body;
}

player_t *player_init(game_t *game, sfVector2i pos, \
pe_world_t *world, int tile_size)
{
    player_t *player = malloc(sizeof(player_t));

    player->start_pos = pos;
    player->shape = sfRectangleShape_create();
    sfRectangleShape_setTexture(player->shape, \
    get_texture(game->state->game_data->assets, "sb_sheet"), 1);
    sfRectangleShape_setTextureRect(player->shape, (sfIntRect){0, 0, 256, 256});
    sfRectangleShape_setSize(player->shape, (sfVector2f){\
        PLAYER_TILE_RADIUS * 2.27 * tile_size, \
        PLAYER_TILE_RADIUS * 2.27 * tile_size});
    player->tile_size = tile_size;
    player->game = game;
    player->game->map->player = player;
    init_body(player, pos, world);
    player_respawn(player);
    player->respawn_left = PLAYER_LIVES;
    return player;
}

static void update_stats(player_t *player, global_stats_t *glob_stats, \
level_stats_t *lvl_stats)
{
    glob_stats->lvl_played++;
    glob_stats->total_time += player->game->stats.time;
    lvl_stats->nb_played++;
    if (lvl_stats->highest_score < player->game->stats.score)
        lvl_stats->highest_score = player->game->stats.score;
}

void player_respawn(player_t *player)
{
    pe_body_t *body = player->body;
    sfVector2i pos = player->start_pos;
    sfVector2f shape_size = sfRectangleShape_getSize(player->shape);

    shape_size.x /= 2.f;
    shape_size.y /= 2.f;
    player->game->global_stats->distance_rolled += body->pos.x - pos.x;
    update_stats(player, player->game->global_stats, \
    &player->game->global_stats->levels[player->game->stats.level_id]);
    body->pos = VEC2F(pos.x, pos.y);
    body->velocity = VEC2F(0, 0);
    sfRectangleShape_setPosition(player->shape, (sfVector2f){\
        (pos.x * player->tile_size) - shape_size.x, \
        (pos.y * player->tile_size) - shape_size.y * PLAYER_PENETRATION_RATIO});
    player->jump_sensor.lifetime = -1;
    player->die_clock = 0;
    player->fly_time = 0;
    player->game->stats = (game_stats_t){0, 0, 0, player->game->stats.level_id};
    player->respawn_left -= 1;
    tilemap_regen(player->game->map);
    player_set_animation(player, ROLLING);
}