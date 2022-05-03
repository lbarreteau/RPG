/*
** EPITECH PROJECT, 2022
** fight_screen
** File description:
** fight_screen
*/

#include "fight_screen.h"
#include "player.h"
#include "global.h"
//#include "enemy.h
#include <unistd.h>

void my_putchar(char c) {
    write(1, &c, 1);
}

void fight_scrn(screens *screen)
{
    struct fight_screen fight;
    bool exit = false;

    set_fight_screen(&fight);
    set_player_fight(&fight);
    while (sfRenderWindow_isOpen(screen->window)) {
        while (sfRenderWindow_pollEvent(screen->window, &screen->event)) {
            exit = event_management_fight_screen(screen, &fight);
        }
        if (exit == true) {
            free_fight_screen(&fight);
            return;
        }
        draw_fight_screen(screen, &fight);
    }
    free_fight_screen(&fight);
}
