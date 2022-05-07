/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "settings_screen.h"

sfVector2f set_pos_mouse_f(screens *screen)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(screen->window);
    sfVector2f pos_mousef;

    pos_mousef.x = pos_mouse.x;
    pos_mousef.y = pos_mouse.y;
    return (pos_mousef);
}

bool mouse_clicked_button(screens *screen, sfSprite *sprite, sfVector2f size)
{
    sfVector2f pos_mouse = set_pos_mouse_f(screen);
    sfVector2f pos_button = sfSprite_getPosition(sprite);

    if (pos_mouse.x >= pos_button.x && pos_mouse.x <= pos_button.x + size.x
    && pos_mouse.y >= pos_button.y && pos_mouse.y <= pos_button.y + size.y) {
        return (true);
    }
    return (false);
}

int event_settings(screens *screen, settings *setting)
{
    if (screen->event.type == sfEvtClosed)
        return (1);
    if (screen->event.type == sfEvtMouseButtonPressed &&
        screen->event.mouseButton.button == sfMouseLeft) {
        if (mouse_clicked_button(screen, setting->exit.sprite,
        (sfVector2f){80, 80})) {
            return (2);
        }
    }
    if (setting->controls.wait_key[0] == false &&
        setting->controls.wait_key[1] == false &&
        setting->controls.wait_key[2] == false &&
        setting->controls.wait_key[3] == false &&
        setting->controls.wait_key[4] == false) {
        volume_events(screen, setting);
        fps_events(screen, setting);
    }
    controls_events(screen, setting);
    color_text_events(screen, setting);
    return (0);
}
