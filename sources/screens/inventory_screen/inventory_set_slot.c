/*
** EPITECH PROJECT, 2022
** inventory_set_slot
** File description:
** inventory_set_slot
*/

#include "inventory.h"

void set_slot(box *spot, sfVector2f pos, sfVector2f size, char *asset)
{
    spot->pos = pos;
    set_sprite(&spot->item.sprite, &spot->item.texture, spot->pos, asset);
    set_intrect(&spot->rect, spot->pos, size);
    spot->slot = set_rectangle_shape(spot->slot, size, spot->pos);
    set_intrect(&spot->item.rect, spot->pos, size);
}

void set_box_condition(int i, inventory *stock, int x, int y)
{
    if (i < 20) {
        set_slot(&stock->spot[i],
            (sfVector2f) {1004 + x * 143, 256 + y * 156},
            (sfVector2f) {100, 100}, stock->asset[7]);
        stock->spot[i].type = ALL;
    }
    if (i > 19 && i < 24) {
        set_slot(&stock->spot[i],
            (sfVector2f) {255 , 256 + (i - 20) * 156},
            (sfVector2f) {100, 100}, stock->asset[i - 19]);
        stock->spot[i].type = (TYPE) (i - 20);
    }
    if (i > 23) {
        set_slot(&stock->spot[i],
            (sfVector2f) {410 , 323 + (i - 24) * 311},
            (sfVector2f) {125, 125}, stock->asset[i - 19]);
        sfSprite_setScale(stock->spot[i].item.sprite, (sfVector2f){1.25, 1.25});
    }
}

void set_box(inventory *stock)
{
    int x = 0;
    int y = 0;

    for (int i = 0; i < 26; i++) {
        set_box_condition(i, stock, x, y);
        stock->spot[i].is_empty = true;
        x++;
        if (x > 4) {
            x = 0;
            y++;
        }
    }
    for (int i = 0; i < 7; i++) {
        stock->texture[i] = sfTexture_createFromFile(stock->asset[i + 1], NULL);
    }
    stock->spot[24].type = WEAPON;
    stock->spot[25].type = ARTEFACT;
}
