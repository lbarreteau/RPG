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

void create_fifteen_collisions(level1 *game)
{
    game->collisions[10].border_rect = create_border_intrect(game,
        (sfIntRect){0, 0, 1000, 400}, 10);
    game->collisions[10] = create_border(game,
        (sfVector2f){1000, 400}, (sfVector2f){1128, 1310}, 10);
    game->collisions[11].border_rect = create_border_intrect(game,
        (sfIntRect){0, 0, 1400, 400}, 11);
    game->collisions[11] = create_border(game,
        (sfVector2f){1400, 400}, (sfVector2f){1728, 1310}, 11);
    game->collisions[12].border_rect = create_border_intrect(game,
        (sfIntRect){0, 0, 1000, 200}, 12);
    game->collisions[12] = create_border(game,
        (sfVector2f){1000, 200}, (sfVector2f){2050, 1710}, 12);
    game->collisions[13].border_rect = create_border_intrect(game,
        (sfIntRect){0, 0, 500, 200}, 13);
    game->collisions[13] = create_border(game,
        (sfVector2f){500, 200}, (sfVector2f){-220, 2110}, 13);
    game->collisions[14].border_rect = create_border_intrect(game,
    (sfIntRect){0, 0, 200, 800}, 14);
    game->collisions[14] = create_border(game,
        (sfVector2f){200, 800}, (sfVector2f){-120, 1510}, 14);
}

void create_twenty_collisions(level1 *game)
{
    game->collisions[17].border_rect = create_border_intrect(game,
        (sfIntRect){0, 0, 280, 200}, 17);
    game->collisions[17] = create_border(game,
        (sfVector2f){280, 150}, (sfVector2f){1448, 2205}, 17);
    game->collisions[18].border_rect = create_border_intrect(game,
        (sfIntRect){0, 0, 160, 200}, 18);
    game->collisions[18] = create_border(game,
        (sfVector2f){160, 150}, (sfVector2f){1825, 2205}, 18);
    game->collisions[19].border_rect = create_border_intrect(game,
        (sfIntRect){0, 0, 160, 200}, 19);
    game->collisions[19] = create_border(game,
        (sfVector2f){160, 150}, (sfVector2f){2155, 2205}, 19);
    game->collisions[20].border_rect = create_border_intrect(game,
        (sfIntRect){0, 0, 160, 200}, 20);
    game->collisions[20] = create_border(game,
        (sfVector2f){160, 150}, (sfVector2f){2470, 2205}, 20);
}