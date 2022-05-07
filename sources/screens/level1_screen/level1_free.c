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
    free_inventory(&game->stock);
    for (int i = 0; i < 2; i++) {
        sfSprite_destroy(game->player1->stat.sprite[i]);
        sfTexture_destroy(game->player1->stat.texture[i]);
    }
    sfText_destroy(game->player1->stat.text_dammage.text);
    sfFont_destroy(game->player1->stat.text_dammage.font);
    sfSprite_destroy(game->player1->sprite);
    sfTexture_destroy(game->player1->texture);
}
