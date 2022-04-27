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
            // sfColor_fromRGBA(139,127,114,175));
    } else {
        sfRectangleShape_setFillColor(shape,
            sfColor_fromRGBA(0,0,0,0));
    }
}

void change_rect(screens *screen, inventory *stock)
{
    for (int i = 0; i < 26; i++) {
        if (i < 20) {
            mouse_on_rect(screen, &stock->spot[i].rect, stock->spot[i].slot);
        } else {
            mouse_on_rect(screen, &stock->spot[i].rect, stock->spot[i].slot);
        }
    }
}

void add_item(inventory *stock, sfTexture *texture)
{
    int i = 0;

    while (stock->spot[i].is_empty == false) {
        i++;
    }
    sfSprite_setTexture(stock->spot[i].item.sprite, texture, sfFalse);
    stock->spot[i].is_empty = false;
}

int mouse_click_slot(screens *screen, inventory *stock)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(screen->window);

    for (int i = 0; i < 26; i++) {
        if (i < 20 && sfIntRect_contains(&stock->spot[i].rect,
            pos_mouse.x, pos_mouse.y) && stock->spot[i].is_empty != true)
            return (i);
        if (i > 19 && sfIntRect_contains(&stock->equipment[i - 20].rect,
            pos_mouse.x, pos_mouse.y) && stock->spot[i].is_empty != true)
            return (i);
    }
    return (-1);
}

void move_in_inventory(screens *screen, inventory *stock)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(screen->window);
    sfVector2f pos = {pos_mouse.x - 50, pos_mouse.y - 50};

    if (stock->nb_slot >= 0 && stock->nb_slot < 20) {
        sfSprite_setPosition(stock->spot[stock->nb_slot].item.sprite, pos);
    }
}

void check_good_move(screens *screen, inventory *stock)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(screen->window);

    for (int i = 0; i < 20; i++) {
        if (sfIntRect_contains(&stock->spot[i].item.rect, pos_mouse.x, pos_mouse.y) && stock->spot[i].is_empty) {
            sfSprite_setTexture(stock->spot[i].item.sprite, sfSprite_getTexture(stock->spot[stock->nb_slot].item.sprite), sfFalse);
            sfSprite_setTexture(stock->spot[stock->nb_slot].item.sprite, sfTexture_createFromFile(stock->asset[7], NULL), sfFalse);
            sfSprite_setPosition(stock->spot[stock->nb_slot].item.sprite,
            (sfVector2f){stock->spot[stock->nb_slot].item.rect.left,
            stock->spot[stock->nb_slot].item.rect.top});
            stock->spot[stock->nb_slot].is_empty = true;
            stock->spot[i].is_empty = false;
            return;
        }
    }
    sfSprite_setPosition(stock->spot[stock->nb_slot].item.sprite,
    (sfVector2f){stock->spot[stock->nb_slot].item.rect.left,
    stock->spot[stock->nb_slot].item.rect.top});
    // for (int i = 0; i < 20; i++) {
    //     if (stock->spot[stock->nb_slot].item.rect)
    // }
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
