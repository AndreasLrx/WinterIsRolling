/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Game structure
*/

#ifndef GAME_STRUCT_H
#define GAME_STRUCT_H

#include "Stats/stats.h"
#include "Drawables/background.h"
#include "GameEngine/game_head.h"
#include "Game/TileMap/tilemap_head.h"
#include "Game/Player/player.h"
#include "Physics/physics.h"

enum TILES_TYPES {PLAYER, GROUND, SNOWFLAKE, WATER, SPIKE, ICE};

typedef struct game_t {
    struct background_t *background;
    struct game_stats_t stats;
    struct global_stats_t *global_stats;
    struct state_t *state;
    struct config_t *cfg;
    struct tilemap_t *map;
    player_t *player;
    struct pe_world_t *world;
} game_t;

game_t *game_struct_init(state_t *state, int level_id);
void game_struct_update(game_t *game, float dt);
void game_struct_draw(game_t *game, sfRenderWindow *window);
void game_struct_handle_input(game_t *game, sfEvent event);
void game_struct_draw_texture(game_t *game, sfRenderTexture *texture);
void game_struct_destroy(game_t **game_adr);

void game_struct_restart(game_t *game);

void game_load_world(pe_world_t *world, tilemap_t *map, config_t *cfg);
int game_struct_get_tile_type(int tile_value);

#endif /* !GAME_STRUCT_H */