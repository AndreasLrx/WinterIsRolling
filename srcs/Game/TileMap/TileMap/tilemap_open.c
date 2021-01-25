/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** tilemap load from file
*/

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include "Game/TileMap/tilemap_head.h"
#include "My/my_convert.h"
#include "My/my_display.h"

static int read_infos(tilemap_t *map, char *buff, \
size_t *buff_size, FILE *file)
{
    size_t i = 0;
    size_t len_read = getline(&buff, buff_size, file);
    sfVector2u new_size;

    map->nb_layers = my_get_number_adv(buff, NULL, 0, 1);
    if (len_read <= 0)
        return 0;
    len_read = getline(&buff, buff_size, file);
    new_size.x = my_get_number_pass(buff, &i);
    new_size.y = my_get_number_pass(buff, &i);
    if (len_read <= 0)
        return 0;
    len_read = getline(&buff, buff_size, file);
    tilemap_resize(map, new_size, 1);
    map->size = new_size;
    return (len_read > 0);
}

static int read_pos(tilemap_t *map, char *buff, config_t *cfg)
{
    int pos = 0;
    int value = 0;
    int i = 0;

    while (buff[i] != '~' && buff[i]) {
        pos = (pos * 92) + buff[i] - '!';
        i++;
    }
    for (int lyr = 0; lyr < map->nb_layers; lyr++) {
        i += (buff[i] != 0);
        value = 0;
        while (buff[i] != '~' && buff[i] && buff[i] != ' ') {
            value *= 92;
            value += buff[i] - '!';
            i++;
        }
        if (value)
            tilemap_change_tile(map, (sfVector2i){lyr, pos}, \
            cfg->tilesets[M_SET(value)], value);
    }
    return i + 1;
}

static void read_pos_loop(tilemap_t *map, char *buff, config_t *cfg)
{
    int i = 0;

    while (buff[i]) {
        i += read_pos(map, buff + i, cfg);
    }
}

static void end_open(tilemap_t *map, sfVector2u size, char *buff, FILE *file)
{
    free(buff);
    fclose(file);
    if (map->size.x <= size.x && map->size.y <= size.y)
        map->size = size;
}

void tilemap_open(tilemap_t *map, char const *file_name, config_t *cfg)
{
    FILE *file = fopen(file_name, "r");
    char *buff = NULL;
    size_t buff_size = 0;
    size_t len_read = 0;
    sfVector2u size = map->size;

    if (file == NULL) {
        my_putstr_err("Can't read map\n");
        return;
    }
    if (!read_infos(map, buff, &buff_size, file)) {
        my_putstr_err("Can't read map\n");
        free(buff);
        fclose(file);
        return;
    }
    len_read = getline(&buff, &buff_size, file);
    if (len_read)
        read_pos_loop(map, buff, cfg);
    end_open(map, size, buff, file);
}