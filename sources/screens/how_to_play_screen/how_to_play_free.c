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
    sfTexture_destroy(game->player.texture);
    sfSprite_destroy(game->player.sprite);
    sfTexture_destroy(game->how_to_play_sign.texture);
    sfSprite_destroy(game->how_to_play_sign.sprite);
    sfTexture_destroy(game->exemple_map.texture);
    sfSprite_destroy(game->exemple_map.sprite);
    sfTexture_destroy(game->title.texture);
    sfSprite_destroy(game->title.sprite);
    sfTexture_destroy(game->next_step.texture);
    sfSprite_destroy(game->next_step.sprite);
}

static void free_name(how_to_play *game)
{
    free(game->name_background_sign);
    free(game->name_player_sprite);
    free(game->name_exemple_map);
    free(game->name_title);
}

void free_how_to_play(how_to_play *game)
{
    free_name(game);
    free_sprite(game);
}
