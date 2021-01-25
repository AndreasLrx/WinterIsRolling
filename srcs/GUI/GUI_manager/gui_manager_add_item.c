/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GUI - gui manager add item
*/

#include "GUI/gui_head.h"

void gui_manager_add_item(gui_manager_t *manager\
, size_t (*item_init)(gui_item_t *, size_t), size_t datas, int tag)
{
    gui_item_t *item = init_gui(item_init, datas);

    item->tag = tag;
    my_vector_push((size_t **)&manager->items, (size_t)item);
}