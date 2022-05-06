/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "inventory.h"
#include "player.h"

void draw_inventory(screens *screen, inventory *stock, player *player1)
{
    sfRenderWindow_drawSprite(screen->window, stock->background.sprite, NULL);
    for (int i = 0; i < 26; i++) {
        sfRenderWindow_drawSprite(screen->window,
            stock->spot[i].item.sprite, NULL);
        sfRenderWindow_drawRectangleShape(screen->window,
            stock->spot[i].slot, NULL);
    }
    sfRenderWindow_drawText(screen->window, player1->stat.text_dammage.text, NULL);
}
