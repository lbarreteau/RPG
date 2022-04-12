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
    sfRenderWindow_drawSprite(screen->window, game->exemple_map.sprite, NULL);
    sfRenderWindow_drawSprite(screen->window, game->how_to_play_sign.sprite, NULL);
    sfRenderWindow_drawSprite(screen->window, game->player.sprite, NULL);
    sfRenderWindow_drawSprite(screen->window, game->title.sprite, NULL);
    sfRenderWindow_drawSprite(screen->window, game->next_step.sprite, NULL);
    sfRenderWindow_display(screen->window);
}
