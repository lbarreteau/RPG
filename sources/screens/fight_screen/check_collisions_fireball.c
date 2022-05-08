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
    for (int i = 0; i < 10; i++) {
        if (fight->attack_ennemy[i].exist == false) {
            fight->attack_ennemy[i].exist = true;
            fight->attack_ennemy[i].is_activ = true;
            break;
        }
    }
}

void create_all_fireballs(fight_screen *fight)
{
    fight->time = sfClock_getElapsedTime(fight->attack_clock);
    fight->seconds = fight->time.microseconds;
    if (fight->seconds > 2800000) {
        create_new_fireball(fight);
        sfClock_restart(fight->attack_clock);
    }
}

void check_damage_player(fight_screen *fight, int i)
{
    if (fight->bubble.is_activ == false) {
        fight->player_fight.stat.health -= 1;
    }
    fight->attack_ennemy[i].is_activ = false;
    fight->attack_ennemy[i].hitbox = (sfIntRect){0, 0, 0, 0};
}

bool check_collisions_fireball_player(fight_screen *fight)
{
    create_all_fireballs(fight);
    for (int i = 0; i < 10; i++) {
        if (sfIntRect_intersects(&fight->attack_ennemy[i].hitbox,
        &fight->player_fight.hitbox, NULL) == sfTrue) {
            check_damage_player(fight, i);
        }
        if (fight->player_fight.stat.health <= 0) {
            fight->dead_player = true;
            return (true);
        }
    }
    return (false);
}

bool check_collisions_fireball_ennemy(fight_screen *fight)
{
    if (sfIntRect_intersects(&fight->attack_player.hitbox,
    &fight->ennemy[0].hitbox, NULL) == sfTrue) {
        fight->attack_player.is_activ = false;
        fight->attack_player.exist = false;
        fight->attack_player.hitbox = (sfIntRect){700, 300, 64, 64};
        fight->attack_player.pos = (sfVector2f) {650, 300};
        sfSprite_setPosition(fight->attack_player.sprite.sprite,
            fight->attack_player.pos);
        fight->ennemy[0].stat.health -= fight->player_fight.stat.dammage;
    }
    if (fight->ennemy[0].stat.health <= 0) {
        return (true);
    }
    return (false);
}
