/*
** EPITECH PROJECT, 2022
** mouse_events
** File description:
** mouse_events
*/

#include "inventory.h"

void mouse_on_rect(screens *screen, sfIntRect *rect, sfRectangleShape *shape)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(screen->window);

    if (sfIntRect_contains(rect, pos_mouse.x, pos_mouse.y)) {
        sfRectangleShape_setFillColor(shape,
            sfColor_fromRGBA(254,80,24,175));
    } else {
        sfRectangleShape_setFillColor(shape,
            sfColor_fromRGBA(0,0,0,0));
    }
}

int mouse_click_slot(screens *screen, inventory *stock)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(screen->window);

    for (int i = 0; i < 26; i++) {
        if (sfIntRect_contains(&stock->spot[i].rect,
            pos_mouse.x, pos_mouse.y) && stock->spot[i].is_empty != true) {
            return (i);
        }
    }
    return (-1);
}

void move_in_inventory(screens *screen, inventory *stock)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(screen->window);
    sfVector2f pos = {pos_mouse.x - 50, pos_mouse.y - 50};

    if (stock->nb_slot >= 0) {
        sfSprite_setPosition(stock->spot[stock->nb_slot].item.sprite, pos);
    }
}
