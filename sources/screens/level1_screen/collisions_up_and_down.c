/*
** EPITECH PROJECT, 2022
** collisions_up_and_down.c
** File description:
** collisions_up_and_down
*/

#include "level1_screen.h"

static bool verif_collision_y_up(level1 *game, player *player1)
{
    for (int i = 0; i < 20; i++) {
        if (player1->position.y == game->collisions[i].border_pos.y +
            game->collisions->border_size.y) {
            return (true);
        }
    }
    return (false);
}

static bool verif_collision_y_down(level1 *game, player *player1)
{
    for (int i = 0; i < 20; i++) {
        if (player1->position.y == game->collisions[i].border_pos.y) {
            return (true);
        }
    }
    return (false);
}

static bool verif_collision_x_up_and_down(level1 *game, player *player1)
{
    for (int i = 0; i < 20; i++) {
        if (player1->position.x + player1->rect.width >=
        game->collisions[i].border_pos.x && player1->position.x <=
        (game->collisions[i].border_pos.x + game->collisions[i].border_size.x))
            return (true);
    }
    return (false);
}

bool there_is_collision_up(level1 *game, player *player1)
{
    bool check_x = false;
    bool check_y = false;

    check_x = verif_collision_y_up(game, player1);
    check_y = verif_collision_x_up_and_down(game, player1);
    if (check_x == true && check_y == true)
        return (true);
    return (false);
}

bool there_is_collision_down(level1 *game, player *player1)
{
    bool check_x = false;
    bool check_y = false;

    check_x = verif_collision_y_down(game, player1);
    check_y = verif_collision_x_up_and_down(game, player1);
    if (check_x == true && check_y == true)
        return (true);
    return (false);
}