/*
** EPITECH PROJECT, 2020
** GameEngine
** File description:
** asset manager functions
*/

#include "GameEngine/game_head.h"
#include "functions.h"

void load_shader(asset_manager_t *asset_manager, char const *name, \
char const *filepath)
{
    asset_t *elmt = (asset_t *)my_map_find(asset_manager->shaders, \
    (size_t)name);
    sfShader *shader;
    asset_t *asset;

    if (elmt != 0){
        return;
    }
    shader = sfShader_createFromFile(NULL, NULL, filepath);
    if (shader == NULL)
        return;
    sfShader_setFloatUniform(shader, "sigma", 5);
    sfShader_setCurrentTextureUniform(shader, "tex");
    asset = malloc(sizeof(asset_t));
    asset->shader = shader;
    my_map_insert(asset_manager->shaders, (size_t)name, (size_t)asset);
}

sfShader *get_shader(asset_manager_t *asset_manager, char const *name)
{
    asset_t *elmt = (asset_t *)my_map_find(asset_manager->shaders, \
    (size_t)name);

    if (elmt == NULL)
        return NULL;
    return elmt->shader;
}