/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "settings_screen.h"

void settings_screen(screens *screen)
{
    struct settings setting;
    bool exit = false;

    init_screen_struct(screen);
    init_settings_struct(&setting);
    set_screen(screen);
    set_settings(&setting);
    while (sfRenderWindow_isOpen(screen->window)) {
        while (sfRenderWindow_pollEvent(screen->window, &screen->event)) {
            exit = event_settings(screen, &setting);
        }
        if (exit == true) {
            free_settings(screen, &setting);
            return;
        }
        draw_settings(screen, &setting);
    }
}
