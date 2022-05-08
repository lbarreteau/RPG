/*
** EPITECH PROJECT, 2022
** detect_ennemy_colision
** File description:
** detect colisions with enmies
*/

#include "level1_screen.h"

void detect_enemy_collision(screens *screen, player *player1,
                            level1 *game, sfVector2f pos)
{
    for (int i = 0; i < 2; i++) {
        game->enemy[i].position.x += pos.x;
        game->enemy[i].position.y += pos.y;
        game->enemy[i].hitbox.top += pos.y;
        game->enemy[i].hitbox.left += pos.x;
        sfSprite_setPosition(game->enemy[i].sprite, game->enemy[i].position);
        if (sfIntRect_intersects(&player1->hitbox,
            &game->enemy[i].hitbox, NULL) == sfTrue &&
            game->enemy[i].is_alive == true) {
            fight_scrn(screen, player1);
            game->enemy[i].is_alive = false;
        }
    }
}
