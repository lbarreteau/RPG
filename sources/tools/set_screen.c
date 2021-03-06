/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"

void set_screen(screens *screen)
{
    screen->window = sfRenderWindow_create(screen->mode, screen->name_screen,
    sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(screen->window, screen->fps);
    screen->background = init_sprite(screen->name_background,
    (sfVector2f) {4.5, 4.5}, (sfVector2f) {0, 0});
}
