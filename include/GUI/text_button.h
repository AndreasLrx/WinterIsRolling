/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** gui - text_button
*/

#ifndef TEXT_BUTTON_H
#define TEXT_BUTTON_H

#include <stddef.h>
#include <SFML/Graphics.h>

enum TEXT_ALIGN {CUSTOM, TOP_LEFT, CENTER};

struct gui_item_t;

struct text_button_infos_t {
    struct button_infos_t *btn_infos;
    sfVector2f pos_text;
    unsigned int char_size;
    sfFont *font;
    sfColor *fill_colors;
    sfColor *out_colors;
    int out_thickness;
    int text_align;
    int text_update_type;
    wchar_t *str;
};

typedef struct text_button_t {
    int *state;
    struct button_t *btn;
    sfText *text;
    struct text_button_infos_t *infos;
    struct gui_item_t *gui_item;
} text_button_t;

size_t text_button_init(struct gui_item_t *base, size_t datas);
struct gui_output *text_button_handle_input(size_t field_adr, size_t event);
struct gui_output *text_button_update(size_t field_adr, float dt, size_t datas);
struct gui_output *text_button_draw(size_t field_adr, sfRenderWindow *window);
struct gui_output *text_button_draw_texture(size_t btn_adr, \
sfRenderTexture *texture);
struct gui_output *text_button_destroy(size_t *field_adr);

int is_text_btn_clicked(text_button_t *btn);

#endif /* !TEXT_BUTTON_H */