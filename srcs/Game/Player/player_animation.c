/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** Player animations
*/

#include "Game/game_struct.h"

void player_update_anim_rect(player_t *player)
{
    sfRectangleShape_setTextureRect(player->shape, (sfIntRect){\
        player->current_frame * PLAYER_FRAME_SIZE_PX, \
        player->current_anim * PLAYER_FRAME_SIZE_PX, \
        PLAYER_FRAME_SIZE_PX, PLAYER_FRAME_SIZE_PX});
}

void player_set_animation(player_t *player, int anim)
{
    player->current_anim = anim;
    player->current_frame = 0;
    player->frame_duration = 0;
    player_update_anim_rect(player);
}

static void handle_end_anim(player_t *player, int anim)
{
    switch (anim) {
    case JUMP:
        player->current_anim = ROLLING;
        break;
    case LANDING:
        player->current_anim = ROLLING;
        break;
    case DIE:
        player->current_anim = DIE;
        player->die_clock++;
        break;
    default:
        break;
    }
    if (player->die_clock >= 4) {
        player_respawn(player);
        player->die_clock = 0;
    }
}

void player_update_animation(player_t *player, float dt)
{
    player->frame_duration += dt;
    if (player->frame_duration >= \
    PLAYER_ANIM_FRAME_DURATION[player->current_anim]) {
        player->current_frame++;
        player->frame_duration = 0;
    } else
        return;
    if (player->current_frame >= PLAYER_ANIM_LENGTH[player->current_anim]) {
        player->current_frame = 0;
        handle_end_anim(player, player->current_anim);
    }
    player_update_anim_rect(player);
}