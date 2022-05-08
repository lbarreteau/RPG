/*
** EPITECH PROJECT, 2022
** set_items
** File description:
** set_items
*/

#include "inventory.h"
#include "level1_screen.h"

void move_items(level1 *game, sfVector2f movement)
{
    sfVector2f new_pos = {0, 0};

    for (int i = 0; i < 2; i++) {
        if (game->item[i].is_pick == false) {
            new_pos = sfSprite_getPosition(game->item[i].sprite);
            new_pos.x += movement.x;
            new_pos.y += movement.y;
            sfSprite_setPosition(game->item[i].sprite, new_pos);
            game->item[i].rect.top = new_pos.y;
            game->item[i].rect.left = new_pos.x;
        }
    }
}

void init_item(items *item, char *asset, sfVector2f pos, TYPE type)
{
    item->texture = sfTexture_createFromFile(asset, NULL);
    item->sprite = sfSprite_create();
    sfSprite_setTexture(item->sprite, item->texture, sfFalse);
    sfSprite_setPosition(item->sprite, pos);
    sfSprite_setScale(item->sprite, (sfVector2f){0.5, 0.5});
    item->rect.height = sfTexture_getSize(item->texture).y * 0.5;
    item->rect.width = sfTexture_getSize(item->texture).x * 0.5;
    item->rect.top = pos.y;
    item->rect.left = pos.x;
    item->type = type;
    item->is_pick = false;
}

void set_items(level1 *game, inventory *stock)
{
    init_item(&game->item[0], stock->asset[8],
        (sfVector2f){300, 2250}, WEAPON);
    init_item(&game->item[1], stock->asset[9],
        (sfVector2f){3050, 1750}, NOTHING);
}
