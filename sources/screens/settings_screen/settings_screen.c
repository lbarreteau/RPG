/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "settings_screen.h"

bool settings_screen(screens *screen)
{
    struct settings setting;
    int exit = 0;

    init_settings_struct(&setting);
    set_settings(screen, &setting);
    while (sfRenderWindow_isOpen(screen->window)) {
        while (sfRenderWindow_pollEvent(screen->window, &screen->event)) {
            exit = event_settings(screen, &setting);
        }
        if (exit == 1) {
            free_settings(&setting);
            return (true);
        }
        if (exit == 2) {
            free_settings(&setting);
            return (false);
        }
        draw_settings(screen, &setting);
    }
    return (false);
}
