/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "inventory.h"

void set_box(inventory *stock)
{
    int x = 0;
    int y = 0;

    for (int i = 0; i < 20; i++) {
        stock->spot[i].pos = (sfVector2f) {1004 + x * 143, 256 + y * 156};
        stock->spot[i].rect = sfRectangleShape_create();
        sfRectangleShape_setPosition(stock->spot[i].rect, stock->spot[i].pos);
        sfRectangleShape_setSize(stock->spot[i].rect, (sfVector2f){100, 100});
        stock->spot[i].is_empty = true;
        x++;
        if (x > 4) {
            x = 0;
            y++;
        }
    }
}

void set_equipment(inventory *stock)
{
    for (int i = 0; i < 4; i++) {
        stock->equipment[i].pos = (sfVector2f) {255 , 256 + i * 156};
        stock->equipment[i].rect = sfRectangleShape_create();
        sfRectangleShape_setPosition(stock->equipment[i].rect,
            stock->equipment[i].pos);
        sfRectangleShape_setSize(stock->equipment[i].rect,
            (sfVector2f){100, 100});
        stock->equipment[i].items.texture =
            sfTexture_createFromFile(stock->asset[i + 1], NULL);
        stock->equipment[i].items.sprite = sfSprite_create();
        sfSprite_setTexture(stock->equipment[i].items.sprite,
            stock->equipment[i].items.texture, sfFalse);
        sfSprite_setPosition(stock->equipment[i].items.sprite,
            stock->equipment[i].pos);
        stock->equipment[i].is_empty = true;
    }
}

void set_tools(inventory *stock)
{
    for (int i = 4; i < 6; i++) {
        stock->equipment[i].pos = (sfVector2f) {410 , 323 + (i - 4) * 311};
        stock->equipment[i].rect = sfRectangleShape_create();
        sfRectangleShape_setPosition(stock->equipment[i].rect,
            stock->equipment[i].pos);
        sfRectangleShape_setSize(stock->equipment[i].rect,
            (sfVector2f){125, 125});
        stock->equipment[i].items.texture =
            sfTexture_createFromFile(stock->asset[i + 1], NULL);
        stock->equipment[i].items.sprite = sfSprite_create();
        sfSprite_setTexture(stock->equipment[i].items.sprite,
            stock->equipment[i].items.texture, sfFalse);
        sfSprite_setPosition(stock->equipment[i].items.sprite,
            stock->equipment[i].pos);
        stock->equipment[i].is_empty = true;
    }
}

void set_inventory(screens *global, inventory *stock)
{
    stock->background.texture =
        sfTexture_createFromFile(stock->asset[0], NULL);
    stock->background.sprite = sfSprite_create();
    sfSprite_setPosition(stock->background.sprite, (sfVector2f){0, 0});
    sfSprite_setTexture(stock->background.sprite,
        stock->background.texture, sfFalse);
    set_box(stock);
    set_equipment(stock);
    set_tools(stock);
}
