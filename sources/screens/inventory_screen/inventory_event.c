/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
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

void change_rect(screens *screen, inventory *stock)
{
    for (int i = 0; i < 26; i++) {
        mouse_on_rect(screen, &stock->spot[i].rect, stock->spot[i].slot);
    }
}

void add_item(inventory *stock, sfTexture *texture)
{
    int i = 0;

    while (stock->spot[i].is_empty == false) {
        i++;
    }
    sfSprite_setTexture(stock->spot[i].item.sprite, texture, sfFalse);
    stock->spot[i].item.type = WEAPON;
    stock->spot[i].is_empty = false;
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

bool event_inventory(screens *screen, inventory *stock)
{
    if (screen->event.type == sfEvtClosed) {
        return (true);
    }
    change_rect(screen, stock);
    if (screen->event.key.type == sfEvtKeyPressed) {
        if (sfKeyboard_isKeyPressed(sfKeyI) == true) {
            add_item(stock, sfTexture_createFromFile(stock->asset[8], NULL));
        }
    }
    if (screen->event.type == sfEvtMouseButtonPressed &&
    screen->event.mouseButton.button == sfMouseLeft) {
        stock->nb_slot = mouse_click_slot(screen, stock);
    }
    if (screen->event.type == sfEvtMouseButtonReleased) {
        if (stock->nb_slot != -1)
            check_good_move(screen, stock);
        stock->nb_slot = -1;
    }
    move_in_inventory(screen, stock);
    return (false);
}
