/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "inventory.h"

void free_inventory(inventory *stock)
{
    for (int i = 0; i < 26; i++) {
        sfRectangleShape_destroy(stock->spot[i].slot);
        sfTexture_destroy(stock->spot[i].item.texture);
        sfSprite_destroy(stock->spot[i].item.sprite);
    }
    for (int i = 0; i < 9; i++) {
        free(stock->asset[i]);
    }
    sfTexture_destroy(stock->background.texture);
    sfSprite_destroy(stock->background.sprite);
}
