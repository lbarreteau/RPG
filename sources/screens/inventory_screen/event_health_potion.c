/*
** EPITECH PROJECT, 2022
** event_health_potion
** File description:
** event_health_potion
*/

#include "inventory.h"

void event_health_potion(box *slot, inventory *stock, player *player1)
{
    slot->is_empty = true;
    sfSprite_setTexture(slot->item.sprite, stock->texture[6], sfFalse);
    if (player1->stat.health != player1->stat.max_health)
        player1->stat.health += 1;
}

void check_is_health(screens *screen, inventory *stock, player *player1)
{
    int slot = mouse_click_slot(screen, stock);

    if (slot == -1)
        return;
    if (stock->spot[slot].is_empty == false &&
    stock->spot[slot].item.type == NOTHING)
        event_health_potion(&stock->spot[slot], stock, player1);
}
