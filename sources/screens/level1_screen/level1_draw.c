/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "level1_screen.h"
#include "player.h"

void draw_level1(screens *screen, level1 *game, player *player1, frame_buffer *buffer)
{
    sfRenderWindow_clear(screen->window, sfBlack);
    sfRenderWindow_drawSprite(screen->window, game->map.sprite, NULL);
    sfSprite_setTexture(player1->sprite, player1->texture, sfFalse);
    sfSprite_setTextureRect(player1->sprite, player1->rect);
    sfRenderWindow_drawSprite(screen->window, player1->sprite, NULL);
    sfRenderWindow_drawSprite(screen->window, buffer->sprite, NULL);
}
