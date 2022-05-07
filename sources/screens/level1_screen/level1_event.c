/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "level1_screen.h"
#include "inventory.h"
#include "fight_screen.h"
#include "menu_screen.h"

bool event_level1(screens *screen, level1 *game, player *player1,
                frame_buffer *buffer, menus *menu)
{
    if (screen->event.type == sfEvtClosed) {
        return (true);
    }
    level1_event_mouse(screen, game, player1);
    level1_event_key(screen, game);
    if (screen->inv_is_set == true)
        event_inventory(screen, &game->stock, player1);
    return (false);
}
