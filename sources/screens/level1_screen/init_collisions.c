/*
** EPITECH PROJECT, 2022
** init_collisions.c
** File description:
** init_collisions
*/

#include "global.h"
#include "level1_screen.h"

collision_t create_border(level1 *game, sfVector2f size,
                sfVector2f pos, int i)
{
    sfRectangleShape_setSize(game->collisions[i].border, size);
    game->collisions->border_size = size;
    sfRectangleShape_setPosition(game->collisions[i].border, pos);
    sfRectangleShape_setFillColor(game->collisions[i].border, sfBlack);
    game->collisions[i].border_pos = pos;
    return (game->collisions[i]);
}

sfIntRect create_border_intrect(level1 *game, sfIntRect params, int i)
{
    game->collisions[i].border_rect.height = params.height;
    game->collisions[i].border_rect.width = params.width;
    game->collisions[i].border_rect.left = params.left;
    game->collisions[i].border_rect.top = params.top;
    return (game->collisions[i].border_rect);
}

void init_all_collisions(level1 *game)
{
    game->collisions = malloc(sizeof(collision_t) * 21);

    for (int i = 0; i < 21; i++) {
        game->collisions[i].border =  sfRectangleShape_create();
        game->collisions[i].border_pos = (sfVector2f){0.0, 0.0};
        game->collisions[i].border_size = (sfVector2f){0.0, 0.0};
        game->collisions[i].border_rect = (sfIntRect){0.0, 0.0, 0.0, 0.0};
    }
    create_first_five_collisions(game);
    create_ten_collisions(game);
    create_fifteen_collisions(game);
    create_map_border_collisions(game);
    create_twenty_collisions(game);
}
