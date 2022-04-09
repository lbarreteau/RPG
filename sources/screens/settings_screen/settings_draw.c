/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "settings_screen.h"

void draw_settings(screens *screen, settings *setting)
{
    sfRenderWindow_clear(screen->window, sfWhite);
    sfRenderWindow_drawSprite(screen->window, screen->background.sprite, NULL);
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawSprite(screen->window,
            setting->vlm_setting.sprite_vlm[i].sprite, NULL);
    }
    sfRenderWindow_display(screen->window);
}
