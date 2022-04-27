/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "inventory.h"

void draw_inventory(screens *screen, inventory *stock)
{
    sfRenderWindow_clear(screen->window, sfWhite);
    sfRenderWindow_drawSprite(screen->window, stock->background.sprite, NULL);
    for (int i = 0; i < 26; i++) {
        if (i < 20) {
            sfRenderWindow_drawSprite(screen->window,
                stock->spot[i].item.sprite, NULL);
            sfRenderWindow_drawRectangleShape(screen->window,
                stock->spot[i].slot, NULL);
        } else {
            sfRenderWindow_drawRectangleShape(screen->window,
                stock->equipment[i - 20].slot, NULL);
            sfRenderWindow_drawSprite(screen->window,
                stock->equipment[i - 20].item.sprite, NULL);
        }
    }
    sfRenderWindow_display(screen->window);
}
