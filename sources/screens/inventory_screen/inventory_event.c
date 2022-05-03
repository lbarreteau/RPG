/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "inventory.h"

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
    if (i > 19)
        return;
    sfSprite_setTexture(stock->spot[i].item.sprite, texture, sfFalse);
    stock->spot[i].item.type = HELMET;
    stock->spot[i].is_empty = false;
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
