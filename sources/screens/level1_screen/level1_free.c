/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "level1_screen.h"

static void free_sprite(sfSprite *sprite, sfTexture *texture)
{
    sfTexture_destroy(texture);
    sfSprite_destroy(sprite);
}

void free_text(sfText *text, sfFont *font)
{
    sfText_destroy(text);
    sfFont_destroy(font);
}

void free_all_sprite(level1 *game)
{
    free_sprite(game->player1->sprite, game->player1->texture);
    free_sprite(game->pnj.sprite, game->pnj.texture);
    free_sprite(game->pnj_2.sprite, game->pnj_2.texture);
    free_sprite(game->map.sprite, game->map.texture);
    free_sprite(game->background_dialog.sprite,
        game->background_dialog.texture);
    free_sprite(game->background_dialog_2.sprite,
        game->background_dialog_2.texture);
    free_sprite(game->enemy[0].sprite, game->enemy[0].texture);
    free_sprite(game->enemy[1].sprite, game->enemy[1].texture);
    for (int i = 0; i < 2; i++) {
        free_sprite(game->player1->stat.sprite[i],
            game->player1->stat.texture[i]);
    }
}

void free_all_text(level1 *game)
{
    free_text(game->player1->stat.text_stat[0].text,
        game->player1->stat.text_stat[0].font);
    free_text(game->player1->stat.text_stat[1].text,
        game->player1->stat.text_stat[1].font);
    free_text(game->dialog.text, game->dialog.font);
    free_text(game->dialog_2.text, game->dialog_2.font);
}

void free_level1(level1 *game)
{
    free_all_sprite(game);
    free_all_text(game);
    for (int i = 0; i < 21; i++) {
        sfRectangleShape_destroy(game->collisions[i].border);
    }
    free(game->collisions);
    free_inventory(&game->stock);
    sfClock_destroy(game->clock);
    free(game->name_screen_background);
    for (int i = 0; i < 2; i++) {
        if (game->item[i].is_pick == false) {
            sfSprite_destroy(game->item[i].sprite);
            sfTexture_destroy(game->item[i].texture);
        }
    }
    free(game->name_pnj);
    free(game->name_pnj_2);
}
