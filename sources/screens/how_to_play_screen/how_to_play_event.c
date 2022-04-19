/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "level1_screen.h"

bool event_how_to_play(screens *screen)
{
    if (screen->event.type == sfEvtClosed) {
        return (true);
    }
    if (screen->event.type == sfEvtKeyPressed) {
    }
    return (false);
}
