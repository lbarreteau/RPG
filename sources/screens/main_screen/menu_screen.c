/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "menu_screen.h"

void update_background_pos(screens *screen)
{
    sfVector2f pos_bkd = sfSprite_getPosition(screen->background.sprite);

    if (pos_bkd.y >= -3900) {
        pos_bkd.y -= 0.5;
    }
    sfSprite_setPosition(screen->background.sprite, pos_bkd);
}

void main_screen(void)
{
    struct screens screen;
    struct menus menu;
    bool exit = false;

    init_screen_struct(&screen);
    init_menu_struct(&menu);
    set_screen(&screen);
    set_menu(&menu);
    while (sfRenderWindow_isOpen(screen.window)) {
        while (sfRenderWindow_pollEvent(screen.window, &screen.event)) {
            exit = event_menu(&screen, &menu);
        }
        if (exit == true) {
            free_menu(&screen, &menu);
            return;
        }
        update_background_pos(&screen);
        draw_menu(&screen, &menu);
    }
}
