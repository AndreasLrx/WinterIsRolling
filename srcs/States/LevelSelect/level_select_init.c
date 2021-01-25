/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** level_select init
*/

#include "States/LevelSelect/level_select_state.h"
#include "My/my_convert.h"

static struct text_button_infos_t *init_disabled_btn(state_t *state, \
sfVector2f pos, wchar_t *str)
{
    struct text_button_infos_t *infos = init_iced_text_btn(state, pos, str);

    infos->btn_infos->update_type |= GUI_COLORED;
    infos->btn_infos->fill_colors = malloc(sizeof(sfColor) * 3);
    for (int i = 0; i < 3; i++) {
        infos->btn_infos->fill_colors[i] = sfColor_fromRGBA(200, 200, 200, 170);
        infos->fill_colors[i] = sfColor_fromRGB(170, 170, 170);
        infos->out_colors[i] = sfColor_fromRGB(42, 138, 188);
    }
    return infos;
}

static void init_btn(state_t *state, level_grid_t *grid, int i, sfVector2f *pos)
{
    wchar_t *istr = my_itowstr(i + 1);

    if (i < grid->nb_availables)
        grid->buttons[i] = init_gui(&text_button_init, \
        (size_t)init_iced_text_btn(state, *pos, istr));
    else {
        grid->buttons[i] = init_gui(&text_button_init, \
        (size_t)init_disabled_btn(state, *pos, istr));
        grid->buttons[i]->enabled = 0;
    }
    grid->buttons[i]->tag = i;
    (*pos).x += 130 * SCL(state) + grid->spacing;
    if ((*pos).x >= (1920 - grid->margin) * SCL(state)) {
        (*pos).x = grid->margin * SCL(state);
        (*pos).y += 130 * SCL(state) + grid->spacing;
    }
    free(istr);
}

static level_grid_t *init_grid(state_t *state)
{
    level_grid_t *grid = malloc(sizeof(level_grid_t));
    sfVector2f current_pos;

    grid->pos = (sfVector2f){0, 360 * SCL(state)};
    grid->margin = 305;
    grid->nb_availables = 3;
    grid->nb_buttons = 10;
    grid->nb_columns = 5;
    grid->spacing = SCL(state) * ((1920 - 2 * grid->margin - \
    grid->nb_columns * 130) / (grid->nb_columns - 1));
    grid->buttons = malloc(sizeof(gui_item_t *) * grid->nb_buttons);
    current_pos = grid->pos;
    current_pos.x = grid->margin * SCL(state);
    for (int i = 0; i < grid->nb_buttons; i++){
        init_btn(state, grid, i, &current_pos);
    }
    return grid;
}

int level_select_init(state_t *state)
{
    state->state_datas = (size_t *)init_grid(state);
    gui_manager_add_item(state->gui, &button_init, \
    (size_t)init_iced_btn(state, RETURN, \
    (sfVector2f){20 * SCL(state), 20 * SCL(state)}), LS_QUIT_BTN);
    level_select_init_title(state);
    return 0;
}