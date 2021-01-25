/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GUI - base struct
*/

#ifndef GUI_STRUCT_H
#define GUI_STRUCT_H

#include <stddef.h>
#include <SFML/Graphics.h>

enum GUI_STATES {GUI_NORMAL, GUI_HOVER, GUI_CLICKED};
enum GUI_UPDATE_TYPES {GUI_COLORED = 1, GUI_OUTCOLORED = 2, \
GUI_TEXTURED = 4, GUI_TEXTURED_RECT = 8};

/*
** Base struct for gui items
**
** item = ptr to gui item struct (button...)
**
** handle_inputs = f_ptr to react to user inputs
**      -size_t item_ptr
**      -size_t datas (sfEvent or other)
**
** update = f_ptr to update item (animations / transformations)
**      -size_t item_ptr
**      -float delta_time
**      -size_t datas (could be null)
**
** draw = f_ptr to draw item
**      -size_t item_ptr
**      -sfRenderWindow* window to draw to
*/
typedef struct gui_item_t{
    size_t item;
    struct gui_output *(*handle_inputs)(size_t, size_t);
    struct gui_output *(*update)(size_t, float, size_t);
    struct gui_output *(*draw)(size_t, sfRenderWindow *);
    struct gui_output *(*draw_texture)(size_t, sfRenderTexture *);
    struct gui_output *(*destroy)(size_t *);
    int selected;
    int enabled;
    int tag;
} gui_item_t;

gui_item_t *init_gui(size_t (*item_init)(gui_item_t *, size_t), size_t datas);
struct gui_output *make_gui_output(gui_item_t *item, size_t data);

#endif /* !GUI_STRUCT_H */