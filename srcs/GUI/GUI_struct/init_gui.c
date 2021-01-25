/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GUI - gui struct init
*/

#include "GUI/gui_head.h"

struct gui_output *make_gui_output(gui_item_t *item, size_t data)
{
    struct gui_output *out;

    if (item == NULL)
        return NULL;
    out = malloc(sizeof(struct gui_output));
    out->tag = item->tag;
    out->data = data;
    return out;
}

gui_item_t *init_gui(size_t (*item_init)(gui_item_t *, size_t), size_t datas)
{
    gui_item_t *item = malloc(sizeof(gui_item_t));

    (*item_init)(item, datas);
    item->selected = 0;
    item->enabled = 1;
    return item;
}