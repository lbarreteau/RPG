/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "level1_screen.h"
#include "how_to_play.h"
#include "settings_screen.h"

int event_how_to_play(screens *screen, how_to_play *game)
{
    if (screen->event.type == sfEvtClosed) {
        return (1);
    }
    if (screen->event.type == sfEvtMouseButtonPressed &&
        screen->event.mouseButton.button == sfMouseLeft) {
        if (mouse_clicked_button(screen, game->exit.sprite,
        (sfVector2f){80, 80})) {
            return (2);
        }
    }
    return (0);
}
