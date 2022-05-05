/*
** EPITECH PROJECT, 2022
** set_attack.c
** File description:
** set_attack
*/

#include "global.h"
#include "fight_screen.h"

void fireball_animation(attack_t *fireball)
{
    fireball->time = sfClock_getElapsedTime(fireball->animation);
    fireball->seconds = fireball->time.microseconds / 1000000.0;
    if (fireball->seconds > 0.1) {
        fireball->rect.left += 64;
        sfSprite_setTextureRect(fireball->sprite.sprite, fireball->rect);
        fireball->pos.x -= 20;
        sfSprite_setPosition(fireball->sprite.sprite, fireball->pos);
        sfClock_restart(fireball->animation);
    }
    if (fireball->rect.left == 64 * 7) {
        fireball->rect.left = 0;
    }
}

void set_attack(attack_t *attack, sfIntRect rect)
{
    attack->sprite.texture = sfTexture_createFromFile("assets/pictures/sprite/fireball.png", NULL);
    attack->sprite.sprite = sfSprite_create();
    attack->rect.top = rect.top;
    attack->rect.left = rect.left;
    attack->rect.width = rect.width;
    attack->rect.height = rect.height;
    attack->pos = (sfVector2f){1150, 300};
    sfSprite_setTexture(attack->sprite.sprite, attack->sprite.texture, sfTrue);
    sfSprite_setTextureRect(attack->sprite.sprite, attack->rect);
    sfSprite_setPosition(attack->sprite.sprite, attack->pos);
    sfSprite_setScale(attack[0].sprite.sprite, (sfVector2f){3, 3});
    attack->is_activ = false;
    attack->animation = sfClock_create();
    attack->movement = sfClock_create();
}
