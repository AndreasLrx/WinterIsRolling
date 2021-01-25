/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GUI - GUI manager
*/

#ifndef GUI_MANAGER_H
#define GUI_MANAGER_H

#include <stddef.h>
#include <SFML/Graphics.h>

#define GET_ITEM(m, type, tag) ((type *)gui_manager_get_item(m, tag))

struct gui_item_t;
struct my_map_t;

struct gui_output {
    int tag;
    size_t data;
};

/*
** GUI manager
**
** items = vector of items
** data_map = datas to update items
**      - key = int (index of item in vec)
**      - value = value/struct to update item (depending on item)
** outputs = vector filled with guis item update/handle input outputs
**      - tag = item tag
**      - data = data (type depend on gui item)
*/
typedef struct gui_manager_t {
    struct gui_item_t **items;
    struct my_map_t *data_map;
    struct gui_output **outputs;
} gui_manager_t;

gui_manager_t *init_gui_manager(void);
void gui_manager_add_item(gui_manager_t *manager, \
size_t (*item_init)(gui_item_t *, size_t), size_t datas, int tag);
void gui_manager_add_data(gui_manager_t *manager, int pos, size_t data);
size_t gui_manager_get_item(gui_manager_t *manager, int tag);

int guis_handle_input(gui_manager_t *manager, size_t datas);
int guis_update(gui_manager_t *manager, float dt);
int guis_draw(gui_manager_t *manager, sfRenderWindow *window);
int guis_draw_texture(gui_manager_t *manager, sfRenderTexture *texture);

void gui_manager_destroy_item(gui_manager_t *manager, int item_pos);
void gui_manager_destroy(gui_manager_t *manager);

void gui_manager_enable_item(gui_manager_t *manager, int tag, int enable);

#endif /* !GUI_MANAGER_H */