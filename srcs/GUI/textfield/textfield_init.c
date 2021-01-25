/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GUI - Textfield init
*/

#include "GUI/gui_head.h"
#include "My/my_strings.h"

void textfield_setstr(textfield_t *field, sfUint32 *str)
{
    int str_size = my_wstrlen((wchar_t *)str);
    size_t field_size = my_vector_get_size((size_t *)field->str);

    if ((int)field_size < str_size)
        my_vector_grow((size_t **)&field->str, (size_t)(str_size + 1));
    my_wstrncpy((wchar_t *)field->str, (wchar_t *)str, \
    MAX(str_size + 1, field_size));
    my_vector_set_size((size_t *)field->str, (size_t)(str_size + 1));
    update_text(field);
}

static void apply_textfield_infos(textfield_t *field)
{
    if (field->infos->font != NULL)
        sfText_setFont(field->text, field->infos->font);
    sfText_setColor(field->text, field->infos->color);
    sfText_setCharacterSize(field->text, field->infos->char_size);
    sfText_setPosition(field->text, field->infos->pos);
    if (field->infos->str != NULL){
        textfield_setstr(field, field->infos->str);
        field->infos->str = NULL;
    }
}

struct textfield_infos_t *init_textfield_infos(void)
{
    struct textfield_infos_t *infos = malloc(sizeof(struct textfield_infos_t));

    infos->font = NULL;
    infos->pos = (sfVector2f){0, 0};
    infos->size = (sfVector2f){200, 50};
    infos->str = NULL;
    infos->color = sfWhite;
    infos->char_size = 13;
    infos->is_ascii = 0;
    infos->whitelist = NULL;
    infos->audio = NULL;
    infos->select_sound = NULL;
    return infos;
}

size_t textfield_init(gui_item_t *base, size_t datas)
{
    textfield_t *field = malloc(sizeof(textfield_t));

    field->infos = (struct textfield_infos_t *)datas;
    field->text = sfText_create();
    field->str = (sfUint32 *)my_vector_init(sizeof(sfUint32), 1);
    if (datas == 0)
        field->infos = init_textfield_infos();
    apply_textfield_infos(field);
    base->item = (size_t)field;
    base->handle_inputs = &textfield_handle_input;
    base->update = &textfield_update;
    base->draw = &textfield_draw;
    base->draw_texture = &textfield_draw_texture;
    base->destroy = &textfield_destroy;
    field->gui_item = base;
    return (size_t)field;
}