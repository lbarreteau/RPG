/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "inventory.h"

void set_sprite(sfSprite **sprite, sfTexture **texture,
sfVector2f pos, char *asset)
{
    (*texture) = sfTexture_createFromFile(asset, NULL);
    (*sprite) = sfSprite_create();
    sfSprite_setTexture((*sprite), (*texture), sfFalse);
    sfSprite_setPosition((*sprite), pos);
}

void set_intrect(sfIntRect *rect, sfVector2f pos, sfVector2f size)
{
    rect->height = size.y;
    rect->width = size.x;
    rect->left = pos.x;
    rect->top = pos.y;
}

sfRectangleShape *set_rectagle_shape(sfRectangleShape *shape ,sfVector2f size, sfVector2f pos)
{
    shape = sfRectangleShape_create();
    sfRectangleShape_setPosition(shape, pos);
    sfRectangleShape_setSize(shape, size);
    sfRectangleShape_setFillColor(shape, sfTransparent);
    return (shape);
}

void set_box(inventory *stock)
{
    int x = 0;
    int y = 0;

    for (int i = 0; i < 20; i++) {
        stock->spot[i].pos = (sfVector2f) {1004 + x * 143, 256 + y * 156};
        set_intrect(&stock->spot[i].rect, stock->spot[i].pos,
            (sfVector2f){100, 100});
        stock->spot[i].slot = set_rectagle_shape(stock->spot[i].slot,
            (sfVector2f){100, 100}, stock->spot[i].pos);
        set_sprite(&stock->spot[i].item.sprite, &stock->spot[i].item.texture,
            stock->spot[i].pos, stock->asset[7]);
        set_intrect(&stock->spot[i].item.rect, stock->spot[i].pos,
            (sfVector2f){100, 100});
        stock->spot[i].is_empty = true;
        stock->spot[i].type = ALL;
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
        set_intrect(&stock->equipment[i].rect, stock->equipment[i].pos,
            (sfVector2f){100, 100});
        stock->equipment[i].slot = set_rectagle_shape(stock->equipment[i].slot,
            (sfVector2f){100, 100}, stock->equipment[i].pos);
        set_sprite(&stock->equipment[i].item.sprite, &stock->equipment[i].item.texture,
            stock->equipment[i].pos, stock->asset[i + 1]);
        stock->equipment[i].is_empty = true;
        stock->equipment[i].type = ARMOR;
    }
}

void set_tools(inventory *stock)
{
    for (int i = 4; i < 6; i++) {
        stock->equipment[i].pos = (sfVector2f) {410 , 323 + (i - 4) * 311};
        set_intrect(&stock->equipment[i].rect, stock->equipment[i].pos,
            (sfVector2f){125, 125});
        stock->equipment[i].slot = set_rectagle_shape(stock->equipment[i].slot,
            (sfVector2f){125, 125}, stock->equipment[i].pos);
        set_sprite(&stock->equipment[i].item.sprite, &stock->equipment[i].item.texture,
            stock->equipment[i].pos, stock->asset[i + 1]);
        stock->equipment[i].is_empty = true;
    }
    stock->equipment[4].type = WEAPON;
    stock->equipment[5].type = ARTEFACT;
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
    stock->nb_slot = -1;
}
