/*
** EPITECH PROJECT, 2022
** level1_evt_key
** File description:
** level1_evt_key
*/

#include "level1_screen.h"
#include "fight_screen.h"
#include "menu_screen.h"

static void movement_redirection(screens *screen, level1 *game)
{
    if (screen->event.key.code == sfKeyI) {
        fight_scrn(screen, game->player1);
    }
    if (screen->event.key.code == screen->list_key[1]) {
        game->move_direction = 1;
    }
    if (screen->event.key.code == screen->list_key[0]) {
        game->move_direction = 2;
    }
    if (screen->event.key.code == screen->list_key[2]) {
        game->move_direction = 3;
    }
    if (screen->event.key.code == screen->list_key[3]) {
        game->move_direction = 4;
    }
}

void level1_event_key(screens *screen, level1 *game)
{
    if (screen->event.type == sfEvtKeyPressed) {
        if (screen->event.key.code == sfKeyEscape) {
            game->pause_event = true;
        }
        if (screen->event.key.code == screen->list_key[4]) {
            screen->inv_is_set = !screen->inv_is_set;
        }
        movement_redirection(screen, game);
    }
    if (screen->event.type == sfEvtKeyReleased) {
        if (screen->event.key.code == screen->list_key[0]
        || screen->event.key.code == screen->list_key[1]
        || screen->event.key.code == screen->list_key[2]
        || screen->event.key.code == screen->list_key[3]) {
            game->move_direction = 0;
        }
    }
}
