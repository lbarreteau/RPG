/*
** EPITECH PROJECT, 2022
** event_management_fight_screen
** File description:
** event management fight screen
*/

#include "fight_screen.h"
#include "global.h"

bool event_management_fight_screen(screens *screen, fight_screen *fight)
{
    if (screen->event.type == sfEvtClosed) {
        return (true);
    }
    if (screen->event.type == sfEvtKeyPressed) {
        if (screen->event.key.code == sfKeySpace && fight->bull.is_activ == false) {
            sfClock_restart(fight->bull.clock);
            fight->bull.is_activ = true;
        }
    }
    return (false);
}
