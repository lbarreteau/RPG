/*
** EPITECH PROJECT, 2022
** init_collisions.c
** File description:
** init_collisions
*/
#include "global.h"
#include "level1_screen.h"

collision_t create_border(level1 *game, sfRectangleShape *border, sfVector2f size,
                sfVector2f pos)
{
    sfRectangleShape_setSize(border, size);

    game->collisions->border_size = size;
    sfRectangleShape_setPosition(border, pos);
    sfRectangleShape_setFillColor(border, sfBlack);
    game->collisions[0].border_pos = pos;
    return (game->collisions[0]);
}

void init_all_collisions(level1 *game)
{
    game->collisions = malloc(sizeof(collision_t) * 20);

    for (int i = 0; i < 20; i++) {
        game->collisions[i].border = sfRectangleShape_create();
        game->collisions[i].border_pos = (sfVector2f){0.0, 0.0};
        game->collisions[i].border_size = (sfVector2f){0.0, 0.0};
    }
    game->collisions[0] = create_border(game, game->collisions[0].border,
    (sfVector2f){141, 400}, (sfVector2f){727, 89});
}
