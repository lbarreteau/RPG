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
    return (false);
}
