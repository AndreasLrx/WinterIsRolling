/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Gui - textfield
*/

#ifndef TEXT_FIELD_H
#define TEXT_FIELD_H

#include <stddef.h>
#include <SFML/Graphics.h>

struct gui_item_t;

struct textfield_infos_t {
    int char_size;
    int is_ascii;
    wchar_t *whitelist;
    sfVector2f pos;
    sfVector2f size;
    sfFont *font;
    sfUint32 *str;
    sfColor color;
    char *select_sound;
    audio_manager_t *audio;
};

typedef struct textfield_t {
    sfUint32 *str;
    struct sfText *text;
    struct textfield_infos_t *infos;
    struct gui_item_t *gui_item;
} textfield_t;

size_t textfield_init(struct gui_item_t *base, size_t datas);
struct gui_output *textfield_handle_input(size_t field_adr, size_t event);
struct gui_output *textfield_update(size_t field_adr, float dt, size_t datas);
struct gui_output *textfield_draw(size_t field_adr, sfRenderWindow *window);
struct gui_output *textfield_draw_texture(size_t field_adr, \
sfRenderTexture *texture);
struct gui_output *textfield_destroy(size_t *field_adr);

void textfield_setstr(textfield_t *field, sfUint32 *str);
void update_text(textfield_t *field);

#endif /* !TEXT_FIELD_H */