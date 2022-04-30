/*
** EPITECH PROJECT, 2022
** all_collisions.c
** File description:
** all_collisions
*/

#include "global.h"
#include "level1_screen.h"

void create_map_border_collisions(level1 *game)
{
    game->collisions[15] = create_border(game, (sfVector2f){40000, 1},
        (sfVector2f){0, 2310}, 15);
    game->collisions[15].border_rect = create_border_intrect(game,
        (sfIntRect){0, 0, 40000, 1}, 15);
    game->collisions[16] = create_border(game, (sfVector2f){1, 40000},
        (sfVector2f){3140, 0}, 16);
    game->collisions[16].border_rect = create_border_intrect(game,
        (sfIntRect){0, 0, 1, 40000}, 16);
}

void create_ten_collisions(level1 *game)
{
    game->collisions[5].border_rect = create_border_intrect(game,
    (sfIntRect){0, 0, 776, 172}, 5);
    game->collisions[5] = create_border(game,
        (sfVector2f){776, 172}, (sfVector2f){1050, -100}, 5);
    game->collisions[6].border_rect = create_border_intrect(game,
    (sfIntRect){0, 0, 776, 1}, 6);
    game->collisions[6] = create_border(game,
        (sfVector2f){776, 1}, (sfVector2f){500, -30}, 6);
    game->collisions[7].border_rect = create_border_intrect(game,
    (sfIntRect){0, 0, 370, 1710}, 7);
    game->collisions[7] = create_border(game,
        (sfVector2f){370, 1710}, (sfVector2f){1440, -100}, 7);
    game->collisions[8].border_rect = create_border_intrect(game,
    (sfIntRect){0, 0, 355, 499}, 8);
    game->collisions[8] = create_border(game,
        (sfVector2f){355, 499}, (sfVector2f){500, 1110}, 8);
    game->collisions[9].border_rect = create_border_intrect(game,
    (sfIntRect){0, 0, 355, 499}, 9);
    game->collisions[9] = create_border(game,
        (sfVector2f){355, 499}, (sfVector2f){1045, 1110}, 9);
}

void create_first_five_collisions(level1 *game)
{
    game->collisions[0] = create_border(game, (sfVector2f){141, 400},
        (sfVector2f){727, 89}, 0);
    game->collisions[0].border_rect = create_border_intrect(game,
        (sfIntRect){727, 89, 141, 400}, 0);
    game->collisions[1].border_rect = create_border_intrect(game,
        (sfIntRect){1053, 25, 141, 475}, 1);
    game->collisions[1] = create_border(game,
        (sfVector2f){141, 475}, (sfVector2f){1053, -25}, 1);
    game->collisions[2].border_rect = create_border_intrect(game,
        (sfIntRect){0, 0, 776, 172}, 2);
    game->collisions[2] = create_border(game,
        (sfVector2f){776, 172}, (sfVector2f){95, -100}, 2);
    game->collisions[3].border_rect = create_border_intrect(game,
        (sfIntRect){0, 0, 370, 1710}, 3);
    game->collisions[3] = create_border(game,
        (sfVector2f){370, 1710}, (sfVector2f){95, -100}, 3);
    game->collisions[4].border_rect = create_border_intrect(game,
        (sfIntRect){0, 0, 600, 400}, 4);
    game->collisions[4] = create_border(game,
        (sfVector2f){600, 400}, (sfVector2f){640, 600}, 4);
}