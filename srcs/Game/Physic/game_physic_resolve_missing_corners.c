/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** game physics - resolve tile missing corners
*/

#include "Game/game_struct.h"

static pe_vec2f_t browse_axis_from_axis(sfImage *image, \
pe_vec2f_t start_point, int axis, int tile_size)
{
    pe_vec2f_t pos[2];
    int px;

    for (int i = 0; i < tile_size; i++) {
        pos[0] = (pe_vec2f_t){start_point.x + (axis % 2) * \
            (i + 1) * ((axis == 3) ? 1 : -1), \
            start_point.y + (!(axis % 2)) * (i + 1) * ((axis == 2) ? -1 : 1)};
        px = sfColor_toInteger(sfImage_getPixel(image, pos[0].x, pos[0].y));
        if (i == 0 && px == 0)
            return VEC2F(-1, -1);
        if (px == 0)
            break;
        pos[1] = pos[0];
    }
    return pos[1];
}

static pe_vec2f_t browse_axis_from_point(sfImage *image, \
pe_vec2i_t missing_way, pe_vec2f_t tile_pos, int tile_size)
{
    int missing = missing_way.x;
    int way = missing_way.y;
    pe_vec2f_t pos[2];
    int px;
    int from = (way == 0) ? ((missing == 0) ? 3 : missing - 1) : \
    ((missing + 1) % 4);

    for (int i = 0; i < tile_size; i++) {
        pos[0] = (pe_vec2f_t){tile_pos.x + (tile_size * (from == 1 || \
            from == 2)) + ((((way) ? from : missing) % 2) * (i + 1) * \
            ((missing == (1 + way)) ? 1 : -1)), tile_pos.y + \
            (tile_size * (from > 1)) + ((((way) ? missing : from) % 2) * \
            (i + 1) * ((missing == (2 + way)) ? 1 : -1))};
        px = sfColor_toInteger(sfImage_getPixel(image, pos[0].x, pos[0].y));
        if (i == 0 && px == 0)
            return VEC2F(-1, -1);
        if (px == 0)
            break;
        pos[1] = pos[0];
    }
    return pos[1];
}

int resolve_two_missing(pe_vec2f_t *vertices, sfImage *image, \
int tile_size, pe_vec2f_t tile_pos)
{
    int axis = ((vertices[0].x != -1 && vertices[1].x != -1) ? 0 : \
    ((vertices[1].x != -1 && vertices[2].x != -1) ? 1 : \
    ((vertices[2].x != -1 && vertices[3].x != -1) ? 2 : 3)));
    int new_v[2] = {(axis > 0) ? axis - 1 : 3, \
        (axis + 2) % 4};
    pe_vec2f_t start_point = {tile_pos.x + (axis == 2 || axis == 1) * \
        tile_size, tile_pos.y + (axis > 1) * tile_size};

    vertices[new_v[0]] = browse_axis_from_axis(image, start_point, \
    axis, tile_size);
    start_point = (pe_vec2f_t){tile_pos.x + (axis < 2) * \
        tile_size, tile_pos.y + (axis == 1 || axis == 2) * tile_size};
    vertices[new_v[1]] = browse_axis_from_axis(image, start_point, \
    axis, tile_size);
    if (vertices[new_v[1]].x >= 0)
        vertices[new_v[1]] = VEC2F_DIV1(VEC2F_SUB(vertices[new_v[1]], \
        tile_pos), tile_size);
    if (vertices[new_v[0]].x >= 0)
        vertices[new_v[0]] = VEC2F_DIV1(VEC2F_SUB(vertices[new_v[0]], \
        tile_pos), tile_size);
    return (vertices[new_v[0]].x < 0 || vertices[new_v[1]].x < 0);
}

static pe_vec2f_t get_closest(pe_vec2f_t v1, pe_vec2f_t v2, int missing)
{
    pe_vec2f_t goal = {(missing == 1 || missing == 3) ? 1 : 0, \
        (missing < 2) ? 0 : 1};
    float dist1 = pe_vec2f_length_squared(VEC2F_SUB(v1, goal));
    float dist2 = pe_vec2f_length_squared(VEC2F_SUB(v2, goal));

    return (dist1 < dist2) ? v1 : v2;
}

int resolve_one_missing(pe_vec2f_t *vertices, sfImage *image, \
int tile_size, pe_vec2f_t tile_pos)
{
    int missing = ((vertices[0].x == -1) ? 0 : ((vertices[1].x == -1) ? \
1 : ((vertices[2].x == -1) ? 2 : 3)));
    pe_vec2f_t found = {-1, -1};

    found = browse_axis_from_point(image, (pe_vec2i_t){missing, 0}, \
    tile_pos, tile_size);
    vertices[missing] = browse_axis_from_point(image, \
    (pe_vec2i_t){missing, 1}, tile_pos, tile_size);
    if (found.x < 0 && vertices[missing].x < 0)
        return 1;
    else {
        vertices[missing] = VEC2F_DIV1(VEC2F_SUB(vertices[missing], \
        tile_pos), tile_size);
        found = VEC2F_DIV1(VEC2F_SUB(found, tile_pos), tile_size);
        if (vertices[missing].x < 0)
            vertices[missing] = found;
        else
            vertices[missing] = get_closest(found, vertices[missing], missing);
    }
    return 0;
}