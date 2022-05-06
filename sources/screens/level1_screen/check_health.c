/*
** EPITECH PROJECT, 2022
** check_health
** File description:
** check_health
*/

#include "player.h"

void check_health(player *player1)
{
    player1->stat.rect[0].width = 60 * player1->stat.health;
    sfSprite_setTextureRect(player1->stat.sprite[0], player1->stat.rect[0]);
    player1->stat.rect[1].width = 60 * (player1->stat.max_health - player1->stat.health);
    sfSprite_setTextureRect(player1->stat.sprite[1], player1->stat.rect[1]);
    sfSprite_setPosition(player1->stat.sprite[1],
    (sfVector2f) {50 + 60 * player1->stat.health, 50});
}
