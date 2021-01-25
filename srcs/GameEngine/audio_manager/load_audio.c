/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Game engine - audio manager
*/

#include "GameEngine/game_head.h"

static void load_musics(audio_manager_t *manager)
{
    load_music(manager, "menu_music", "res/Musics/menu_music.ogg");
    load_music(manager, "game_music", "res/Musics/game_music.ogg");
}

static void load_sounds(audio_manager_t *manager)
{
    load_sound(manager, "mouse_click", "res/Sounds/mouse_click.wav");
    load_sound(manager, "splash", "res/Sounds/splash1.wav");
    load_sound(manager, "snowflake_collect", \
    "res/Sounds/snowflake_collected.wav");
    load_sound(manager, "hit", "res/Sounds/hit.wav");
    load_sound(manager, "land", "res/Sounds/land.wav");
}

void load_audio(audio_manager_t *manager)
{
    load_musics(manager);
    load_sounds(manager);
    return;
}