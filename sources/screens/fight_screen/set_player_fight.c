/*
** EPITECH PROJECT, 2022
** set_player
** File description:
** set_player
*/

#include "global.h"
#include "fight_screen.h"
#include "player.h"

static void set_sprite(fight_screen *fight)
{
    sfSprite_setScale(fight->player_fight.sprite, fight->player_fight.scale);
    sfSprite_setPosition(fight->player_fight.sprite,
    fight->player_fight.position);
    sfSprite_setTexture(fight->player_fight.sprite, fight->player_fight.texture,
    sfFalse);
    sfSprite_setTextureRect(fight->player_fight.sprite,
    fight->player_fight.rect);
}

void set_player_fight(fight_screen *fight, player *player1)
{
    fight->player_fight.texture = sfTexture_createFromFile(
        "assets/pictures/sprite/npc_sprite.png", NULL);
    fight->player_fight.sprite = sfSprite_create();
    fight->player_fight.rect.top = 144;
    fight->player_fight.rect.left = 51;
    fight->player_fight.rect.width = 51;
    fight->player_fight.rect.height = 72;
    fight->player_fight.position.x = 676;
    fight->player_fight.position.y = 350;
    fight->player_fight.status = 0;
    fight->player_fight.scale.x = 1.7;
    fight->player_fight.scale.y = 1.7;
    fight->player_fight.stat = player1->stat;
    fight->player_fight.hitbox.left = 676;
    fight->player_fight.hitbox.top = 350;
    fight->player_fight.hitbox.width = 86.7;
    fight->player_fight.hitbox.height = 42.5;
    set_sprite(fight);
}
