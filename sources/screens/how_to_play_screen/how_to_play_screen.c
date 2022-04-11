/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "how_to_play.h"

void how_to_play_screen(screens *screen)
{
    struct how_to_play game;
    bool exit = false;

    init_how_to_play_struct(&game);
    set_how_to_play(&game);
    while (sfRenderWindow_isOpen(screen->window)) {
        while (sfRenderWindow_pollEvent(screen->window, &screen->event)) {
            exit = event_how_to_play(screen);
        }
        if (exit == true) {
            free_how_to_play(&game);
            return;
        }
        draw_how_to_play(screen, &game);
    }
}
