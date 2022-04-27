/*
** EPITECH PROJECT, 2022
** collisions_left_and_right.c
** File description:
** collisions_left_and_right
*/

#include "level1_screen.h"

static bool verif_collision_y_left_and_right(level1 *game, player *player1)
{
    for (int i = 0; i < 20; i++) {
        if (player1->position.y >
        game->collisions[i].border_pos.y &&
        player1->position.y + player1->rect.height <
        (game->collisions[i].border_pos.y + 16 + game->collisions->border_size.y)) {
            return (true);
        }
    }
    return (false);
}

static bool verif_collision_x_left(level1 *game, player *player1)
{
    for (int i = 0; i < 20; i++) {
        if (player1->position.x  - 4 < (game->collisions[i].border_pos.x +
        game->collisions[i].border_size.x) && (player1->position.x  - 4 >
        game->collisions[i].border_pos.x)) {
            return (true);
        }
    }
    return (false);
}

static bool verif_collision_x_right(level1 *game, player *player1)
{
    for (int i = 0; i < 20; i++) {
        if (player1->position.x + player1->rect.width  + 4 > (
            game->collisions[i].border_pos.x) && player1->position.x  + 4 <
            (game->collisions[i].border_pos.x + game->collisions[i].border_size.x)) {
            return (true);
        }
    }
    return (false);
}

bool there_is_collision_left(level1 *game, player *player1)
{
    bool check_x = false;
    bool check_y = false;

    check_y = verif_collision_y_left_and_right(game, player1);
    check_x = verif_collision_x_left(game, player1);
    if (check_x == true && check_y == true)
        return (true);
    return (false);
}

bool there_is_collision_right(level1 *game, player *player1)
{
    bool check_x = false;
    bool check_y = false;

    check_y = verif_collision_y_left_and_right(game, player1);
    check_x = verif_collision_x_right(game, player1);
    if (check_x == true && check_y == true)
        return (true);
    return (false);
}