/*
** EPITECH PROJECT, 2022
** modif_collisions_pos.c
** File description:
** modif_collisions_pos
*/

#include "level1_screen.h"

void modif_pos_pnj(sfVector2f pos_pnj, sfVector2f pos_pnj_2,
                    sfVector2f movement, level1 *game)
{
    pos_pnj.y += movement.y;
    pos_pnj.x += movement.x;
    pos_pnj_2.y += movement.y;
    pos_pnj_2.x += movement.x;
    sfSprite_setPosition(game->pnj.sprite, pos_pnj);
    sfSprite_setPosition(game->pnj_2.sprite, pos_pnj_2);
    game->hitbox_pnj.left = pos_pnj.x;
    game->hitbox_pnj.top = pos_pnj.y;
    game->hitbox_pnj2.left = pos_pnj_2.x;
    game->hitbox_pnj2.top = pos_pnj_2.y;
}

void modif_collisions_pos(level1 *game, sfVector2f movement)
{
    sfVector2f pos_pnj = sfSprite_getPosition(game->pnj.sprite);
    sfVector2f pos_pnj_2 = sfSprite_getPosition(game->pnj_2.sprite);

    for (int i = 0; i < 21; i++) {
        game->collisions[i].border_pos.x += movement.x;
        game->collisions[i].border_pos.y += movement.y;
        sfRectangleShape_setPosition(game->collisions[i].border,
            game->collisions[i].border_pos);
        game->collisions[i].border_rect.left = game->collisions[i].border_pos.x;
        game->collisions[i].border_rect.top = game->collisions[i].border_pos.y;
    }
    modif_pos_pnj(pos_pnj, pos_pnj_2, movement, game);
}
