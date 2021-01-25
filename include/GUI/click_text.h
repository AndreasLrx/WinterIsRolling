/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GUI Manager - clickable text (click_text)
*/

#ifndef CLICK_TEXT_H
#define CLICK_TEXT_H

#include <stddef.h>
#include <SFML/Graphics.h>
#include "./click_text.h"

struct gui_item_t;

struct click_text_infos_t {
    wchar_t const *text;
    sfFont *font;
    int character_size;
    sfVector2f pos;
    sfColor *fill_colors;
    sfColor *out_colors;
    int out_thickness;
    int nb_states;
    int update_type;
    char *click_sound;
    audio_manager_t *audio;
};

typedef struct click_text_t {
    int state;
    sfText *texte;
    struct click_text_infos_t *infos;
    struct gui_item_t *gui_item;
} click_text_t;

size_t click_text_init(struct gui_item_t *base, size_t datas);
struct gui_output *click_text_handle_input(size_t click_text_adr, size_t event);
struct gui_output *click_text_update(size_t click_text_adr, \
float dt, size_t datas);
struct gui_output *click_text_draw(size_t click_text_adr, \
sfRenderWindow *window);
struct gui_output *click_text_draw_texture(size_t click_text_adr, \
sfRenderTexture *texture);
struct gui_output *click_text_destroy(size_t *click_text_adr);

int is_text_clicked(click_text_t *text);

#endif /* !CLICK_TEXT_H */