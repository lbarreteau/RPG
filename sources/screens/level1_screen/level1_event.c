/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "level1_screen.h"

bool event_level1(screens *screen)
{
    sfVector2f pos_player;

    if (screen->event.type == sfEvtClosed) {
        return (true);
    }
    if (screen->event.type == sfEvtKeyPressed) {
        pos_player = sfSprite_getPosition(screen->background.sprite);
        if (screen->event.key.code == sfKeyRight) {
            pos_player.x -= 3;
        }
        if (screen->event.key.code == sfKeyLeft) {
            pos_player.x += 3;
        }
        if (screen->event.key.code == sfKeyUp) {
            pos_player.y += 3;
        }
        if (screen->event.key.code == sfKeyDown) {
            pos_player.y -= 3;
        }
        sfSprite_setPosition(screen->background.sprite, pos_player);
    }
    return (false);
}
