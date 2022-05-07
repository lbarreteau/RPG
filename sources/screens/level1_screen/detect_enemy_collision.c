/*
** EPITECH PROJECT, 2022
** detect_ennemy_colision
** File description:
** detect colisions with enmies
*/

#include "level1.h"

void detect_enemy_collision_up_down(screens *screen, player *player1, int move)
{
    game->enemy.position.y += move;
    game->enemy.hitbox.height += move;
    sfSprite_setPosition(game->enemy.sprite, game->enemy.position);
    if (sfIntRect_intersects(&player1->hitbox,&game->enemy.hitbox, NULL) == sfTrue) {
        fight_scrn(screen, player1);
    }
}

void detect_enemy_collision_right_left(screens *screen, player *player1, int move)
{
    game->enemy.position.x += move;
    game->enemy.hitbox.width += move;
    sfSprite_setPosition(game->enemy.sprite, game->enemy.position);
    if (sfIntRect_intersects(&player1->hitbox,&game->enemy.hitbox, NULL) == sfTrue) {
        fight_scrn(screen, player1);
    }
}

void detect_enemy_collision(screens *screen, player *player1, int move, int option)
{
    if (option == 0) {
        detect_enemy_collision_right_left(screen, player1, move);
    } else {
        detect_enemy_collision_up_down(screen, player1, move);detect_enemy_collision_right_left(screen, player1, move);
    }
}
