/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "level1_screen.h"

bool event_level1(screens *screen, level1 *game)
{
    if (screen->event.type == sfEvtClosed) {
        return (true);
    }
    if (screen->event.type == sfEvtKeyPressed) {
        if (screen->event.key.code == sfKeyRight) {
            game->move_direction = 1;
        }
        if (screen->event.key.code == sfKeyLeft) {
            game->move_direction = 2;
        }
        if (screen->event.key.code == sfKeyUp) {
            game->move_direction = 3;
        }
        if (screen->event.key.code == sfKeyDown) {
            game->move_direction = 4;
        }
    }
    if (screen->event.type == sfEvtKeyReleased) {
        if (screen->event.key.code == sfKeyDown || screen->event.key.code == sfKeyUp || screen->event.key.code == sfKeyLeft || screen->event.key.code == sfKeyRight) {
            game->move_direction = 0;
        }
    }
    return (false);
}
