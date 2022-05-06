/*
** EPITECH PROJECT, 2022
** check_collisions_fireball.c
** File description:
** check_collisions_fireball
*/

#include "global.h"
#include "fight_screen.h"

void create_new_fireball(fight_screen *fight)
{
    fight->time = sfClock_getElapsedTime(fight->attack_clock);
    fight->seconds = fight->time.microseconds;
    if (fight->seconds > 2700000) {
        for (int i = 0; i < 10; i++) {
            if (fight->attack[i].exist == false) {
                fight->attack[i].exist = true;
                fight->attack[i].is_activ = true;
                break;
            }
        }
        sfClock_restart(fight->attack_clock);
    }
}

bool check_collisions_fireball_player(fight_screen *fight)
{
    create_new_fireball(fight);
    for (int i = 0; i < 10; i++) {
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
