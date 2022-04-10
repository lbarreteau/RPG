/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "level1_screen.h"

static void free_sprite(level1 *game)
{
    sfTexture_destroy(game->player.texture);
    sfSprite_destroy(game->player.sprite);
}

void free_how_to_play(level1 *game)
{
    free_sprite(game);
}
