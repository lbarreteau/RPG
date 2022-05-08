/*
** EPITECH PROJECT, 2022
** check_equipment
** File description:
** check_equipment
*/

#include "player.h"
#include "inventory.h"

void check_equipment(player *player1, inventory *stock)
{
    if (stock->spot[24].is_empty == false) {
        player1->stat.dammage = 2 + (player1->stat.max_health - 3);
    } else {
        player1->stat.dammage = 1 + (player1->stat.max_health - 3);
    }
}
