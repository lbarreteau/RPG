/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "settings_screen.h"

static void free_screen(screens *screen)
{
    free(screen->name_screen);
    free(screen->name_background);
    sfTexture_destroy(screen->background.texture);
    sfTexture_destroy(screen->background.texture_dark);
    sfSprite_destroy(screen->background.sprite);
    sfRenderWindow_close(screen->window);
    sfRenderWindow_destroy(screen->window);
}

static void free_sprite(settings *setting)
{
    for (int i = 0; i < 4; i++) {
        sfTexture_destroy(setting->vlm.sprite[i].texture);
        sfTexture_destroy(setting->vlm.sprite[i].texture_dark);
        sfSprite_destroy(setting->vlm.sprite[i].sprite);
        free(setting->asset_btn[i]);
    }
    for (int i = 0; i < 3; i++) {
        sfTexture_destroy(setting->fps.sprite[i].texture);
        sfTexture_destroy(setting->fps.sprite[i].texture_dark);
        sfSprite_destroy(setting->fps.sprite[i].sprite);
        free(setting->asset_btn[i + 4]);
    }
}

void free_settings(screens *screen, settings *setting)
{
    free_sprite(setting);
    free_screen(screen);
}
