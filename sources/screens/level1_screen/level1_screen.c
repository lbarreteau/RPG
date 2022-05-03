/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "level1_screen.h"
#include "player.h"

void level1_screen(screens *screen)
{
    struct level1 game;
    struct player player1;
    bool exit = false;

    init_level1_struct(&game);
    set_player(&player1);
    set_level1(&game);
    init_all_collisions(&game);
    while (sfRenderWindow_isOpen(screen->window)) {
        while (sfRenderWindow_pollEvent(screen->window, &screen->event)) {
            exit = event_level1(screen, &game, &player1);
        }
        if (exit == true) {
            free_level1(&game);
            return;
        }
        move_player(&game, screen, &player1);
        draw_level1(screen, &game, &player1);
    }
    free_level1(&game);
}
