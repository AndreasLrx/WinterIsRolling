/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - body destroy
*/

#include "Physics/physics.h"

static void remove_contacts(pe_body_t *body)
{
    size_t nb_contacts = my_vector_get_size((size_t *)body->contacts);
    pe_body_t *other;

    for (size_t i = 0; i < nb_contacts; i++) {
        other = (body->contacts[i]->af->body == body) ? \
    body->contacts[i]->bf->body : body->contacts[i]->af->body;
        pe_body_remove_contact(other, body->contacts[i]);
    }
}

void pe_body_destroy(pe_body_t *body)
{
    size_t nb_fixtures = my_vector_get_size((size_t *)body->fixtures);

    remove_contacts(body);
    for (size_t i = 0; i < nb_fixtures; i++)
        pe_fixture_destroy(body->fixtures[i]);
    my_vector_free((size_t **)&body->fixtures);
    my_vector_free((size_t **)&body->contacts);
    free(body);
}