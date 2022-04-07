/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "menu_screen.h"

void set_screen(screens *screen)
{
    screen->window = sfRenderWindow_create(screen->mode, screen->name_screen,
    sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(screen->window, screen->fps);
    screen->background = init_sprite(screen->name_background,
    (sfVector2f) {2.5, 2.5}, (sfVector2f) {0, 0});
}

void set_menu(menus *menu)
{
    menu->start_game = init_sprite(menu->name_start_game,
    (sfVector2f) {1.5, 1.5}, (sfVector2f) {600, 740});
    menu->settings = init_sprite(menu->name_start_game,
    (sfVector2f) {0.5, 1}, (sfVector2f) {1650, 20});
}
