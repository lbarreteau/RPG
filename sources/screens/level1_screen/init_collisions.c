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
    game->collisions = malloc(sizeof(collision_t) * 20);

    for (int i = 0; i < 20; i++) {
        game->collisions[i].border =  sfRectangleShape_create();
        game->collisions[i].border_pos = (sfVector2f){0.0, 0.0};
        game->collisions[i].border_size = (sfVector2f){0.0, 0.0};
        game->collisions[i].border_rect = (sfIntRect){0.0, 0.0, 0.0, 0.0};
    }
    create_first_five_collisions(game);
    create_map_border_collisions(game);
    game->collisions[5].border_rect = create_border_intrect(game, (sfIntRect){0, 0, 776, 172}, 5);
    game->collisions[5] = create_border(game,
        (sfVector2f){776, 172}, (sfVector2f){1050, -100}, 5);
    game->collisions[6].border_rect = create_border_intrect(game, (sfIntRect){0, 0, 776, 1}, 6);
    game->collisions[6] = create_border(game,
        (sfVector2f){776, 1}, (sfVector2f){500, -30}, 6);
    game->collisions[7].border_rect = create_border_intrect(game, (sfIntRect){0, 0, 370, 1710}, 7);
    game->collisions[7] = create_border(game,
        (sfVector2f){370, 1710}, (sfVector2f){1440, -100}, 7);
    game->collisions[8].border_rect = create_border_intrect(game, (sfIntRect){0, 0, 355, 499}, 8);
    game->collisions[8] = create_border(game,
        (sfVector2f){355, 499}, (sfVector2f){500, 1110}, 8);
    game->collisions[9].border_rect = create_border_intrect(game, (sfIntRect){0, 0, 355, 499}, 9);
    game->collisions[9] = create_border(game,
        (sfVector2f){355, 499}, (sfVector2f){1045, 1110}, 9);
    game->collisions[10].border_rect = create_border_intrect(game, (sfIntRect){0, 0, 1000, 400}, 10);
    game->collisions[10] = create_border(game,
        (sfVector2f){1000, 400}, (sfVector2f){1128, 1310}, 10);
    game->collisions[11].border_rect = create_border_intrect(game, (sfIntRect){0, 0, 1400, 400}, 11);
    game->collisions[11] = create_border(game,
        (sfVector2f){1400, 400}, (sfVector2f){1728, 1310}, 11);
    game->collisions[12].border_rect = create_border_intrect(game, (sfIntRect){0, 0, 1000, 200}, 12);
    game->collisions[12] = create_border(game,
        (sfVector2f){1000, 200}, (sfVector2f){2050, 1710}, 12);
}
