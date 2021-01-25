/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GUI - gui manager destroy item
*/

#include "GUI/gui_head.h"

void gui_manager_destroy_item(gui_manager_t *manager, int item_pos)
{
    manager->items[item_pos]->destroy(&manager->items[item_pos]->item);

    free(manager->items[item_pos]);
    my_vector_erase((size_t *)manager->items, (size_t)item_pos, 0);
    my_map_erase_key(manager->data_map, (size_t)item_pos);
}