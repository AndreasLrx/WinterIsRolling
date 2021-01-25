/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GUI - gui manager fcts
*/

#include "GUI/gui_head.h"

int guis_handle_input(gui_manager_t *manager, size_t event)
{
    size_t nb_items = my_vector_get_size((size_t *)manager->items);
    struct gui_output *out = NULL;
    struct gui_item_t *item;

    my_vector_clear((size_t *)manager->outputs, 1);
    for (size_t i = 0; i < nb_items; i++){
        item = manager->items[i];
        if (!item->enabled)
            continue;
        out = item->handle_inputs(item->item, event);
        if (out != NULL)
            my_vector_push((size_t **)&manager->outputs, (size_t)out);
    }
    return 0;
}

int guis_update(gui_manager_t *manager, float dt)
{
    size_t nb_items = my_vector_get_size((size_t *)manager->items);
    struct gui_output *out = NULL;
    struct gui_item_t *item;

    my_vector_clear((size_t *)manager->outputs, 1);
    for (size_t i = 0; i < nb_items; i++){
        item = manager->items[i];
        if (!item->enabled)
            continue;
        out = item->update(item->item, dt, \
        my_map_find(manager->data_map, i));
        if (out != NULL)
            my_vector_push((size_t **)&manager->outputs, (size_t)out);
    }
    return 0;
}

void gui_manager_destroy(gui_manager_t *manager)
{
    size_t nb_items = my_vector_get_size((size_t *)manager->items);

    for (size_t i = 0; i < nb_items; i++)
        manager->items[i]->destroy(&manager->items[i]->item);
    my_map_free(&manager->data_map);
    my_vector_free((size_t **)&manager->items);
    my_vector_clear((size_t *)manager->outputs, 1);
    my_vector_free((size_t **)&manager->outputs);
    free(manager);
}

size_t gui_manager_get_item(gui_manager_t *manager, int tag)
{
    size_t nb_items = my_vector_get_size((size_t *)manager->items);

    for (size_t i = 0; i < nb_items; i++){
        if (manager->items[i]->tag == tag)
            return manager->items[i]->item;
    }
    return 0;
}

void gui_manager_enable_item(gui_manager_t *manager, int tag, int enable)
{
    size_t nb_items = my_vector_get_size((size_t *)manager->items);

    for (size_t i = 0; i < nb_items; i++){
        if (manager->items[i]->tag == tag)
            manager->items[i]->enabled = enable;
    }
}