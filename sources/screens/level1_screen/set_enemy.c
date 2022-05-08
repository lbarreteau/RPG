/*
** EPITECH PROJECT, 2022
** set_eenemy
** File description:
** set enemies
*/

#include "level1_screen.h"

void set_enemy(level1 *game)
{
    game->enemy.texture = sfTexture_createFromFile(
        "assets/pictures/sprite/npc_sprite.png", NULL);
    game->enemy.sprite = sfSprite_create();
    game->enemy.rect.top = 0;
    game->enemy.rect.left = 0;
    game->enemy.rect.width = 51;
    game->enemy.rect.height = 72;
    game->enemy.position.x = 1035;
    game->enemy.position.y = 580;
    game->enemy.is_alive = true;
    game->enemy.scale.x = 1.7;
    game->enemy.scale.y = 1.7;
    game->enemy.hitbox.left = 1035;
    game->enemy.hitbox.top = 580;
    game->enemy.hitbox.width = 51;
    game->enemy.hitbox.height = 72;
    sfSprite_setScale(game->enemy.sprite, game->enemy.scale);
}
