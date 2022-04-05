/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "menu_screen.h"

void free_screen(screens *screen)
{
    free(screen->name_screen);
    free(screen->name_background);
    sfTexture_destroy(screen->background.texture);
    sfSprite_destroy(screen->background.sprite);
    sfRenderWindow_close(screen->window);
    sfRenderWindow_destroy(screen->window);
}

void free_menu(screens *screen, menus *menu)
{
    free_screen(screen);
}
