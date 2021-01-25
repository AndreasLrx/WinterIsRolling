/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Player
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "Physics/Utils/vec2.h"
#include "Game/Player/player_cst.h"

enum PLAYER_ANIM {ROLLING, JUMP, DIE, LANDING};

struct pe_world_t;
struct game_t;
struct pe_manifold_t;
struct pe_fixture_t;

struct jump_sensor_t {
    pe_vec2f_t normal;
    int lifetime;
};

typedef struct player_t {
    sfVector2i start_pos;
    struct pe_body_t *body;
    struct sfRectangleShape *shape;
    int current_anim;
    int current_frame;
    int frame_duration;
    int tile_size;
    int die_clock;
    int respawn_left;
    int fly_time;
    struct jump_sensor_t jump_sensor;
    struct game_t *game;
} player_t;

player_t *player_init(struct game_t *game, sfVector2i pos, \
struct pe_world_t *world, int tile_size);
void player_draw(player_t *player, sfRenderWindow *wind);
void player_draw_texture(player_t *player, sfRenderTexture *texture);
void player_handle_input(player_t *player, sfEvent event);
void player_update(player_t *player, float dt);
void player_destroy(player_t *player);
void player_respawn(player_t *player);

void player_update_anim_rect(player_t *player);
void player_set_animation(player_t *player, int anim);
void player_update_animation(player_t *player, float dt);

void player_kill(player_t *player, int from);
void player_land(player_t *player, \
struct pe_manifold_t *contact, struct pe_fixture_t *other);
void player_collect_snowflake(player_t *player, struct pe_fixture_t *flake);

#endif /* !PLAYER_H */