/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GUI - textfield handle inputs
*/

#include <wchar.h>
#include "GUI/gui_head.h"
#include "My/my_strings.h"

static void play_select_sound(textfield_t *field)
{
    if (field->infos->audio == NULL)
        return;
    play_sound(field->infos->audio, field->infos->select_sound);
}

static void update_select(textfield_t *field, sfEvent *event)
{
    sfVector2f mouse_pos = {event->mouseButton.x, event->mouseButton.y};

    if (is_in_bounds(mouse_pos, field->infos->pos, field->infos->size)){
        if (field->gui_item->selected == 0)
            play_select_sound(field);
        field->gui_item->selected = 1;
    } else if (field->gui_item->selected)
        field->gui_item->selected = 0;
}

static int handle_text(textfield_t *field, sfEvent *event)
{
    size_t vect_size = my_vector_get_size((size_t *)field->str);
    sfUint32 c = event->text.unicode;

    if (c == 8 && vect_size > 1)
        my_vector_erase((size_t *)field->str, vect_size - 2, 0);
    if (c != 8 && c != 13 && ((!field->infos->is_ascii) || \
    (c >= 32 && c <= 126))){
        if (field->infos->whitelist == NULL || \
            my_wstrchr(field->infos->whitelist, (wchar_t)c) != NULL)
            my_vector_insert((size_t **)&field->str, vect_size - 1, (size_t)c);
    }
    if (c == 13 && my_vector_get_size((size_t *)field->str) != 1)
        return 1;
    update_text(field);
    return 0;
}

struct gui_output *output_text(textfield_t *field)
{
    struct gui_output *out = malloc(sizeof(struct gui_output));

    out->tag = field->gui_item->tag;
    out->data = (size_t)my_wstrdup_except((wchar_t *)field->str, '\n');
    my_vector_push((size_t **)&field->str, 0);
    return out;
}

struct gui_output *textfield_handle_input(size_t field_adr, size_t event_var)
{
    textfield_t *field = (textfield_t *)field_adr;
    sfEvent *event = (sfEvent*)(event_var);

    if (event->type == sfEvtMouseButtonPressed)
        update_select(field, event);
    if (!field->gui_item->selected)
        return 0;
    if (event->type == sfEvtTextEntered){
        if (handle_text(field, event))
            return output_text(field);
    }
    return NULL;
}