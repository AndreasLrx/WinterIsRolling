/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** TileMap
*/

#ifndef TILEMAP_H
#define TILEMAP_H

#include <limits.h>
#include <SFML/Graphics.h>

#define M_VALUE(t, i) (((t + 1) << 16) + (i))
#define M_SET(value) (((value) >> 16) - 1)
#define M_TILE(value) ((value) & SHRT_MAX)
#define M_POS(px, py, map) ((px) + ((py) * (map->size.x)))
#define M_X(pos, map) ((pos) % (map->size.x))
#define M_Y(pos, map) ((pos) / (map->size.x))
#define M_ACTIVE_LAYER(map) ((map)->nb_layers / 2)

struct my_map_t;
struct tileset_t;
struct config_t;
struct player_t;

typedef struct tilemap_t {
    sfVector2u size;
    sfVector2f pos;
    sfVector2f view_size;
    float current_zoom;
    struct my_map_t **draw_map;
    int **map;
    sfView *view;
    int nb_layers;
    int tile_size;
    sfRenderWindow *window;
    struct player_t *player;
} tilemap_t;

tilemap_t *tilemap_init(sfIntRect pos, sfVector2u size, \
int tile_size, int nb_layers);
void tilemap_regen(tilemap_t *map);
void tilemap_draw(tilemap_t *map);
void tilemap_draw_texture(tilemap_t *map, sfRenderTexture *texture);
void tilemap_destroy(tilemap_t **map_adr);

void tilemap_place_tile(tilemap_t *map, sfVector2i pos, \
struct tileset_t *set, int tile);
void tilemap_change_tile(tilemap_t *map, sfVector2i pos, \
struct tileset_t *set, int tile_value);
void tilemap_remove_tile(tilemap_t *map, sfVector2i pos);

sfVector2i tilemap_pixel_to_tile(tilemap_t *map, sfVector2i pos);
void tilemap_zoom(tilemap_t *map, sfVector2i mouse_pos, float zoom);
void tilemap_move(tilemap_t *map, sfVector2f offset);
void tilemap_correct_pos(tilemap_t *map);

void tilemap_resize(tilemap_t *map, sfVector2u new_size, int only_up);

void tilemap_save(tilemap_t *map, char const *file_name);
void tilemap_open(tilemap_t *map, char const *file_name, struct config_t *cfg);

#endif /* !TILEMAP_H */