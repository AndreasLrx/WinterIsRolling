/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GUI - Textfield destroy
*/

#include "GUI/gui_head.h"

struct gui_output *textfield_destroy(size_t *data)
{
    textfield_t *field = (textfield_t *)(*data);

    free(field->infos);
    my_vector_free((size_t **)&field->str);
    sfText_destroy(field->text);
    free(field);
    *data = 0;
    return NULL;
}