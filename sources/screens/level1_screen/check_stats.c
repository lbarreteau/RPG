/*
** EPITECH PROJECT, 2022
** check_stats
** File description:
** check_stats
*/

#include "player.h"
#include "fight_screen.h"

void check_health(player *player1)
{
    player1->stat.rect[0].width = 60 * player1->stat.health;
    sfSprite_setTextureRect(player1->stat.sprite[0], player1->stat.rect[0]);
    player1->stat.rect[1].width =
        60 * (player1->stat.max_health - player1->stat.health);
    sfSprite_setTextureRect(player1->stat.sprite[1], player1->stat.rect[1]);
    sfSprite_setPosition(player1->stat.sprite[1],
    (sfVector2f) {50 + 60 * player1->stat.health, 50});
}

void check_health_ennemy(ennemies_t *ennemy)
{
    ennemy->stat.rect[0].width = 60 * ennemy->stat.health;
    sfSprite_setTextureRect(ennemy->stat.sprite[0], ennemy->stat.rect[0]);
    ennemy->stat.rect[1].width =
        60 * (ennemy->stat.max_health - ennemy->stat.health);
    sfSprite_setTextureRect(ennemy->stat.sprite[1], ennemy->stat.rect[1]);
    sfSprite_setPosition(ennemy->stat.sprite[1],
    (sfVector2f) {1600 + 60 * ennemy->stat.health, 50});
}

void check_dammage(player *player1)
{
    char number[2];

    number[0] = '0' + player1->stat.dammage;
    number[1] = '\0';
    sfText_setString(player1->stat.text_dammage.text, number);
}

void check_xp(player *player1)
{
    if (player1->stat.xp > 10 && player1->stat.level1 == false) {
        player1->stat.max_health += 1;
        player1->stat.dammage *= 2;
        player1->stat.level1 = true;
    }
}

void check_stats(player *player1)
{
    check_health(player1);
    check_dammage(player1);
    check_xp(player1);
}
