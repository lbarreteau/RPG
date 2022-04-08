/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "settings_screen.h"

bool event_settings(screens *screen, settings *setting)
{

    if (screen->event.type == sfEvtClosed) {
        return (true);
    }
    return (false);
}
