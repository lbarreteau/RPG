/*
** EPITECH PROJECT, 2022
** modif_collisions_pos.c
** File description:
** modif_collisions_pos
*/

#include "level1_screen.h"

void modif_collisions_pos(level1 game, sfVector2f movement)
{
    for (int i = 0; i < 20; i++) {
        game.collisions[i].border_pos.x += movement.x;
        game.collisions[i].border_pos.y += movement.y;
        sfRectangleShape_setPosition(game.collisions[i].border,
            game.collisions[i].border_pos);
        game.collisions[i].border_rect.left = game.collisions[i].border_pos.x;
        game.collisions[i].border_rect.top = game.collisions[i].border_pos.y;
    }
}
