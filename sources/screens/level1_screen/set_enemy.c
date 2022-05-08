/*
** EPITECH PROJECT, 2022
** set_eenemy
** File description:
** set enemies
*/

#include "level1_screen.h"

void set_first_enemy(enemy_t *enemy)
{
    enemy->texture = sfTexture_createFromFile(
        "assets/pictures/sprite/npc_sprite.png", NULL);
    enemy->sprite = sfSprite_create();
    enemy->rect.top = 284;
    enemy->rect.left = 357;
    enemy->rect.width = 51;
    enemy->rect.height = 72;
    enemy->position.x = 200;
    enemy->position.y = 1525;
    enemy->is_alive = true;
    enemy->scale.x = 1.7;
    enemy->scale.y = 1.7;
    enemy->hitbox.left = 200;
    enemy->hitbox.top = 1525;
    enemy->hitbox.width = 87;
    enemy->hitbox.height = 123;
    sfSprite_setPosition(enemy->sprite, enemy->position);
    sfSprite_setScale(enemy->sprite, enemy->scale);
}

void set_second_enemy(enemy_t *enemy)
{
    enemy->texture = sfTexture_createFromFile(
        "assets/pictures/sprite/npc_sprite.png", NULL);
    enemy->sprite = sfSprite_create();
    enemy->rect.top = 284;
    enemy->rect.left = 357;
    enemy->rect.width = 51;
    enemy->rect.height = 72;
    enemy->position.x = 2425;
    enemy->position.y = 1950;
    enemy->is_alive = true;
    enemy->scale.x = 1.7;
    enemy->scale.y = 1.7;
    enemy->hitbox.left = 2425;
    enemy->hitbox.top = 1950;
    enemy->hitbox.width = 87;
    enemy->hitbox.height = 123;
    sfSprite_setPosition(enemy->sprite, enemy->position);
    sfSprite_setScale(enemy->sprite, enemy->scale);
}

void set_enemy(enemy_t *enemy)
{
    set_first_enemy(&enemy[0]);
    set_second_enemy(&enemy[1]);
}
