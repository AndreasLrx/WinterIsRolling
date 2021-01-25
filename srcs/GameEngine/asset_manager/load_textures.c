/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** load textures
*/

#include "GameEngine/game_head.h"

static void load_shaders(asset_manager_t *manager)
{
    load_shader(manager, "blur", "res/Shaders/gauss_blur.frag");
}

static void load_gui_textures(asset_manager_t *manager)
{
    load_texture(manager, "scroll_cursor_normal", \
    "res/Textures/GUI/snowflake_normal.png");
    load_texture(manager, "scroll_cursor_clicked", \
    "res/Textures/GUI/snowflake_clicked.png");
    load_texture(manager, "buttons", \
    "res/Textures/GUI/buttons.png");
}

static void load_fonts(asset_manager_t *manager)
{
    load_font(manager, "roboto_font", "res/Fonts/roboto_regular.ttf");
    load_font(manager, "title_font", "res/Fonts/ballet_harmony.ttf");
    load_font(manager, "number_font", "res/Fonts/komtit.ttf");
}

static void load_textures(asset_manager_t *manager)
{
    load_texture(manager, "clock", \
    "res/Textures/Game/clock.png");
    load_texture(manager, "snowflake", \
    "res/Textures/Game/snowflake.png");
    load_texture(manager, "parallax_bg_menu", \
    "res/Textures/Backgrounds/parallax_bg.png");
    load_texture(manager, "parallax_bg", \
    "res/Textures/Backgrounds/parallax_bg_2.png");
    load_texture(manager, "ls_bg", \
    "res/Textures/Backgrounds/ls_bg.jpg");
    load_texture(manager, "size_box", \
    "res/Textures/Settings/size_box.png");
    load_texture(manager, "framerate_box", \
    "res/Textures/Settings/framerate_box.png");
    load_texture(manager, "sb_sheet", \
    "res/Textures/Character/character.png");
}

void load_all_textures(asset_manager_t *manager)
{
    load_textures(manager);
    load_fonts(manager);
    load_shaders(manager);
    load_gui_textures(manager);
}