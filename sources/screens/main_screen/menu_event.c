/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "menu_screen.h"

void mouse_clicked_on_button(screens *screen, sfSprite *sign, menus *menu,
    int i)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(screen->window);
    sfVector2f pos_button = sfSprite_getPosition(sign);

    if (pos_mouse.x >= pos_button.x && pos_mouse.x <= pos_button.x + 512 &&
            pos_mouse.y >= pos_button.y && pos_mouse.y <= pos_button.y + 116) {
        sfTexture_destroy(menu->signs[i].texture);
        menu->signs[i].texture = sfTexture_createFromFile(menu->name_sign_dark,
        NULL);
        sfSprite_setTexture(sign, menu->signs[i].texture, sfFalse);
    }
}

void mouse_on_button(screens *screen, sfSprite *sign, menus *menu, int i)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(screen->window);
    sfVector2f pos_button = sfSprite_getPosition(sign);

    if (pos_mouse.x >= pos_button.x && pos_mouse.x <= pos_button.x + 512 &&
            pos_mouse.y >= pos_button.y && pos_mouse.y <= pos_button.y + 116) {
        sfTexture_destroy(menu->signs[i].texture);
        menu->signs[i].texture = sfTexture_createFromFile(menu->name_sign_dark,
        NULL);
        sfSprite_setTexture(sign, menu->signs[i].texture, sfFalse);
    } else {
        sfTexture_destroy(menu->signs[i].texture);
        menu->signs[i].texture = sfTexture_createFromFile(menu->name_sign,
        NULL);
        sfSprite_setTexture(sign, menu->signs[i].texture, sfFalse);
    }

}

bool event_menu(screens *screen, menus *menu)
{
    if (screen->event.type == sfEvtClosed) {
        return (true);
    }
    if (screen->event.type == sfEvtMouseMoved) {
        for (int i = 0; i < 4; i++) {
            mouse_on_button(screen, menu->signs[i].sprite, menu, i);
        }
    }
    if (screen->event.type == sfEvtMouseButtonPressed) {
        for (int i = 0; i < 4; i++) {
            mouse_clicked_on_button(screen, menu->signs[i].sprite, menu, i);
        }
    }
    return (false);
}
