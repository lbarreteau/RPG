/*
** EPITECH PROJECT, 2022
** colot_text_events
** File description:
** colot_text_events
*/

#include "settings_screen.h"

bool mouse_click_color(screens *screen, sfRectangleShape *rect)
{
    sfVector2f pos_mouse = set_pos_mouse_f(screen);

    if (pos_mouse.x > sfRectangleShape_getPosition(rect).x &&
        pos_mouse.x < sfRectangleShape_getPosition(rect).x
        + sfRectangleShape_getSize(rect).x &&
        pos_mouse.y > sfRectangleShape_getPosition(rect).y &&
        pos_mouse.y < sfRectangleShape_getPosition(rect).y
        + sfRectangleShape_getSize(rect).y) {
        return (true);
    }
    return (false);
}

void click_button_color(screens *screen, settings *setting, int i)
{
    sfVector2f pos_rect =
    sfRectangleShape_getPosition(setting->color_text.rect[i]);

    pos_rect.x += 25;
    pos_rect.y += 25;
    if (screen->event.type == sfEvtMouseButtonPressed &&
        screen->event.mouseButton.button == sfMouseLeft) {
        if (mouse_click_color(screen, setting->color_text.rect[i]) == true) {
            sfRectangleShape_setPosition(setting->color_text.rect[5],
                pos_rect);
            screen->theme_color = setting->color_text.color[i];
        }
    }
}

void color_text_events(screens *screen, settings *setting)
{
    for (int i = 0; i < 5; i++) {
        click_button_color(screen, setting, i);
    }
}