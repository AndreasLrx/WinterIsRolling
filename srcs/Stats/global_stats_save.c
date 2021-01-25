/*
** EPITECH PROJECT, 2021
** My runner
** File description:
** stats save
*/

#include "Stats/stats.h"
#include <fcntl.h>
#include "GameEngine/game_head.h"
#include "My/my_display.h"
#include "My/my_convert.h"
#include "My/my_strings.h"
#include "functions.h"

static int write_value(int value, FILE *file, char end_char)
{
    int size_str = my_number_len(value) + (end_char != 0);
    char *str = malloc(sizeof(char) * (size_str + 1));
    char *p = str;
    char *istr = my_itostr(value);
    int return_code;

    my_strnset(str, 0, size_str + 1);
    p = my_strcat(p, istr);
    free(istr);
    if (end_char != 0)
        str[size_str - 1] = end_char;
    return_code = fwrite(str, size_str, 1, file);
    free(str);
    return return_code;
}

static int write_stats(global_stats_t *stats, FILE *file)
{
    if (write_value(stats->snowflakes_gathered, file, '|') != 1 || \
    write_value(stats->total_time, file, '|') != 1 || \
    write_value(stats->nb_jumps, file, '|') != 1 || \
    write_value(stats->distance_rolled, file, '|') != 1 || \
    write_value(stats->lvl_played, file, '\n') != 1) {
        return -1;
    }
    for (int i = 0; i < NB_MAP; i++) {
        if (write_value(stats->levels[i].highest_percent, file, '|') != 1 || \
        write_value(stats->levels[i].highest_score, file, '|') != 1 || \
        write_value(stats->levels[i].nb_played, file, '|') != 1 || \
        write_value(stats->levels[i].nb_success, file, '\n') != 1) {
            return -1;
        }
    }
    return 0;
}

int global_stats_save(global_stats_t *stats)
{
    FILE *stats_file = fopen("./datas/stats.data", "w");

    if (stats_file == NULL){
        my_putstr_err("Can't create stats file\n");
        return 0;
    }
    if (write_stats(stats, stats_file) == -1){
        my_putstr_err("Error occured while saving stats\n");
        fclose(stats_file);
        return 0;
    }
    fclose(stats_file);
    return 1;
}