/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GUi manager - draw
*/

#include "GUI/gui_head.h"

int guis_draw(gui_manager_t *manager, sfRenderWindow *window)
{
    size_t nb_items = my_vector_get_size((size_t *)manager->items);
    struct gui_output *out = NULL;

    my_vector_clear((size_t *)manager->outputs, 1);
    for (size_t i = 0; i < nb_items; i++){
        out = manager->items[i]->draw(manager->items[i]->item, window);
        if (out != NULL)
            my_vector_push((size_t **)&manager->outputs, (size_t)out);
    }
    return 0;
}

int guis_draw_texture(gui_manager_t *manager, sfRenderTexture *texture)
{
    size_t nb_items = my_vector_get_size((size_t *)manager->items);
    struct gui_output *out = NULL;

    my_vector_clear((size_t *)manager->outputs, 1);
    for (size_t i = 0; i < nb_items; i++){
        out = manager->items[i]->draw_texture(manager->items[i]->item, texture);
        if (out != NULL)
            my_vector_push((size_t **)&manager->outputs, (size_t)out);
    }
    return 0;
}