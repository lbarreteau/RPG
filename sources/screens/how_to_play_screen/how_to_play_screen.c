/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "how_to_play.h"

bool how_to_play_screen(screens *screen)
{
    struct how_to_play game;
    int exit = 0;

    init_how_to_play_struct(&game);
    set_how_to_play(&game);
    while (sfRenderWindow_isOpen(screen->window)) {
        while (sfRenderWindow_pollEvent(screen->window, &screen->event)) {
            exit = event_how_to_play(screen, &game);
        }
        if (exit == 1) {
            free_how_to_play(&game);
            return (true);
        }
        if (exit == 2) {
            free_how_to_play(&game);
            return (false);
        }
        draw_how_to_play(screen, &game);
    }
    return (false);
}
