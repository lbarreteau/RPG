/*
** EPITECH PROJECT, 2022
** set_fight_screen
** File description:
** set_fight_screen
*/

#include "fight_screen.h"
#include "global.h"

void set_fight_screen(fight_screen *fight)
{
    //fight->player = init_sprite(game->name_player_sprite, (sfVector2f) {1, 1}, (sfVector2f) {0, 0});
    //fight->protection = init_sprite(game->name_player_sprite, (sfVector2f) {1, 1}, (sfVector2f) {0, 0});
    //fight->energy = init_sprite(game->name_player_sprite, (sfVector2f) {1, 1}, (sfVector2f) {0, 0});
    //fight->enemy = init_sprite(game->name_player_sprite, (sfVector2f) {1, 1}, (sfVector2f) {0, 0});
    fight->map = init_sprite("assets/pictures/map/map_fight.png", (sfVector2f) {5, 5}, (sfVector2f) {-400, -500});
    fight->bull.sprite = init_sprite("assets/pictures/sprite/bull.png", (sfVector2f) {0.7, 0.7}, (sfVector2f) {600, 300});
    fight->bull.clock = sfClock_create();
    fight->bull.is_activ = false;
    fight->font = sfFont_createFromFile("assets/families/font.ttf");
}
