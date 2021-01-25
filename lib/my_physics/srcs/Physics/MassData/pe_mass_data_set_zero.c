/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Physics - mass data set zero
*/

#include "Physics/MassData/mass_data.h"

void pe_mass_data_set_zero(pe_mass_data_t *data, int zero_center)
{
    if (zero_center)
        data->center = VEC2F(0, 0);
    data->mass = 0;
    data->inertia = 0;
    data->inv_inertia = 0;
    data->inv_mass = 0;
}