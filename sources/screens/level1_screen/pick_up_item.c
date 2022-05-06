/*
** EPITECH PROJECT, 2022
** pick_up_item
** File description:
** pick_up_item
*/

#include "inventory.h"
#include "level1_screen.h"
#include "player.h"

void add_item(inventory *stock, struct items item)
{
    int i = 0;

    while (stock->spot[i].is_empty == false) {
        i++;
    }
    if (i > 19)
        return;
    sfSprite_setPosition(item.sprite, stock->spot[i].pos);
    stock->spot[i].item.sprite = item.sprite;
    sfSprite_setScale(stock->spot[i].item.sprite, (sfVector2f){1, 1});
    stock->spot[i].item.type = item.type;
    stock->spot[i].item.texture = item.texture;
    stock->spot[i].is_empty = false;
}

void pick_up_item(level1 *game, player *player1, inventory *stock)
{
    for (int i = 0; i < 1; i++) {
        if (sfIntRect_intersects(&player1->hitbox,
        &game->item[i].rect, NULL) == sfTrue) {
            add_item(stock, game->item[i]);
            game->item[i].rect.height = 0;
            game->item[i].rect.width = 0;
            game->item[i].is_pick = true;
        }
    }
}
