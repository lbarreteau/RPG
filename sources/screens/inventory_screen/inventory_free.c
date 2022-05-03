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
        sfRectangleShape_destroy(stock->spot[i].slot);
        sfTexture_destroy(stock->spot[i].item.texture);
        sfSprite_destroy(stock->spot[i].item.sprite);
    }
    for (int i = 0; i < 9; i++) {
        if (i < 7)
            sfTexture_destroy(stock->texture[i]);
        free(stock->asset[i]);
    }
    sfTexture_destroy(stock->background.texture);
    sfSprite_destroy(stock->background.sprite);
    free(screen->name_background);
    free(screen->name_screen);
    sfRenderWindow_close(screen->window);
    sfRenderWindow_destroy(screen->window);
}
