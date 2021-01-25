/*
** EPITECH PROJECT, 2021
** My runner
** File description:
** stats file creation
*/

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "Stats/stats.h"
#include "global_cst.h"
#include "My/my_memory.h"
#include "My/my_convert.h"
#include "My/my_display.h"

static FILE *open_stats(void);

static FILE *create_stats(void)
{
    FILE *stats_file = fopen("./datas/stats.data", "w");

    if (stats_file == NULL){
        my_putstr_err("Can't create stats file\n");
        return NULL;
    }
    if (1 != fwrite("0|0|0|0|0\n", 10, 1, stats_file)){
        my_putstr_err("Can't write in stats file\n");
        fclose(stats_file);
        return NULL;
    }
    for (int i = 0; i < NB_MAP; i++) {
        if (1 != fwrite("0|0|0|0\n", 8, 1, stats_file)){
            my_putstr_err("Can't write in stats file\n");
            fclose(stats_file);
            return NULL;
        }
    }
    fclose(stats_file);
    return open_stats();
}

static FILE *open_stats(void)
{
    FILE *stats_file = fopen("./datas/stats.data", "r");

    if (stats_file == NULL)
        stats_file = create_stats();
    return stats_file;
}

static int try_read(size_t *len, FILE **file, char *buffer)
{
    *len = fread(buffer, 1, 1024, *file);
    if (*len <= 0){
        fclose(*file);
        *file = create_stats();
        if (file != NULL)
            *len = fread(buffer, 1, 1024, *file);
    }
    if (*len <= 0){
        my_putstr_err("Error reading stats file\n");
        fclose(*file);
    }
    return (*len > 0);
}

static void read_levels(global_stats_t *stats, char *buffer, size_t *index)
{
    stats->levels = my_calloc(sizeof(level_stats_t) * NB_MAP, 0);

    for (int i = 0; i < NB_MAP; i++) {
        stats->levels[i].highest_percent = my_get_number_pass(buffer, index);
        stats->levels[i].highest_score = my_get_number_pass(buffer, index);
        stats->levels[i].nb_played = my_get_number_pass(buffer, index);
        stats->levels[i].nb_success = my_get_number_pass(buffer, index);
    }
}

global_stats_t *global_stats_init(void)
{
    FILE *file = open_stats();
    global_stats_t *stats;
    char buffer[1025] = {0};
    size_t len;
    size_t i = 0;

    if (file == NULL || try_read(&len, &file, buffer) != 1)
        return NULL;
    stats = malloc(sizeof(global_stats_t));
    stats->snowflakes_gathered = my_get_number_pass(buffer, &i);
    stats->total_time = my_get_number_pass(buffer, &i);
    stats->nb_jumps = my_get_number_pass(buffer, &i);
    stats->distance_rolled = my_get_number_pass(buffer, &i);
    stats->lvl_played = my_get_number_pass(buffer, &i);
    read_levels(stats, buffer, &i);
    return stats;
}