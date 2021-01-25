/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** game physics - get tile corners
*/

#include "Game/game_struct.h"

int fill_corners(pe_vec2f_t *vertices, sfImage *image, \
int tile_size, pe_vec2f_t tile_pos)
{
    int pixel;
    int v = 0;

    for (int x = 0; x < 2; x++) {
        pixel = sfColor_toInteger(sfImage_getPixel(image, \
        tile_pos.x + (x * tile_size), tile_pos.y));
        if (pixel) {
            v++;
            vertices[x] = VEC2F(x, 0);
        }
    }
    for (int x = 1; x >= 0; x--) {
        pixel = sfColor_toInteger(sfImage_getPixel(image, \
        tile_pos.x + (x * tile_size), tile_pos.y + tile_size));
        if (pixel) {
            v++;
            vertices[(1 - x) + 2] = VEC2F(x, 1);
        }
    }
    return v;
}