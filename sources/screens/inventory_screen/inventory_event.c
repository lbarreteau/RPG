/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "inventory.h"

void change_rect(screens *screen, inventory *stock)
{
    for (int i = 0; i < 26; i++) {
        mouse_on_rect(screen, &stock->spot[i].rect, stock->spot[i].slot);
    }
}

void event_inventory(screens *screen, inventory *stock)
{
    change_rect(screen, stock);
    if (screen->event.type == sfEvtMouseButtonPressed &&
    screen->event.mouseButton.button == sfMouseLeft) {
        stock->nb_slot = mouse_click_slot(screen, stock);
    }
    if (screen->event.type == sfEvtMouseButtonReleased) {
        if (stock->nb_slot != -1)
            check_good_move(screen, stock);
        stock->nb_slot = -1;
    }
    move_in_inventory(screen, stock);
}
