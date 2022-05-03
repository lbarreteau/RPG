/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "inventory.h"


void inventory_screen(void)
{
    struct screens screen;
    struct inventory stock;
    bool exit = false;

    init_screen_struct(&screen);

    screen.window = sfRenderWindow_create(screen.mode, screen.name_screen, sfClose, NULL);
    sfRenderWindow_setFramerateLimit(screen.window, screen.fps);

    init_inventory_struct(&stock);
    set_inventory(&stock);
    while (sfRenderWindow_isOpen(screen.window)) {
        while (sfRenderWindow_pollEvent(screen.window, &screen.event)) {
            exit = event_inventory(&screen, &stock);
        }
        if (exit == true) {
            free_inventory(&screen, &stock);
            return;
        }
        draw_inventory(&screen, &stock);
    }
}
