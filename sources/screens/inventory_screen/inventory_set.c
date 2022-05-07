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

sfRectangleShape *set_rectagle_shape(sfRectangleShape *shape,
    sfVector2f size, sfVector2f pos)
{
    shape = sfRectangleShape_create();
    sfRectangleShape_setPosition(shape, pos);
    sfRectangleShape_setSize(shape, size);
    sfRectangleShape_setFillColor(shape, sfTransparent);
    return (shape);
}

void set_inventory(inventory *stock)
{
    stock->background.texture =
        sfTexture_createFromFile(stock->asset[0], NULL);
    stock->background.sprite = sfSprite_create();
    sfSprite_setPosition(stock->background.sprite, (sfVector2f){0, 0});
    sfSprite_setTexture(stock->background.sprite,
        stock->background.texture, sfFalse);
    set_box(stock);
    stock->nb_slot = -1;
}
