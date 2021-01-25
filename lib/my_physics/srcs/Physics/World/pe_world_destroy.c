/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - world destroy
*/

#include "Physics/physics.h"

#include <stdio.h>

void pe_world_destroy_body(pe_world_t *world, pe_body_t *body)
{
    size_t nb_body = my_vector_get_size((size_t *)world->bodies);

    for (size_t i = 0; i < nb_body; i++) {
        if (world->bodies[i] == body) {
            my_vector_erase((size_t *)world->bodies, i, 0);
            break;
        }
    }
    pe_bin_tree_remove_body(world->tree, body);
}

void pe_world_destroy(pe_world_t *world)
{
    my_vector_free((size_t **)&world->bodies);
    pe_bin_tree_destroy(world->tree);
    free(world);
}