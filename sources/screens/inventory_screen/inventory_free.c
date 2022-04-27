/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "inventory.h"


void free_inventory(screens *screen, inventory *stock)
{
    for (int i = 0; i < 26; i++) {
        if (i < 20) {
            sfRectangleShape_destroy(stock->spot[i].slot);
        } else {
            sfTexture_destroy(stock->equipment[i - 20].item.texture);
            sfSprite_destroy(stock->equipment[i - 20].item.sprite);
            sfRectangleShape_destroy(stock->equipment[i - 20].slot);
        }
    }
    for (int i = 0; i < 7; i++) {
        free(stock->asset[i]);
    }
    sfTexture_destroy(stock->background.texture);
    sfSprite_destroy(stock->background.sprite);
    free(screen->name_background);
    free(screen->name_screen);
    sfRenderWindow_close(screen->window);
    sfRenderWindow_destroy(screen->window);
}
