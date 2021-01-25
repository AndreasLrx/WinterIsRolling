/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - body add contact
*/

#include "Physics/physics.h"

void pe_body_clear_contacts(pe_body_t *body)
{
    size_t nb_contacts = my_vector_get_size((size_t *)body->contacts);
    int is_a;
    pe_body_t *other;

    for (size_t i = 0; i < nb_contacts; i++) {
        is_a = (body->contacts[i]->af->body == body);
        other = (is_a) ? body->contacts[i]->bf->body : \
        body->contacts[i]->af->body;
        if (other->body_type == STATIC || \
            my_vector_get_size((size_t *)other->contacts) != 0)
            free(body->contacts[i]);
    }
    my_vector_clear((size_t *)body->contacts, 0);
}

void pe_body_remove_contact(pe_body_t *body, pe_manifold_t *contact)
{
    size_t nb_contacts = my_vector_get_size((size_t *)body->contacts);

    for (size_t i = 0; i < nb_contacts; i++) {
        if (body->contacts[i] == contact) {
            free(contact);
            my_vector_erase((size_t *)body->contacts, i, 0);
            return;
        }
    }
}

void pe_body_add_contact(pe_body_t *body, pe_manifold_t *contact)
{
    my_vector_push((size_t **)&body->contacts, (size_t)contact);
}