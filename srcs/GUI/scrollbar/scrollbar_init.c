/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GUI - scrollbar init
*/

#include <stdio.h>
#include "GUI/gui_head.h"

static void apply_scrollbar_infos(scrollbar_t *scrollbar)
{
    for (int i = 0; i < scrollbar->infos->fill + 1; i++) {
        scrollbar->bar_rects[i] = sfRectangleShape_create();
        sfRectangleShape_setPosition(scrollbar->bar_rects[i], \
        scrollbar->infos->pos);
        sfRectangleShape_setFillColor(scrollbar->bar_rects[i], \
        scrollbar->infos->fill_colors[i]);
        sfRectangleShape_setSize(scrollbar->bar_rects[i], \
        scrollbar->infos->bar_size);
        if (i != 0)
            return;
        if (scrollbar->infos->update_type & GUI_OUTCOLORED){
            sfRectangleShape_setOutlineColor(scrollbar->bar_rects[i], \
            scrollbar->infos->out_colors[0]);
            sfRectangleShape_setOutlineThickness(scrollbar->bar_rects[i], \
            scrollbar->infos->out_thickness);
        }
    }
}

static void cursor_infos_set_update_type(struct \
scrollbar_infos_t *infos, struct button_infos_t *c_infos)
{
    c_infos->update_type = infos->update_type;
    c_infos->nb_states = infos->nb_states;
    if (infos->update_type && GUI_COLORED)
        c_infos->fill_colors = infos->fill_colors + 1 + infos->fill;
    if (infos->update_type && GUI_OUTCOLORED){
        c_infos->out_colors = infos->out_colors + 1;
        c_infos->out_thickness = infos->out_thickness;
    }
    if (infos->update_type && (GUI_TEXTURED | GUI_TEXTURED_RECT))
        c_infos->textures = infos->textures;
    if (infos->update_type && GUI_TEXTURED_RECT)
        c_infos->text_rects = infos->text_rects;
}

static button_t *create_cursor(struct scrollbar_infos_t *infos)
{
    struct button_infos_t *c_infos = malloc(sizeof(struct button_infos_t));

    if (infos->vertical){
        c_infos->pos = (sfVector2f){infos->pos.x - (infos->cursor_size.x - \
            infos->bar_size.x) / 2.f, infos->pos.y + infos->bar_size.y * \
            infos->min_max_cursor_pos.x};
    } else {
        c_infos->pos = (sfVector2f){infos->pos.x + infos->bar_size.x * \
            infos->min_max_cursor_pos.x, \
            infos->pos.y - (infos->cursor_size.y - infos->bar_size.y) / 2.f, };
    }
    c_infos->size = infos->cursor_size;
    c_infos->audio = NULL;
    cursor_infos_set_update_type(infos, c_infos);
    return (button_t *)button_init(NULL, (size_t)c_infos);
}

struct scrollbar_infos_t *init_scrollbar_infos(void)
{
    struct scrollbar_infos_t *infos = malloc(sizeof(struct scrollbar_infos_t));

    infos->pos = (sfVector2f){0, 0};
    infos->bar_size = (sfVector2f){10, 200};
    infos->cursor_size = (sfVector2f){20, 20};
    infos->min_len = (sfVector2f){0, 100};
    infos->min_max_cursor_pos = (sfVector2f){0.1, 0.9};
    infos->update_type = GUI_COLORED;
    infos->fill_colors = malloc(sizeof(sfColor) * 4);
    infos->fill_colors[0] = sfRed;
    infos->fill_colors[1] = sfWhite;
    infos->fill_colors[2] = sfCyan;
    infos->fill_colors[3] = sfBlue;
    infos->nb_states = 3;
    infos->vertical = 1;
    infos->fill = 0;
    return infos;
}

size_t scrollbar_init(gui_item_t *base, size_t datas)
{
    scrollbar_t *scrollbar = malloc(sizeof(scrollbar_t));

    scrollbar->infos = (struct scrollbar_infos_t *)datas;
    if (datas == 0)
        scrollbar->infos = init_scrollbar_infos();
    scrollbar->value = scrollbar->infos->min_len.x;
    scrollbar->bar_rects = malloc(sizeof(sfRectangleShape *) * \
    (1 + scrollbar->infos->fill));
    scrollbar->cursor = create_cursor(scrollbar->infos);
    scrollbar->state = &scrollbar->cursor->state;
    apply_scrollbar_infos(scrollbar);
    base->item = (size_t)scrollbar;
    base->handle_inputs = &scrollbar_handle_input;
    base->update = &scrollbar_update;
    base->draw = &scrollbar_draw;
    base->draw_texture = &scrollbar_draw_texture;
    base->destroy = &scrollbar_destroy;
    scrollbar->gui_item = base;
    scrollbar_update_fill(scrollbar);
    return (size_t)scrollbar;
}