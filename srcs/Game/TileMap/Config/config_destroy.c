/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Config destroy
*/

#include <stdlib.h>
#include "Game/TileMap/tilemap_head.h"

void config_destroy(config_t *cfg)
{
    if (cfg->map_dir)
        free(cfg->map_dir);
    if (cfg->set_dir)
        free(cfg->set_dir);
    if (cfg->tilesets) {
        for (int i = 0; i < cfg->nb_sets; i++)
            tileset_destroy(cfg->tilesets[i]);
        free(cfg->tilesets);
    }
    free(cfg);
}