/*
** EPITECH PROJECT, 2022
** move_items
** File description:
** move_items
*/

#include "inventory.h"

int set_item_in_new_slot(int i, inventory *stock)
{
    if (stock->spot[i].type == stock->spot[stock->nb_slot].item.type ||
    stock->spot[i].type == ALL) {
        sfSprite_setTexture(stock->spot[i].item.sprite,
        sfSprite_getTexture(stock->spot[stock->nb_slot].item.sprite), sfFalse);
        if (stock->nb_slot > 19) {
            sfSprite_setTexture(stock->spot[stock->nb_slot].item.sprite,
            sfTexture_createFromFile(
            stock->asset[stock->nb_slot - 19], NULL), sfFalse);
        } else {
            sfSprite_setTexture(stock->spot[stock->nb_slot].item.sprite,
            sfTexture_createFromFile(stock->asset[7], NULL), sfFalse);
        }
        sfSprite_setPosition(stock->spot[stock->nb_slot].item.sprite,
        (sfVector2f){stock->spot[stock->nb_slot].item.rect.left,
        stock->spot[stock->nb_slot].item.rect.top});
        stock->spot[i].item.type = stock->spot[stock->nb_slot].item.type;
        stock->spot[stock->nb_slot].is_empty = true;
        stock->spot[i].is_empty = false;
        return (1);
    }
    return (0);
}

int check_in_slot(int i, inventory *stock, sfVector2i pos_mouse)
{
    if (sfIntRect_contains(&stock->spot[i].item.rect,
    pos_mouse.x, pos_mouse.y) && stock->spot[i].is_empty) {
        if (set_item_in_new_slot(i, stock) == 1)
            return (1);
    }
    return (0);
}

void check_good_move(screens *screen, inventory *stock)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(screen->window);

    for (int i = 0; i < 26; i++) {
        if (check_in_slot(i, stock, pos_mouse) == 1)
            return;
    }
    sfSprite_setPosition(stock->spot[stock->nb_slot].item.sprite,
    (sfVector2f){stock->spot[stock->nb_slot].item.rect.left,
    stock->spot[stock->nb_slot].item.rect.top});
}