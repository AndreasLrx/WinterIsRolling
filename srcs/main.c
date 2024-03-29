/*
** EPITECH PROJECT, 2020
** My runner
** File description:
** main
*/

#include "my_runner.h"
#include "My/my_display.h"
#include "My/my_strings.h"

static void show_usage(void)
{
    my_putstr("Winter is Rolling :\n\n  Description :\n");
    my_putstr("    In this game you play a snowball ro");
    my_putstr("lling down a mountain\n    trying to avoid traps like spikes, ");
    my_putstr("holes or even water.\n    But don't forget to collect all the ");
    my_putstr("snowflakes!\n\n  Controls :\n    Space bar = Jump\n");
    my_putstr("\n  Special effects :\n");
    my_putstr("    - Ice : accelerate but can't jump\n");
    my_putstr("    - Water : Die\n");
    my_putstr("    - Spikes : Die\n");
    my_putstr("    - Hit a wall : Die\n\n  Settings :\n");
    my_putstr("    - Music / Sound volume : grab the snowflake to adjust the ");
    my_putstr("volumes\n    - Window Size : change the width by clicking on i");
    my_putstr("t and writing the size wanted\n    - Framerate : click in the ");
    my_putstr("box and write the framerate wanted\n\n    All settings are val");
    my_putstr("idated when clicking in the top right validate button \n    ex");
    my_putstr("cept for the size for which you must restart the game.\n\n");
}

int main(int argc, char **argv)
{
    sfVideoMode mode = {0, 0, 32};
    game_data_t *data;

    if (argc == 2 && my_strcmp("-h", argv[1]) == 0) {
        show_usage();
        return 0;
    }
    data = init_game(&mode, "Winter is Rolling");
    if (data == NULL)
        return 84;
    sfRenderWindow_setPosition(data->window, (sfVector2i){0, 0});
    run(data);
    destroy_game(data);
    return 0;
}

