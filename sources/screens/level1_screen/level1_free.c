/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "level1_screen.h"

static void free_screen(screens *screen)
{
    free(screen->name_screen);
    free(screen->name_background);
    sfTexture_destroy(screen->background.texture);
    sfSprite_destroy(screen->background.sprite);
    sfRenderWindow_close(screen->window);
    sfRenderWindow_destroy(screen->window);
}

static void free_sprite(level1 *game)
{
}

void free_level1(screens *screen, level1 *game)
{
    free_sprite(game);
    free_screen(screen);
}
