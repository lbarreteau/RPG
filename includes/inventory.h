/*
** EPITECH PROJECT, 2022
** inventory
** File description:
** inventory
*/

#pragma once

#include "global.h"

typedef enum {NOTHING = -1, HELMET, CHESTPLATE, LEGGINGS, BOOTS, WEAPON, ARTEFACT, ALL} TYPE;

typedef struct items {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    TYPE type;
    bool is_pick;
} items;

typedef struct box {
    sfVector2f pos;
    sfRectangleShape *slot;
    sfIntRect rect;
    struct items item;
    TYPE type;
    bool is_empty;
} box;

typedef struct inventory {
    struct sprite background;
    char *asset[9];
    sfTexture *texture[7];
    struct box spot[26];
    int nb_slot;
} inventory;

void event_inventory(screens *screen, inventory *box);
void draw_inventory(screens *screen, inventory *stock);
void init_inventory_struct(inventory *stock);
void set_inventory(inventory *stock);
void free_inventory(screens *screen, inventory *stock);
void check_good_move(screens *screen, inventory *stock);
void set_box(inventory *stock);
void set_sprite(sfSprite **sprite, sfTexture **texture, sfVector2f pos, char *asset);
void set_intrect(sfIntRect *rect, sfVector2f pos, sfVector2f size);
sfRectangleShape *set_rectagle_shape(sfRectangleShape *shape ,sfVector2f size, sfVector2f pos);
void mouse_on_rect(screens *screen, sfIntRect *rect, sfRectangleShape *shape);
int mouse_click_slot(screens *screen, inventory *stock);
void move_in_inventory(screens *screen, inventory *stock);