/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "level1_screen.h"
#include "player.h"

void draw_dialog(screens *screen, level1 *game)
{
    if (game->dialog_active == true) {
        sfText_setString(game->dialog.text, "\t\tOnce upon a time there was"
        " a calm\nand peaceful dungeon but a villain has taken it\n\t\t  over"
        " and will fight it to deliver.");
        sfRenderWindow_drawSprite(screen->window,
            game->background_dialog.sprite, NULL);
        sfRenderWindow_drawText(screen->window, game->dialog.text, NULL);
    }
    if (game->dialog_active_2 == true) {
        sfText_setString(game->dialog_2.text,
        "ezregfksqdvniklabacbvpsdonbacmzaeepjdio\n"
        "aoeziruqsdfghfklqosdfgkldgghkluiydfsdffdb");
        sfRenderWindow_drawSprite(screen->window,
            game->background_dialog_2.sprite, NULL);
        sfRenderWindow_drawText(screen->window, game->dialog_2.text, NULL);
    }
}

void draw_entity(screens *screen, level1 *game, player *player1)
{
    sfSprite_setTexture(player1->sprite, player1->texture, sfFalse);
    sfSprite_setTextureRect(player1->sprite, player1->rect);
    sfRenderWindow_drawSprite(screen->window, player1->stat.sprite[0], NULL);
    sfRenderWindow_drawSprite(screen->window, player1->stat.sprite[1], NULL);
    sfRenderWindow_drawSprite(screen->window, game->pnj.sprite, NULL);
    sfRenderWindow_drawSprite(screen->window, game->pnj_2.sprite, NULL);
    sfRenderWindow_drawSprite(screen->window, player1->sprite, NULL);
}

void draw_level1(screens *screen, level1 *game, player *player1)
{
    sfRenderWindow_clear(screen->window, sfBlack);
    sfRenderWindow_drawSprite(screen->window, game->map.sprite, NULL);
    for (int i = 0; i < 2; i++) {
        if (game->item[i].is_pick == false) {
            sfRenderWindow_drawSprite(screen->window,
            game->item[i].sprite, NULL);
        }
    }
    draw_entity(screen, game, player1);
    sfSprite_setTexture(game->enemy.sprite, game->enemy.texture, sfFalse);
    sfSprite_setTextureRect(game->enemy.sprite, game->enemy.rect);
    //sfRenderWindow_drawSprite(screen->window, game->enemy.sprite, NULL);
    if (screen->inv_is_set == true)
        draw_inventory(screen, &game->stock, player1);
    sfRenderWindow_drawSprite(screen->window, game->buffer->sprite, NULL);
    draw_dialog(screen, game);
}
