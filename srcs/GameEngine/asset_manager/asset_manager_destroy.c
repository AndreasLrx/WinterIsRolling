/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Game Engine - destroy asset manager
*/

#include <GameEngine/game_head.h>

void asset_manager_destroy(asset_manager_t **assets_adr)
{
    asset_manager_t *assets = *assets_adr;
    size_t nb_fonts = my_map_size(assets->fonts);
    size_t nb_textures = my_map_size(assets->textures);
    size_t nb_shaders = my_map_size(assets->shaders);

    for (size_t i = 0; i < nb_shaders; i++)
        sfShader_destroy(((asset_t *)my_map_at(assets->shaders, i))->shader);
    for (size_t i = 0; i < nb_fonts; i++)
        sfFont_destroy(((asset_t *)my_map_at(assets->fonts, i))->font);
    for (size_t i = 0; i < nb_textures; i++)
        sfTexture_destroy(((asset_t *)my_map_at(assets->textures, i))->texture);
    my_map_free(&assets->fonts);
    my_map_free(&assets->textures);
    my_map_free(&assets->shaders);
    free(assets);
    *assets_adr = NULL;
}