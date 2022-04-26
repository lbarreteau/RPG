/*
** EPITECH PROJECT, 2022
** inventory
** File description:
** inventory
*/

#pragma once

#include "global.h"

typedef struct box {
    sfVector2f pos;
    sfRectangleShape *rect;
    struct sprite items;
    bool is_empty;
} box;

typedef struct inventory {
    struct sprite background;
    char *asset[7];
    struct box spot[20];
    struct box equipment[6];
} inventory;

bool event_inventory(screens *screen, inventory *box);
void draw_inventory(screens *screen, inventory *stock);
void init_inventory_struct(inventory *stock);
void set_inventory(screens *global, inventory *stock);
void free_inventory(screens *screen, inventory *stock);