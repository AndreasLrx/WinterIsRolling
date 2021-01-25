/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Tileset init
*/

#include <stdlib.h>
#include "Game/TileMap/tilemap_head.h"
#include "My/my_strings.h"
#include "My/my_display.h"
#include "My/my_convert.h"

static char *get_full_path(char *buffer, config_t *cfg, \
size_t *i, tileset_t *set)
{
    int tile_name_len = my_strlen_to(buffer, ' ');
    int len = tile_name_len + my_strlen(cfg->set_dir) + 1;
    char *full_path = malloc(sizeof(char) * len);

    my_strncpy(full_path, cfg->set_dir, len);
    my_strncat(full_path, buffer, tile_name_len);
    set->name = my_strndup(buffer, tile_name_len);
    if (*i)
        (*i) += tile_name_len + 1;
    return full_path;
}

void tileset_destroy(tileset_t *set)
{
    if (set->texture != NULL)
        free(set->texture);
    if (set->name != NULL)
        free(set->name);
    free(set);
}

tileset_t *tileset_init(config_t *cfg, char *buffer, size_t *i)
{
    tileset_t *set = malloc(sizeof(tileset_t));
    char *full_path = get_full_path(buffer + *i, cfg, i, set);

    set->texture = sfTexture_createFromFile(full_path, NULL);
    if (set->texture == NULL) {
        my_putstr_err("Can't load tileset\n");
        free(full_path);
        tileset_destroy(set);
        return NULL;
    }
    set->tile_size = my_get_number_pass(buffer, i);
    set->scale = my_get_float_pass(buffer, i);
    set->size = (sfVector2i){\
        sfTexture_getSize(set->texture).x / set->tile_size, \
        sfTexture_getSize(set->texture).y / set->tile_size};
    free(full_path);
    return set;
}