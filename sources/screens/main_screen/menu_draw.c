/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "menu_screen.h"

void draw_menu(screens *screen, menus *menu)
{
    sfRenderWindow_clear(screen->window, sfWhite);
    sfRenderWindow_drawSprite(screen->window, screen->background.sprite, NULL);
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawSprite(screen->window, menu->signs[i].sprite, NULL);
        sfRenderWindow_drawText(screen->window,
        menu->name_options[i].text, NULL);
    }
    sfRenderWindow_display(screen->window);
}
