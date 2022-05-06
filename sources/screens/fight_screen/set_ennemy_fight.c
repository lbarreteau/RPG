/*
** EPITECH PROJECT, 2022
** set_ennemy_fight.c
** File description:
** set_ennemy_fight
*/

#include "global.h"
#include "fight_screen.h"

static set_sprite(fight_screen *fight)
{
    sfSprite_setScale(fight->ennemi[0].sprite, fight->ennemi[0].scale);
    sfSprite_setPosition(fight->ennemi[0].sprite,
    fight->ennemi[0].position);
    sfSprite_setTexture(fight->ennemi[0].sprite, fight->ennemi[0].texture,
    sfFalse);
    sfSprite_setTextureRect(fight->ennemi[0].sprite,
    fight->ennemi[0].rect);
}

void set_ennemy_fight(fight_screen *fight)
{
    fight->ennemi[0].texture = sfTexture_createFromFile(
        "assets/pictures/sprite/npc_sprite.png", NULL);
    fight->ennemi[0].sprite = sfSprite_create();
    fight->ennemi[0].rect.top = 355;
    fight->ennemi[0].rect.left = 354;
    fight->ennemi[0].rect.width = 51;
    fight->ennemi[0].rect.height = 72;
    fight->ennemi[0].position.x = 1246;
    fight->ennemi[0].position.y = 350;
    fight->ennemi[0].scale.x = 1.8;
    fight->ennemi[0].scale.y = 1.8;
    fight->ennemi[0].life = 3;
    fight->ennemi[0].hitbox.left = 1246;
    fight->ennemi[0].hitbox.top = 350;
    fight->ennemi[0].hitbox.width = 86.7;
    fight->ennemi[0].hitbox.height = 42.5;
    set_sprite(fight);
}