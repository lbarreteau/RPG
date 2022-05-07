/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "how_to_play.h"

void set_how_to_play(how_to_play *game)
{
    game->how_to_play = init_sprite(game->background,
    (sfVector2f) {1, 1}, (sfVector2f) {0, 0});
    game->exit.texture =
        sfTexture_createFromFile(
        "assets/pictures/settings/sliderbar_button.png", NULL);
    game->exit.sprite = sfSprite_create();
    sfSprite_setPosition(game->exit.sprite, (sfVector2f){125, 125});
    sfSprite_setTexture(game->exit.sprite, game->exit.texture, sfFalse);
}
