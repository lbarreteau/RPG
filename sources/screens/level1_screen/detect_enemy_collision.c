/*
** EPITECH PROJECT, 2022
** detect_ennemy_colision
** File description:
** detect colisions with enmies
*/

#include "level1_screen.h"

void detect_enemy_collision(screens *screen, player *player1, level1 *game, sfVector2f pos)
{
    game->enemy.position.x += pos.x;
    game->enemy.position.y += pos.y;
    game->enemy.hitbox.top += pos.y;
    game->enemy.hitbox.left += pos.x;
    sfSprite_setPosition(game->enemy.sprite, game->enemy.position);
    if (sfIntRect_intersects(&player1->hitbox,
        &game->enemy.hitbox, NULL) == sfTrue && game->enemy.is_alive == true) {
        fight_scrn(screen, player1);
        game->enemy.is_alive = false;
    }
}
