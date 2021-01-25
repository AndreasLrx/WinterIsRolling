/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GUI - gui manager init
*/

#include "GUI/gui_head.h"

gui_manager_t *init_gui_manager(void)
{
    gui_manager_t *manager = malloc(sizeof(gui_manager_t));

    manager->data_map = my_map_init(sizeof(int), sizeof(size_t), \
    &my_map_intcmp, 0);
    manager->items = (gui_item_t **)my_vector_init(sizeof(gui_item_t *), 5);
    manager->outputs = \
    (struct gui_output **)my_vector_init(sizeof(struct gui_output *), 5);
    return manager;
}