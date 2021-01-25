/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Game Stats
*/

#ifndef STATS_H
#define STATS_H

typedef struct game_stats_t {
    float time;
    float score;
    int snowflakes;
    int level_id;
} game_stats_t;

typedef struct level_stats_t {
    int nb_played;
    int nb_success;
    int highest_percent;
    int highest_score;
} level_stats_t;

typedef struct global_stats_t {
    int snowflakes_gathered;
    int total_time;
    int nb_jumps;
    int distance_rolled;
    int lvl_played;
    level_stats_t *levels;
} global_stats_t;

global_stats_t *global_stats_init(void);
int global_stats_save(global_stats_t *stats);

#endif /* !STATS_H */