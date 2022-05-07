/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "how_to_play.h"

void draw_how_to_play(screens *screen, how_to_play *game)
{
    sfRenderWindow_clear(screen->window, sfWhite);
    sfRenderWindow_drawSprite(screen->window, game->how_to_play.sprite, NULL);
    sfRenderWindow_drawSprite(screen->window, game->exit.sprite, NULL);
    sfRenderWindow_display(screen->window);
}
