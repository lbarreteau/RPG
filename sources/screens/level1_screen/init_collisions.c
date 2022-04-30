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
    game->collisions[10].border_rect = create_border_intrect(game, (sfIntRect){0, 0, 1000, 400}, 10);
    game->collisions[10] = create_border(game,
        (sfVector2f){1000, 400}, (sfVector2f){1128, 1310}, 10);
    game->collisions[11].border_rect = create_border_intrect(game, (sfIntRect){0, 0, 1400, 400}, 11);
    game->collisions[11] = create_border(game,
        (sfVector2f){1400, 400}, (sfVector2f){1728, 1310}, 11);
    game->collisions[12].border_rect = create_border_intrect(game, (sfIntRect){0, 0, 1000, 200}, 12);
    game->collisions[12] = create_border(game,
        (sfVector2f){1000, 200}, (sfVector2f){2050, 1710}, 12);
    game->collisions[13].border_rect = create_border_intrect(game, (sfIntRect){0, 0, 500, 200}, 13);
    game->collisions[13] = create_border(game,
        (sfVector2f){500, 200}, (sfVector2f){-220, 2110}, 13);
    game->collisions[14].border_rect = create_border_intrect(game, (sfIntRect){0, 0, 200, 800}, 14);
    game->collisions[14] = create_border(game,
        (sfVector2f){200, 800}, (sfVector2f){-120, 1510}, 14);
    create_map_border_collisions(game);
    game->collisions[17].border_rect = create_border_intrect(game, (sfIntRect){0, 0, 280, 200}, 17);
    game->collisions[17] = create_border(game,
        (sfVector2f){280, 150}, (sfVector2f){1448, 2205}, 17);
    game->collisions[18].border_rect = create_border_intrect(game, (sfIntRect){0, 0, 160, 200}, 18);
    game->collisions[18] = create_border(game,
        (sfVector2f){160, 150}, (sfVector2f){1825, 2205}, 18);
    game->collisions[19].border_rect = create_border_intrect(game, (sfIntRect){0, 0, 160, 200}, 19);
    game->collisions[19] = create_border(game,
        (sfVector2f){160, 150}, (sfVector2f){2155, 2205}, 19);
    game->collisions[20].border_rect = create_border_intrect(game, (sfIntRect){0, 0, 160, 200}, 20);
    game->collisions[20] = create_border(game,
        (sfVector2f){160, 150}, (sfVector2f){2470, 2205}, 20);
}
