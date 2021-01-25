/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GUI - click text init
*/

#include <stdio.h>
#include "GUI/gui_head.h"

static void apply_text_infos(click_text_t *text)
{
    sfText_setCharacterSize(text->texte, text->infos->character_size);
    sfText_setPosition(text->texte, text->infos->pos);
    sfText_setFillColor(text->texte, sfWhite);
    sfText_setUnicodeString(text->texte, (sfUint32 *)text->infos->text);
    sfText_setFont(text->texte, text->infos->font);
    if (text->infos->update_type & GUI_COLORED)
        sfText_setFillColor(text->texte, text->infos->fill_colors[0]);
    if (text->infos->update_type & GUI_OUTCOLORED){
        sfText_setOutlineColor(text->texte, text->infos->out_colors[0]);
        sfText_setOutlineThickness(text->texte, text->infos->out_thickness);
    }
}

static struct click_text_infos_t *init_click_text_infos(void)
{
    struct click_text_infos_t *infos = \
    malloc(sizeof(struct click_text_infos_t));

    infos->font = NULL;
    infos->text = L"Click here";
    infos->pos = (sfVector2f){0, 0};
    infos->character_size = 15;
    infos->update_type = GUI_COLORED;
    infos->fill_colors = malloc(sizeof(sfColor) * 3);
    infos->fill_colors[0] = sfWhite;
    infos->fill_colors[1] = sfCyan;
    infos->fill_colors[2] = sfBlue;
    infos->nb_states = 3;
    infos->click_sound = NULL;
    infos->audio = NULL;
    return infos;
}

size_t click_text_init(gui_item_t *base, size_t datas)
{
    click_text_t *text = malloc(sizeof(click_text_t));

    text->state = GUI_NORMAL;
    text->infos = (struct click_text_infos_t *)datas;
    if (datas == 0)
        text->infos = init_click_text_infos();
    text->texte = sfText_create();
    apply_text_infos(text);
    base->item = (size_t)text;
    base->handle_inputs = &click_text_handle_input;
    base->update = &click_text_update;
    base->draw = &click_text_draw;
    base->draw_texture = &click_text_draw_texture;
    base->destroy = &click_text_destroy;
    text->gui_item = base;
    return (size_t)text;
}