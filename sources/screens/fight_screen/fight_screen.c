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

void set_all_fight(fight_screen *fight, player *player1)
{
    set_fight_screen(fight);
    set_player_fight(fight, player1);
    set_ennemy_fight(fight);
}

void fight_scrn(screens *screen, player *player1)
{
    struct fight_screen fight;
    bool exit = false;

    set_all_fight(&fight, player1);
    while (sfRenderWindow_isOpen(screen->window)) {
        while (sfRenderWindow_pollEvent(screen->window, &screen->event)) {
            exit = event_management_fight_screen(screen, &fight);
        }
        if (exit == true) {
            player1->stat.health = fight.player_fight.stat.health;
            free_fight_screen(&fight);
            return;
        }
        exit = check_collisions_fireball_player(&fight);
        if (exit != true)
            exit = check_collisions_fireball_ennemy(&fight);
        check_health(&fight.player_fight);
        check_health_ennemy(&fight.ennemy[0]);
        draw_fight_screen(screen, &fight);
    }
}
