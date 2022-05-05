/*
** EPITECH PROJECT, 2022
** fight_screen
** File description:
** fight_screen
*/

#include "fight_screen.h"
#include "player.h"
#include "global.h"
#include <unistd.h>

void fight_scrn(screens *screen)
{
    struct fight_screen fight;
    bool exit = false;

    set_fight_screen(&fight);
    set_player_fight(&fight);
    set_attack(&fight.attack[0], (sfIntRect){0, 0, 64, 64});
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
