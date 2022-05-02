/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "level1_screen.h"

void set_level1(level1 *game)
{
    game->map = init_sprite("assets/pictures/map/map_spawn.png",
    (sfVector2f) {4, 4}, (sfVector2f) {-1175, -900});
    game->clock = sfClock_create();
    game->move_direction = 0;
}
