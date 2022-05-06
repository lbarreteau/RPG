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
    sfSprite_setScale(fight->ennemy[0].sprite, fight->ennemy[0].scale);
    sfSprite_setPosition(fight->ennemy[0].sprite,
    fight->ennemy[0].position);
    sfSprite_setTexture(fight->ennemy[0].sprite, fight->ennemy[0].texture,
    sfFalse);
    sfSprite_setTextureRect(fight->ennemy[0].sprite,
    fight->ennemy[0].rect);
}

void set_ennemy_fight(fight_screen *fight)
{
    fight->ennemy[0].texture = sfTexture_createFromFile(
        "assets/pictures/sprite/npc_sprite.png", NULL);
    fight->ennemy[0].sprite = sfSprite_create();
    fight->ennemy[0].rect.top = 355;
    fight->ennemy[0].rect.left = 354;
    fight->ennemy[0].rect.width = 51;
    fight->ennemy[0].rect.height = 72;
    fight->ennemy[0].position.x = 1246;
    fight->ennemy[0].position.y = 335;
    fight->ennemy[0].scale.x = 1.7;
    fight->ennemy[0].scale.y = 1.7;
    fight->ennemy[0].life = 3;
    fight->ennemy[0].hitbox.left = 1246;
    fight->ennemy[0].hitbox.top = 335;
    fight->ennemy[0].hitbox.width = 86.7;
    fight->ennemy[0].hitbox.height = 42.5;
    set_sprite(fight);
}