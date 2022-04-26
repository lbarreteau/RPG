/*
** EPITECH PROJECT, 2022
** modif_collisions_pos.c
** File description:
** modif_collisions_pos
*/

#include "level1_screen.h"

static bool verif_collision_y(level1 *game, player *player1)
{
    for (int i = 0; i < 20; i++) {
        if (player1->position.y == game->collisions[i].border_pos.y +
            game->collisions->border_size.y) {
            printf("collision");
            return (true);
        }
    }
    return (false);
}

static bool verif_collision_x(level1 *game, player *player1)
{
    for (int i = 0; i < 20; i++) {
        if (player1->position.x + player1->rect.width >=
        game->collisions[i].border_pos.x && player1->position.x <=
        (game->collisions[i].border_pos.x + game->collisions[i].border_size.x)) {
            printf("collision");
            return (true);
        }
    }
    return (false);
}

bool there_is_collision_up(level1 *game, player *player1)
{
    printf("player pos x = %f, pos y = %f\n", player1->position.x, player1->position.y);
    printf("pos x = %f, pos y = %f\n", game->collisions[1].border_pos.x, game->collisions[0].border_pos.y);
    bool check_x = false;
    bool check_y = false;

    check_x = verif_collision_y(game, player1);
    check_y = verif_collision_x(game, player1);
    if (check_x == true && check_y == true)
        return (true);
    return (false);
}

void modif_collisions_pos(level1 game, sfVector2f movement)
{
    for (int i = 0; i < 20; i++) {
        game.collisions[i].border_pos.x += movement.x;
        game.collisions[i].border_pos.y += movement.y;
        sfRectangleShape_setPosition(game.collisions[i].border,
            game.collisions[i].border_pos);
    }
}