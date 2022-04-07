/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "level1_screen.h"

void level1_screen(void)
{
    struct screens screen;
    struct level1 game;
    bool exit = false;

    init_screen_struct(&screen);
    init_level1_struct(&game);
    set_screen(&screen);
    set_level1(&game);
    while (sfRenderWindow_isOpen(screen.window)) {
        while (sfRenderWindow_pollEvent(screen.window, &screen.event)) {
            exit = event_menu(&screen, &game);
        }
        if (exit == true) {
            free_level1(&screen, &game);
            return;
        }
        draw_level1(&screen, &game);
    }
}
