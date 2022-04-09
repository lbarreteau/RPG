/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "level1_screen.h"

void level1_screen(screens *screen)
{
    struct level1 game;
    bool exit = false;

    init_level1_struct(&game);
    set_level1(&game);
    while (sfRenderWindow_isOpen(screen->window)) {
        while (sfRenderWindow_pollEvent(screen->window, &screen->event)) {
            exit = event_level1(screen);
        }
        if (exit == true) {
            free_level1(&game);
            return;
        }
        draw_level1(screen, &game);
    }
}
