/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "how_to_play.h"

void set_how_to_play(how_to_play *game)
{
    game->player = init_sprite(game->name_player_sprite,
    (sfVector2f) {1, 1}, (sfVector2f) {0, 0});
    game->how_to_play_sign = init_sprite(game->name_background_sign,
    (sfVector2f) {2, 2}, (sfVector2f) {130, 40});
    game->exemple_map = init_sprite(game->name_exemple_map,
    (sfVector2f) {3, 3}, (sfVector2f) {0, 0});
}
