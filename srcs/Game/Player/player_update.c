/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** player update
*/

#include "Game/game_struct.h"

static void update_position(player_t *player)
{
    pe_vec2f_t pos = player->body->pos;
    sfVector2f shape_size = sfRectangleShape_getSize(player->shape);

    shape_size.x /= 2.f;
    shape_size.y /= 2.f;
    sfRectangleShape_setPosition(player->shape, (sfVector2f){\
        (pos.x * player->tile_size) - shape_size.x, \
        (pos.y * player->tile_size) - shape_size.y * PLAYER_PENETRATION_RATIO});
}

static void handle_contact(player_t *player, int i)
{
    pe_manifold_t *contact = player->body->contacts[i];
    pe_fixture_t *fixture = ((contact->af->body == player->body) ? \
contact->af : contact->bf);
    pe_fixture_t *other = ((contact->af == fixture) ? \
contact->bf : contact->af);

    if (contact->normal.y >= 0.6 && !other->is_sensor)
        player_land(player, contact, other);
    if (fixture->is_sensor)
        return;
    if (((contact->normal.y <= 0.6 && \
        other->collision_filter.category == GROUND) || \
        (other->collision_filter.category == WATER || \
        other->collision_filter.category == SPIKE)))
        player_kill(player, other->collision_filter.category);
    if (other->collision_filter.category == SNOWFLAKE)
        player_collect_snowflake(player, other);
}

static void player_correctionnal_force(player_t *player)
{
    float vel_sqr = pe_vec2f_length_squared(player->body->velocity);

    if (vel_sqr >= 200)
        return;
    pe_body_add_force(player->body, VEC2F(10 * ((200 - vel_sqr) / 200), 0));
}

void player_update(player_t *player, float dt)
{
    size_t nb_contacts = my_vector_get_size((size_t *)player->body->contacts);

    if (player->body->velocity.x < 0)
        player_kill(player, -1);
    for (int i = 0; i < nb_contacts && player->die_clock == 0; i++)
        handle_contact(player, i);
    player->jump_sensor.lifetime--;
    if (player->jump_sensor.lifetime < 0)
        player->fly_time++;
    update_position(player);
    player_correctionnal_force(player);
    player_update_animation(player, dt);
}