/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GUI - scrollbar
*/

#ifndef GUI_SCROLLBAR_H
#define GUI_SCROLLBAR_H

#include <stddef.h>
#include <SFML/Graphics.h>

struct gui_item_t;
struct button_t;

struct scrollbar_infos_t {
    sfVector2f pos;
    sfVector2f bar_size;
    sfVector2f cursor_size;
    sfVector2f min_len;
    sfVector2f min_max_cursor_pos;
    sfTexture **textures;
    sfIntRect *text_rects;
    sfColor *fill_colors;
    sfColor *out_colors;
    int out_thickness;
    int nb_states;
    int update_type;
    int vertical;
    int fill;
};

typedef struct scrollbar_t {
    int *state;
    float value;
    sfVector2f last_pos;
    struct button_t *cursor;
    struct sfRectangleShape **bar_rects;
    struct scrollbar_infos_t *infos;
    struct gui_item_t *gui_item;
} scrollbar_t;

size_t scrollbar_init(struct gui_item_t *base, size_t datas);
struct gui_output *scrollbar_handle_input(size_t bar_adr, size_t event);
struct gui_output *scrollbar_update(size_t bar_adr, float dt, size_t datas);
struct gui_output *scrollbar_draw(size_t bar_adr, sfRenderWindow *window);
struct gui_output *scrollbar_draw_texture(size_t bar_adr, \
sfRenderTexture *texture);
struct gui_output *scrollbar_destroy(size_t *bar_adr);

void scrollbar_set_value(scrollbar_t *bar, float value);
void scrollbar_update_fill(scrollbar_t *bar);

#endif /* !GUI_SCROLLBAR_H */