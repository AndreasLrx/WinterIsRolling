/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GUI - button fcts
*/

#include "GUI/gui_head.h"

int is_btn_clicked(button_t *btn)
{
    return (btn->state == GUI_CLICKED);
}