/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Tileset
*/

#ifndef TILESET_H
#define TILESET_H

#include <SFML/Graphics.h>

#define T_X(tile, set) (((tile) % (set)->size.x) * (set)->tile_size)
#define T_Y(tile, set) (((tile) / (set)->size.x) * (set)->tile_size)

typedef struct tileset_t {
    char *name;
    float scale;
    int tile_size;
    sfVector2i size;
    sfTexture *texture;
} tileset_t;

tileset_t *tileset_init(config_t *cfg, char *buffer, size_t *i);
void tileset_destroy(tileset_t *set);

#endif /* !TILESET_H */