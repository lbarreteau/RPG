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

void free_sprite(menus *menu)
{
    free(menu->name_sign);
    free(menu->name_sign_dark);
    free(menu->name_music);
    for (int i = 0; i < 4; i++) {
        sfTexture_destroy(menu->signs[i].texture);
        sfTexture_destroy(menu->signs[i].texture_dark);
        sfSprite_destroy(menu->signs[i].sprite);
        sfFont_destroy(menu->name_options[i].font);
        sfText_destroy(menu->name_options[i].text);
    }
}

void free_menu(screens *screen, menus *menu)
{
    sfFont_destroy(menu->title.font);
    sfText_destroy(menu->title.text);
    sfMusic_stop(menu->background_music);
    sfMusic_destroy(menu->background_music);
    free_sprite(menu);
    free_screen(screen);
}
