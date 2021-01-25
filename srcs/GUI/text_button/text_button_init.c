/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GUI - text_button init
*/

#include <stdio.h>
#include "GUI/gui_head.h"

static void set_text_pos(text_button_t *btn)
{
    sfFloatRect bounds;
    sfFloatRect l_bounds;
    sfVector2f btn_pos;
    sfVector2f btn_size;

    if (btn->infos->text_align == CUSTOM) {
        sfText_setPosition(btn->text, btn->infos->pos_text);
    }
    if (btn->infos->text_align == TOP_LEFT) {
        sfText_setPosition(btn->text, btn->infos->btn_infos->pos);
    }
    if (btn->infos->text_align == CENTER) {
        bounds = sfText_getGlobalBounds(btn->text);
        l_bounds = sfText_getLocalBounds(btn->text);
        btn_pos = btn->infos->btn_infos->pos;
        btn_size = btn->infos->btn_infos->size;
        sfText_setPosition(btn->text, (sfVector2f){btn_pos.x + \
            (btn_size.x - bounds.width) / 2.f, \
            btn_pos.y + (btn_size.y - bounds.height) / 2.f - l_bounds.top});
    }
}

static void apply_text_button_infos(text_button_t *text_button)
{
    sfText_setCharacterSize(text_button->text, text_button->infos->char_size);
    sfText_setFont(text_button->text, text_button->infos->font);
    if (text_button->infos->text_update_type & GUI_COLORED)
        sfText_setFillColor(text_button->text, \
        text_button->infos->fill_colors[0]);
    if (text_button->infos->text_update_type & GUI_OUTCOLORED){
        sfText_setOutlineColor(text_button->text, \
        text_button->infos->out_colors[0]);
        sfText_setOutlineThickness(text_button->text, \
        text_button->infos->out_thickness);
    }
    sfText_setUnicodeString(text_button->text, \
    (sfUint32 *)text_button->infos->str);
    set_text_pos(text_button);
}

struct text_button_infos_t *init_text_button_infos(void)
{
    struct text_button_infos_t *infos = \
    malloc(sizeof(struct text_button_infos_t));

    infos->pos_text = (sfVector2f){0, 0};
    infos->char_size = 30;
    infos->font = NULL;
    infos->text_update_type = GUI_COLORED;
    infos->fill_colors = malloc(sizeof(sfColor) * 3);
    infos->fill_colors[0] = sfWhite;
    infos->fill_colors[1] = sfCyan;
    infos->fill_colors[2] = sfBlue;
    infos->text_align = CENTER;
    infos->btn_infos = NULL;
    return infos;
}

size_t text_button_init(gui_item_t *base, size_t datas)
{
    text_button_t *text_button = malloc(sizeof(text_button_t));

    text_button->infos = (struct text_button_infos_t *)datas;
    if (datas == 0)
        text_button->infos = init_text_button_infos();
    text_button->text = sfText_create();
    text_button->btn = (button_t *)button_init(NULL, \
    (size_t)text_button->infos->btn_infos);
    text_button->state = &text_button->btn->state;
    apply_text_button_infos(text_button);
    text_button->gui_item = base;
    if (base == NULL)
        return (size_t)text_button;
    base->item = (size_t)text_button;
    base->handle_inputs = &text_button_handle_input;
    base->update = &text_button_update;
    base->draw = &text_button_draw;
    base->draw_texture = &text_button_draw_texture;
    base->destroy = &text_button_destroy;
    return (size_t)text_button;
}