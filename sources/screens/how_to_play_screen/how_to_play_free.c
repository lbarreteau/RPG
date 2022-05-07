/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "how_to_play.h"

static void free_sprite(how_to_play *game)
{
    sfTexture_destroy(game->how_to_play.texture);
    sfSprite_destroy(game->how_to_play.sprite);
    sfTexture_destroy(game->exit.texture);
    sfSprite_destroy(game->exit.sprite);
}

static void free_name(how_to_play *game)
{
    free(game->background);
}

void free_how_to_play(how_to_play *game)
{
    free_name(game);
    free_sprite(game);
}
