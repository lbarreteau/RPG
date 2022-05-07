/*
** EPITECH PROJECT, 2022
** menu_pause_event.c
** File description:
** menu_pause_event
*/

#include "global.h"
#include "menu_screen.h"

static bool redirection_screen(int nb_screen, screens *screen, menus *menu)
{
    switch (nb_screen) {
        case 0:
            return (true);
        case 1:
            return (settings_screen(screen));
        case 2:
            how_to_play_screen(screen);
            return (true);
        case 3:
            return (true);
        default:
            return (false);
    }
}

static bool mouse_clicked_on_button(screens *screen, sfSprite *sign,
    menus *menu, int i)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(screen->window);
    sfVector2f pos_button = sfSprite_getPosition(sign);
    float size = 1920 / 1080;
    float real_size = menu->size_screen.x / menu->size_screen.y;

    if (pos_mouse.x >= pos_button.x && pos_mouse.x <= pos_button.x + (512 *
        real_size / size) && pos_mouse.y >= pos_button.y && pos_mouse.y <=
        pos_button.y + (116 * real_size / size)) {
        sfMusic_play(screen->music[1]);
        sfSprite_setTexture(sign, menu->texture_dark, sfFalse);
        return (redirection_screen(i, screen, menu));
    }
    return (false);
}

static void mouse_on_button(screens *screen, sfSprite *sign, menus *menu, int i)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(screen->window);
    sfVector2f pos_button = sfSprite_getPosition(sign);

    float size = 1920 / 1080;
    float real_size = menu->size_screen.x / menu->size_screen.y;

    if (pos_mouse.x >= pos_button.x && pos_mouse.x <= pos_button.x + (512 *
    real_size / size) && pos_mouse.y >= pos_button.y && pos_mouse.y <=
        pos_button.y + (116 * real_size / size)) {
        sfSprite_setTexture(sign, menu->texture_dark, sfFalse);
    } else {
        sfSprite_setTexture(sign, menu->signs[i].texture, sfFalse);
    }
}

bool event_menu_pause(screens *screen, menus *menu)
{
    bool exit = false;

    if (screen->event.type == sfEvtClosed) {
        return (true);
    }
    if (screen->event.type == sfEvtMouseMoved) {
        for (int i = 0; i < 4; i++) {
            mouse_on_button(screen, menu->signs[i].sprite, menu, i);
        }
    }
    if (screen->event.type == sfEvtMouseButtonPressed) {
        for (int i = 0; i < 4 && exit != true; i++) {
            exit = mouse_clicked_on_button(screen, menu->signs[i].sprite,
                                            menu, i);
        }
    }
    return (exit);
}