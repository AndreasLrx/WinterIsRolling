/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** GUI - button fcts
*/

#include "GUI/gui_head.h"

int is_text_clicked(click_text_t *text)
{
    return (text->state == GUI_CLICKED);
}