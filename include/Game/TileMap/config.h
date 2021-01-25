/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** tilesets config
*/

#ifndef TILE_CONFIG_H
#define TILE_CONFIG_H

#define NB_LAYERS 3

#include <SFML/Graphics.h>

enum TOOLS{PEN, ERASER, SELECT, MOVE, ZOOM};

struct tileset_t;
struct state_t;
struct tilemap_t;

typedef struct config_t {
    int nb_sets;
    int tile_size;
    char *set_dir;
    char *map_dir;
    struct tileset_t **tilesets;
} config_t;

config_t *config_init(char *config_file_name);
void config_display(config_t *cfg);
void config_destroy(config_t *cfg);

#endif /* !TILE_CONFIG_H */