/*
** EPITECH PROJECT, 2022
** check_collisions_fireball.c
** File description:
** check_collisions_fireball
*/

#include "global.h"
#include "fight_screen.h"

bool check_collisions_fireball_player(fight_screen *fight)
{
    printf("%d\n", fight->player_fight.life);
    for (int i = 0; i < 3; i++) {
        if (sfIntRect_intersects(&fight->attack[i].hitbox,
        &fight->player_fight.hitbox, NULL) == sfTrue &&
        fight->bubble.is_activ == false) {
            fight->attack[i].is_activ = false;
            fight->attack[i].hitbox = (sfIntRect){0, 0, 0, 0};
            fight->player_fight.life -= 1;
        }
        if (sfIntRect_intersects(&fight->attack[i].hitbox,
        &fight->player_fight.hitbox, NULL) == sfTrue &&
        fight->bubble.is_activ == true) {
            fight->attack[i].is_activ = false;
        }
    }
    return (true);
}
