/*
** EPITECH PROJECT, 2022
** set_player
** File description:
** set_player
*/

#include "player.h"
#include <stddef.h>

void set_player(player *player1)
{
    player1->texture = sfTexture_createFromFile("assets/pictures/sprite/npc_sprite.png", NULL);
    player1->sprite = sfSprite_create();;
    player1->rect.top = 0;
    player1->rect.left = 0;
    player1->rect.width = 51;
    player1->rect.height = 72;
    player1->position.x = 935;
    player1->position.y = 400;
    player1->status = 0;
    player1->scale.x = 1.7;
    player1->scale.y = 1.7;

    sfSprite_setScale(player1->sprite, player1->scale);
    sfSprite_setPosition(player1->sprite, player1->position);
}
