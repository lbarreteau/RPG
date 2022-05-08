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
    game->background_dialog = init_sprite("assets/pictures/sign/long_sign.png",
    (sfVector2f) {2, 2}, (sfVector2f) {450, 800});
    game->dialog_2 = init_text(25, (sfVector2f) {550, 875}, sfBlack);
    game->background_dialog_2 = init_sprite("assets/pictures/sign/long_sign.png",
    (sfVector2f) {2, 2}, (sfVector2f) {450, 800});
    game->dialog = init_text(25, (sfVector2f) {540, 860}, sfBlack);
    game->pnj = init_sprite(game->name_pnj,
    (sfVector2f) {1.75, 1.75}, (sfVector2f) {430, 1000});
    game->hitbox_pnj = (sfIntRect) {430, 1000, 51, 122};
    game->pnj_2 = init_sprite(game->name_pnj_2,
    (sfVector2f) {1.75, 1.75}, (sfVector2f) {1300, 40});
    game->hitbox_pnj2 = (sfIntRect) {1300, 40, 51, 122};
    set_enemy(game->enemy);
}
