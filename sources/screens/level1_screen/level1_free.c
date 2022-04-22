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
    sfTexture_destroy(game->map.texture);
    sfSprite_destroy(game->map.sprite);
}

void free_level1(level1 *game)
{
    free_sprite(game);
}
