/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** functions
*/

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stddef.h>
#include <SFML/Graphics.h>

struct state_t;

#define ABS(a) (((a) >= 0) ? (a) : (-(a)))
#ifndef MAX
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#endif
#ifndef MIN
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#endif
#define BTWN(a, min, max) (MIN(MAX((min), (a)), (max)))

int my_map_strcmp(size_t s1, size_t s2);
int my_map_intcmp(size_t s1, size_t s2);
int my_map_charcmp(size_t s1, size_t s2);

int is_in_bounds_i(sfVector2i pos, sfVector2i item_pos, \
sfVector2i item_size, int strict);
int is_in_bounds(sfVector2f pos, sfVector2f item_pos, sfVector2f item_size);
int is_in_rect(sfVector2f pos, sfFloatRect rect);

struct button_infos_t *init_iced_btn(struct state_t *state, \
int id_button, sfVector2f pos);
struct text_button_infos_t *init_iced_text_btn(struct state_t *state, \
sfVector2f pos, wchar_t *str);

#endif /* !FUNCTIONS_H */