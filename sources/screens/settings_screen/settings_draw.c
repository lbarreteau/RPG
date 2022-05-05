/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "settings_screen.h"

void draw_controls(screens *screen, settings *setting)
{
    for (int i = 0; i < 5; i++) {
        if (setting->controls.wait_key[i] == false) {
            sfRenderWindow_drawSprite(screen->window,
                setting->controls.sprite[i * 2].sprite, NULL);
        } else {
            sfRenderWindow_drawSprite(screen->window,
                setting->controls.sprite[i * 2 + 1].sprite, NULL);
        }
        sfRenderWindow_drawText(screen->window,
            setting->controls.text[i].text, NULL);
    }
    sfRenderWindow_drawSprite(screen->window, setting->exit.sprite, NULL);
}

void draw_settings(screens *screen, settings *setting)
{
    sfRenderWindow_clear(screen->window, sfWhite);
    sfRenderWindow_drawSprite(screen->window, setting->background, NULL);
    for (int i = 0; i < 4; i++) {
        sfRenderWindow_drawSprite(screen->window,
            setting->vlm.sprite[i].sprite, NULL);
    }
    for (int i = 0; i < 3; i++) {
        sfRenderWindow_drawSprite(screen->window,
            setting->fps.sprite[i].sprite, NULL);
    }
    draw_controls(screen, setting);
    for (int i = 0; i < 6; i++) {
        sfRenderWindow_drawRectangleShape(screen->window, setting->color_text.rect[i], NULL);
    }
    sfRenderWindow_display(screen->window);
}
