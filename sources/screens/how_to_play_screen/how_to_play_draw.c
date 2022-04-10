/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "level1_screen.h"

void draw_how_to_play(screens *screen, level1 *game)
{
    sfRenderWindow_clear(screen->window, sfWhite);
    sfRenderWindow_drawSprite(screen->window, screen->background.sprite, NULL);
    sfRenderWindow_drawSprite(screen->window, game->player.sprite, NULL);
    sfRenderWindow_display(screen->window);
}
