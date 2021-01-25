/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** gui - button
*/

#ifndef BUTTON_H
#define BUTTON_H

#include <stddef.h>
#include <SFML/Graphics.h>

struct gui_item_t;

struct button_infos_t {
    sfVector2f pos;
    sfVector2f size;
    sfTexture **textures;
    sfColor *fill_colors;
    sfColor *out_colors;
    sfIntRect *text_rects;
    int out_thickness;
    int nb_states;
    int update_type;
    char *click_sound;
    audio_manager_t *audio;
};

typedef struct button_t {
    int state;
    struct sfRectangleShape **rect;
    struct button_infos_t *infos;
    struct gui_item_t *gui_item;
} button_t;

size_t button_init(struct gui_item_t *base, size_t datas);
struct gui_output *button_handle_input(size_t field_adr, size_t event);
struct gui_output *button_update(size_t field_adr, float dt, size_t datas);
struct gui_output *button_draw(size_t field_adr, sfRenderWindow *window);
struct gui_output *button_draw_texture(size_t btn_adr, \
sfRenderTexture *texture);
struct gui_output *button_destroy(size_t *field_adr);

int is_btn_clicked(button_t *btn);

#endif /* !BUTTON_H */