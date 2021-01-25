/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GUI - button init
*/

#include <stdio.h>
#include "GUI/gui_head.h"

static void apply_textures(button_t *button, int i)
{
    if (button->infos->update_type & GUI_TEXTURED_RECT){
        sfRectangleShape_setTexture(button->rect[i], \
        button->infos->textures[0], 1);
        sfRectangleShape_setTextureRect(button->rect[i], \
        button->infos->text_rects[i]);
    }
    if (button->infos->update_type & GUI_TEXTURED)
        sfRectangleShape_setTexture(button->rect[i], \
        button->infos->textures[i], 1);
}

static void apply_button_infos(button_t *button)
{
    for (int i = 0; i < button->infos->nb_states; i++){
        button->rect[i] = sfRectangleShape_create();
        sfRectangleShape_setSize(button->rect[i], button->infos->size);
        sfRectangleShape_setPosition(button->rect[i], button->infos->pos);
        if (button->infos->update_type & GUI_COLORED)
            sfRectangleShape_setFillColor(button->rect[i], \
            button->infos->fill_colors[i]);
        if (button->infos->update_type & GUI_OUTCOLORED){
            sfRectangleShape_setOutlineColor(button->rect[i], \
            button->infos->out_colors[i]);
            sfRectangleShape_setOutlineThickness(button->rect[i], \
            button->infos->out_thickness);
        }
        apply_textures(button, i);
    }
}

struct button_infos_t *init_button_infos(void)
{
    struct button_infos_t *infos = malloc(sizeof(struct button_infos_t));

    infos->pos = (sfVector2f){0, 0};
    infos->size = (sfVector2f){200, 50};
    infos->update_type = GUI_COLORED;
    infos->fill_colors = malloc(sizeof(sfColor) * 3);
    infos->fill_colors[0] = sfWhite;
    infos->fill_colors[1] = sfCyan;
    infos->fill_colors[2] = sfBlue;
    infos->nb_states = 3;
    infos->audio = NULL;
    infos->click_sound = NULL;
    return infos;
}

size_t button_init(gui_item_t *base, size_t datas)
{
    button_t *button = malloc(sizeof(button_t));

    button->state = GUI_NORMAL;
    button->infos = (struct button_infos_t *)datas;
    if (datas == 0)
        button->infos = init_button_infos();
    button->rect = malloc(sizeof(sfRectangleShape *) * \
    button->infos->nb_states);
    apply_button_infos(button);
    button->gui_item = base;
    if (base == NULL)
        return (size_t)button;
    base->item = (size_t)button;
    base->handle_inputs = &button_handle_input;
    base->update = &button_update;
    base->draw = &button_draw;
    base->draw_texture = &button_draw_texture;
    base->destroy = &button_destroy;
    return (size_t)button;
}