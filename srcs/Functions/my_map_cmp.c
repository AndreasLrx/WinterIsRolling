/*
** EPITECH PROJECT, 2020
** GameEngine
** File description:
** asset manager functions
*/

#include "functions.h"
#include "My/my_strings.h"

int my_map_strcmp(size_t s1, size_t s2)
{
    return (my_strcmp((const char *)s1, (const char *)s2) == 0);
}

int my_map_intcmp(size_t v1, size_t v2)
{
    for (int i = 0; i < sizeof(int); i++){
        if (*((char *)(&v1) + i) != *((char *)(&v2) + i))
            return 0;
    }
    return 1;
}

int my_map_charcmp(size_t v1, size_t v2)
{
    return (*((char *)(&v1)) == *((char *)(&v2)));
}