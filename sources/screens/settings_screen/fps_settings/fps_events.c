/*
** EPITECH PROJECT, 2022
** fps_events
** File description:
** fps_events
*/

#include "settings_screen.h"

void check_fps_is_click(int i, settings *setting)
{
    for (int j = 0; j < 3; j++) {
        if (j != i) {
            sfSprite_setTextureRect(setting->fps.sprite[j].sprite,
                setting->fps.rect);
        }
    }
}

void change_fps(screens *screen, settings *setting)
{
    for (int i = 0; i < 3; i++) {
        if (mouse_clicked_button(screen, setting->fps.sprite[i].sprite,
            (sfVector2f) {118, 118}) == true) {
            setting->fps.rect.left += 118;
            sfSprite_setTextureRect(setting->fps.sprite[i].sprite,
                setting->fps.rect);
            setting->fps.rect.left = 0;
            check_fps_is_click(i, setting);
            sfRenderWindow_setFramerateLimit(screen->window, (i + 1) * 30);
            screen->fps = (i + 1) * 30;
        }
    }
}

void fps_events(screens *screen, settings *setting)
{
    if (screen->event.type == sfEvtMouseButtonPressed &&
        screen->event.mouseButton.button == sfMouseLeft) {
        change_fps(screen, setting);
    }
}