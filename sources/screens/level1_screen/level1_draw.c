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
        sfText_setString(game->dialog.text, "\t\tPlease, help me. My twins"
        " brothers\nare possessed by the dungeon and are crazy.\n\t\t"
        " You must give them back please.");
        sfRenderWindow_drawSprite(screen->window,
            game->background_dialog.sprite, NULL);
        sfRenderWindow_drawText(screen->window, game->dialog.text, NULL);
    }
    if (game->dialog_active_2 == true) {
        sfText_setString(game->dialog_2.text,
        "\tI can control the dungeaon for a while but\n"
        "\t\tmy brothers under are submerged, \n\t\t\t\t\t\tplease help them");
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
    for (int i = 0; i < 2; i++) {
        sfSprite_setTexture(game->enemy[i].sprite,
            game->enemy[i].texture, sfFalse);
        sfSprite_setTextureRect(game->enemy[i].sprite, game->enemy[i].rect);
        if (game->enemy[i].is_alive == true) {
            sfRenderWindow_drawSprite(screen->window,
                game->enemy[i].sprite, NULL);
        }
    }
}

void draw_win_screen(screens *screen, level1 *game)
{
    sfText *win = sfText_create();
    sfTime time;
    game->win_screen_clock = sfClock_create();

    time = sfClock_getElapsedTime(game->win_screen_clock);
    sfRenderWindow_clear(screen->window, sfBlack);
    sfText_setFont(win, game->font);
    sfText_setString(win, "Congratulations, You win :)");
    sfText_setOutlineColor(win, sfYellow);
    sfText_setCharacterSize(win, 50);
    sfText_setColor(win, sfRed);
    sfText_setPosition(win, (sfVector2f) {550, 500});
    while (time.microseconds <= 5000000) {
        sfRenderWindow_drawText(screen->window, win, NULL);
        sfRenderWindow_display(screen->window);
        time = sfClock_getElapsedTime(game->win_screen_clock);
    }
    screen->is_dead = true;
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
    if (screen->inv_is_set == true)
        draw_inventory(screen, &game->stock, player1);
    sfRenderWindow_drawSprite(screen->window, game->buffer->sprite, NULL);
    draw_water(game, game->buffer->water_active, game->buffer->snow_active);
    draw_snow(game, game->buffer->snow_active, game->buffer->water_active);
    draw_dialog(screen, game);
    sfRenderWindow_display(screen->window);
    if (game->enemy[0].is_alive == false && game->enemy[1].is_alive == false) {
        draw_win_screen(screen, game);
        screen->is_dead = true;
    }
}
