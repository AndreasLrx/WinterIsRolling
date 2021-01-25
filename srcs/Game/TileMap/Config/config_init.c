/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Tile map config
*/

#include <stdlib.h>
#include "Game/TileMap/tilemap_head.h"
#include "My/my_display.h"
#include "My/my_convert.h"
#include "My/my_memory.h"
#include "My/my_strings.h"

static int try_read(char *file_name, FILE **file, char *buffer)
{
    size_t len;

    *file = fopen(file_name, "r");
    if (!(*file)) {
        my_putstr_err("Can't open config\n");
        return 0;
    }
    len = fread(buffer, 1, 1024, *file);
    if (len <= 0){
        my_putstr_err("Error reading config file\n");
        fclose(*file);
    }
    return (len > 0);
}

static int get_save_dir(config_t *cfg, char *buffer, size_t *i)
{
    size_t index = *i;

    while (buffer[index] != ' ' && buffer[index])
        index++;
    if (buffer[index] != ' ')
        return 0;
    cfg->set_dir = my_strndup(buffer + *i, index - *i);
    (*i) = ++index;
    while (buffer[index] != '\n' && buffer[index])
        index++;
    if (buffer[index] != '\n')
        return 0;
    cfg->map_dir = my_strndup(buffer + *i, index - *i);
    (*i) = ++index;
    return 1;
}

static void init_sets(config_t *cfg, char *buffer, size_t *i)
{
    cfg->tilesets = malloc(sizeof(tileset_t *) * cfg->nb_sets);

    for (size_t j = 0; j < cfg->nb_sets; j++) {
        cfg->tilesets[j] = tileset_init(cfg, buffer, i);
    }
}

config_t *config_init(char *config_file_name)
{
    config_t *cfg = NULL;
    FILE *file;
    char buffer[1024 + 1] = {0};
    size_t i = 0;

    if (!try_read(config_file_name, &file, buffer))
        return NULL;
    cfg = my_calloc(sizeof(config_t), 0);
    cfg->nb_sets = my_get_number_pass(buffer, &i);
    if (!get_save_dir(cfg, buffer, &i)) {
        config_destroy(cfg);
        my_putstr_err("Invalid tilesets/map directories\n");
        return NULL;
    }
    cfg->tile_size = my_get_number_pass(buffer, &i);
    init_sets(cfg, buffer, &i);
    fclose(file);
    return cfg;
}