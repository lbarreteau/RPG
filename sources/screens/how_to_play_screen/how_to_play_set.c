/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "level1_screen.h"

void set_how_to_play(level1 *game)
{
    game->player = init_sprite("assets/pictures/long_sign.png",
    (sfVector2f) {1, 1}, (sfVector2f) {0, 0});
}
