/*
** EPITECH PROJECT, 2022
** move_player
** File description:
** move the player
*/

#include "level1_screen.h"
#include "player.h"

void static_position(level1 *game, screens *screen, player *player1)
{
    player1->rect.left = 52;
}

void move_right(level1 *game, screens *screen, player *player1)
{
    sfVector2f pos_player = sfSprite_getPosition(game->map.sprite);

    pos_player.x -= 4;
    sfSprite_setPosition(game->map.sprite, pos_player);
    modif_collisions_pos(game[0], (sfVector2f){-4, 0});
    player1->rect.top = 144;
}

void move_left(level1 *game, screens *screen, player *player1)
{
    sfVector2f pos_player = sfSprite_getPosition(game->map.sprite);

    pos_player.x += 4;
    sfSprite_setPosition(game->map.sprite, pos_player);
    modif_collisions_pos(game[0], (sfVector2f){4, 0});
    player1->rect.top = 72;
}

void move_up(level1 *game, screens *screen, player *player1)
{
    sfVector2f pos_player = sfSprite_getPosition(game->map.sprite);

    pos_player.y += 4;
    sfSprite_setPosition(game->map.sprite, pos_player);
    modif_collisions_pos(game[0], (sfVector2f){0, 4});
    player1->rect.top = 216;
}

void move_down(level1 *game, screens *screen, player *player1)
{
    sfVector2f pos_player = sfSprite_getPosition(game->map.sprite);

    pos_player.y -= 4;
    sfSprite_setPosition(game->map.sprite, pos_player);
    modif_collisions_pos(game[0], (sfVector2f){0, -4});
    player1->rect.top = 0;
}

void move_player(level1 *game, screens *screen, player *player1)
{
    void (*orientation[5])(level1 *, screens *, player *) = {&static_position, &move_right, &move_left, &move_up, &move_down};

    game->time = sfClock_getElapsedTime(game->clock);
    game->seconds = game->time.microseconds / 1000000.0;
    if (player1->rect.left == 0) {
        player1->status = 1;
    }
    if (player1->rect.left == 104) {
        player1->status = -1;
    }
    if (game->seconds > 0.14) {
        player1->rect.left += 52 * player1->status;
        sfClock_restart(game->clock);
    }
    orientation[game->move_direction](game, screen, player1);
}