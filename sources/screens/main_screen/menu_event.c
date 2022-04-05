/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "menu_screen.h"

bool event_menu(screens *screen, menus *menu)
{
    if (screen->event.type == sfEvtClosed) {
        return (true);
    }
    return (false);
}
