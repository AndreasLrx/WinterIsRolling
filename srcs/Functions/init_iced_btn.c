/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** init iced button
*/

#include "GameEngine/game_head.h"
#include "GUI/gui_head.h"
#include "Drawables/drawables_head.h"

struct button_infos_t *init_iced_btn(state_t *state, \
int id_button, sfVector2f pos)
{
    struct button_infos_t *infos = malloc(sizeof(struct button_infos_t));

    infos->pos = pos;
    infos->size = (sfVector2f){130 * SCL(state), SCL(state) * 130};
    infos->textures = malloc(sizeof(sfTexture *));
    infos->textures[0] = get_texture(state->game_data->assets, "buttons");
    infos->text_rects = malloc(sizeof(sfIntRect) * 3);
    for (int i = 0; i < 3; i++){
        infos->text_rects[i] = (sfIntRect){id_button * 130, i * 130, 130, 130};
    }
    infos->nb_states = 3;
    infos->update_type = GUI_TEXTURED_RECT;
    infos->click_sound = "mouse_click";
    infos->audio = state->game_data->audio;
    return infos;
}

struct text_button_infos_t *init_iced_text_btn(state_t *state, \
sfVector2f pos, wchar_t *str)
{
    struct text_button_infos_t *infos = \
    malloc(sizeof(struct text_button_infos_t));

    infos->btn_infos = init_iced_btn(state, NONE, pos);
    infos->text_align = CENTER;
    infos->str = str;
    infos->font = get_font(state->game_data->assets, "number_font");
    infos->text_update_type = GUI_COLORED | GUI_OUTCOLORED;
    infos->char_size = 100 * SCL(state);
    infos->fill_colors = malloc(sizeof(sfColor) * 3);
    infos->out_colors = malloc(sizeof(sfColor) * 3);
    for (int i = 0; i < 3; i++){
        infos->out_colors[i] = sfColor_fromRGB(62, 168, 228);
    }
    infos->fill_colors[0] = sfWhite;
    infos->fill_colors[1] = sfColor_fromRGB(170, 241, 254);
    infos->fill_colors[2] = sfColor_fromRGB(132, 206, 221);
    infos->out_thickness = 3 * SCL(state);
    return infos;
}