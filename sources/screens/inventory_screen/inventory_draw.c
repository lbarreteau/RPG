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
        if (i < 20)
            sfRenderWindow_drawRectangleShape(screen->window,
                stock->spot[i].rect, NULL);
        else
            sfRenderWindow_drawRectangleShape(screen->window,
                stock->equipment[i - 20].rect, NULL);
    }
    for (int i = 0; i < 6; i++) {
        sfRenderWindow_drawSprite(screen->window,
            stock->equipment[i].items.sprite, NULL);
    }
    sfRenderWindow_display(screen->window);
}
