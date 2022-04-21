/*
** EPITECH PROJECT, 2022
** move_player
** File description:
** move the player
*/

#include "level1_screen.h"

void static_position(level1 *game)
{

}

void move_right(level1 *game, screens *screen)
{
    sfVector2f pos_player = sfSprite_getPosition(screen->background.sprite);

    pos_player.x -= 4;
    sfSprite_setPosition(screen->background.sprite, pos_player);
}

void move_left(level1 *game, screens *screen)
{
    sfVector2f pos_player = sfSprite_getPosition(screen->background.sprite);

    pos_player.x += 4;
    sfSprite_setPosition(screen->background.sprite, pos_player);
}

void move_up(level1 *game, screens *screen)
{
    sfVector2f pos_player = sfSprite_getPosition(screen->background.sprite);

    pos_player.y += 4;
    sfSprite_setPosition(screen->background.sprite, pos_player);
}

void move_down(level1 *game, screens *screen)
{
    sfVector2f pos_player = sfSprite_getPosition(screen->background.sprite);

    pos_player.y -= 4;
    sfSprite_setPosition(screen->background.sprite, pos_player);
}

void move_player(level1 *game, screens *screen)
{
    void (*orientation[5])(level1 *, screens *) = {&static_position, &move_right, &move_left, &move_up, &move_down};

    game->time = sfClock_getElapsedTime(game->clock);
    game->seconds = game->time.microseconds / 1000000.0;
    orientation[game->move_direction](game, screen);
}