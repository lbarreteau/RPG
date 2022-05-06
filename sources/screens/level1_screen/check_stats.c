/*
** EPITECH PROJECT, 2022
** check_stats
** File description:
** check_stats
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

void check_dammage(player *player1)
{
    char number[2];

    number[0] = '0' + player1->stat.dammage;
    number[1] = '\0';
    sfText_setString(player1->stat.text_dammage.text, number);
}