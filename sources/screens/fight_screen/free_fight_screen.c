/*
** EPITECH PROJECT, 2022
** free_fight_screen
** File description:
** free fight screen
*/

#include "fight_screen.h"
#include "global.h"

static void free_sprite(fight_screen *fight)
{
    sfClock_destroy(fight->attack_clock);
}

void free_fight_screen(fight_screen *fight)
{
    free_sprite(fight);
}
