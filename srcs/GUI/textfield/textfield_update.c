/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GUI - textfield update
*/

#include "GUI/gui_head.h"

static int check_size(textfield_t *field)
{
    int updated = 0;

    if (sfText_getLocalBounds(field->text).width >= field->infos->size.x){
        my_vector_insert((size_t **)&field->str, \
        my_vector_get_size((size_t *)field->str) - 2, (size_t)10);
        sfText_setUnicodeString(field->text, field->str);
    }
    if (sfText_getLocalBounds(field->text).height >= field->infos->size.y){
        my_vector_erase((size_t *)field->str, \
        my_vector_get_size((size_t *)field->str) - 2, 0);
        my_vector_erase((size_t *)field->str, \
        my_vector_get_size((size_t *)field->str) - 2, 0);
        sfText_setUnicodeString(field->text, field->str);
    }
    return updated;
}

void update_text(textfield_t *field)
{
    sfText_setUnicodeString(field->text, field->str);
    check_size(field);
}

struct gui_output *textfield_update(size_t field, float dt, size_t datas)
{
    return NULL;
}