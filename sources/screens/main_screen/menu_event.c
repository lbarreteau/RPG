/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "menu_screen.h"

static void redirection_screen(int nb_screen, screens *screen)
{
    //free_sprite(menu);
    switch (nb_screen) {
        case 0:
            level1_screen(screen);
            exit(0);
            break;
        case 1:
            
            break;
        case 2:
            
            break;
        case 3:
            exit(0);
            break;
        default:
            break;
    }
}

static void mouse_clicked_on_button(screens *screen, sfSprite *sign, menus *menu,
    int i)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(screen->window);
    sfVector2f pos_button = sfSprite_getPosition(sign);
    float size = 1920/ 1080;
    float real_size = menu->size_screen.x / menu->size_screen.y;

    if (pos_mouse.x >= pos_button.x && pos_mouse.x <= pos_button.x + (512 *
            real_size / size) && pos_mouse.y >= pos_button.y && pos_mouse.y <=
        pos_button.y + (116 * real_size / size)) {
        sfSprite_setTexture(sign, menu->signs[i].texture_dark, sfFalse);
        redirection_screen(i, screen);
    }
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
        sfSprite_setTexture(sign, menu->signs[i].texture_dark, sfFalse);
    } else {
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
