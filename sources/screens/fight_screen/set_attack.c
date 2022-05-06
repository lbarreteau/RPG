/*
** EPITECH PROJECT, 2022
** set_attack.c
** File description:
** set_attack
*/

#include "global.h"
#include "fight_screen.h"

void fireball_animation(attack_t *fireball, int movement)
{
    fireball->time = sfClock_getElapsedTime(fireball->animation);
    fireball->seconds = fireball->time.microseconds / 1000000.0;
    if (fireball->seconds > 0.1) {
        fireball->rect.left += 64;
        sfSprite_setTextureRect(fireball->sprite.sprite, fireball->rect);
        fireball->pos.x += movement;
        fireball->hitbox.left += movement;
        sfSprite_setPosition(fireball->sprite.sprite, fireball->pos);
        sfClock_restart(fireball->animation);
    }
    if (fireball->rect.left == 64 * 7) {
        fireball->rect.left = 0;
    }
}

void destroy_attack(attack_t *attack)
{
    sfTexture_destroy(attack->sprite.texture);
    sfSprite_destroy(attack->sprite.sprite);
    attack->rect.top = 0;
    attack->rect.left = 0;
    attack->rect.width = 0;
    attack->rect.height = 0;
    attack->pos = (sfVector2f){0, 0};
    attack->hitbox = (sfIntRect){0, 0, 0, 0};
    attack->is_activ = false;
    attack->exist = false;
    sfClock_destroy(attack->animation);
    sfClock_destroy(attack->movement);
}

void set_attack_player(attack_t *attack, sfIntRect rect, int i)
{
    attack->sprite.texture = sfTexture_createFromFile
        ("assets/pictures/sprite/fireball.png", NULL);
    attack->sprite.sprite = sfSprite_create();
    attack->rect.top = rect.top;
    attack->rect.left = rect.left;
    attack->rect.width = rect.width;
    attack->rect.height = rect.height;
    attack->pos = (sfVector2f){700, 300};
    attack->hitbox = (sfIntRect){700, 300, 64, 64};
    sfSprite_setTexture(attack->sprite.sprite, attack->sprite.texture, sfTrue);
    sfSprite_setTextureRect(attack->sprite.sprite, attack->rect);
    sfSprite_setPosition(attack->sprite.sprite, attack->pos);
    sfSprite_setScale(attack[i].sprite.sprite, (sfVector2f){3, 3});
    attack->is_activ = false;
    attack->exist = false;
    attack->animation = sfClock_create();
    attack->movement = sfClock_create();
}

void set_attack_ennemy(attack_t *attack, sfIntRect rect, int i)
{
    attack->sprite.texture = sfTexture_createFromFile
        ("assets/pictures/sprite/fireball.png", NULL);
    attack->sprite.sprite = sfSprite_create();
    attack->rect.top = rect.top;
    attack->rect.left = rect.left;
    attack->rect.width = rect.width;
    attack->rect.height = rect.height;
    attack->pos = (sfVector2f){1150, 300};
    attack->hitbox = (sfIntRect){1150, 300, 64, 64};
    sfSprite_setTexture(attack->sprite.sprite, attack->sprite.texture, sfTrue);
    sfSprite_setTextureRect(attack->sprite.sprite, attack->rect);
    sfSprite_setPosition(attack->sprite.sprite, attack->pos);
    sfSprite_setScale(attack[i].sprite.sprite, (sfVector2f){3, 3});
    attack->is_activ = false;
    attack->exist = false;
    attack->animation = sfClock_create();
    attack->movement = sfClock_create();
}
