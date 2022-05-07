/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "level1_screen.h"

void set_level1(level1 *game, player *player1)
{
    game->map = init_sprite("assets/pictures/map/map_spawn.png",
    (sfVector2f) {4, 4}, (sfVector2f) {-1175, -900});
    game->clock = sfClock_create();
    game->move_direction = 0;
    game->player1 = player1;
    game->pause_event = false;
    set_enemy(game);
    game->background_dialog = init_sprite("assets/pictures/sign/long_sign.png",
    (sfVector2f) {2, 2}, (sfVector2f) {450, 800});
    game->dialog = init_text(25, (sfVector2f) {540, 860}, sfBlack);
}
