/*
** EPITECH PROJECT, 2022
** controls_events
** File description:
** controls_events
*/

#include "settings_screen.h"

const char *keycode[] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T", "U",
    "V", "W", "X", "Y", "Z", "Num0", "Num1", "Num2", "Num3", "Num4", "Num5", "Num6", "Num7", "Num8", "Num9",
    "Escape", "LControl", "LShift", "LAlt", "LSystem", "RControl", "RShift", "RAlt", "RSystem",
    "Menu", "LBracket", "RBracket", "SemiColon", "Comma", "Period", "Quote", "Slash", "BackSlash",
    "Tilde", "Equal", "Dash", "Space", "Return", "Back", "Tab", "PageUp", "PageDown", "End", "Home",
    "Insert", "Delete", "Add", "Subtract", "Multiply", "Divide", "Left", "Right", "Up", "Down",
    "Numpad0", "Numpad1", "Numpad2", "Numpad3", "Numpad4", "Numpad5", "Numpad6", "Numpad7",
    "Numpad8", "Numpad9", "F1", "F2", "F3", "F4", "F5", "F6", "F7", "F8", "F9", "F10", "F11", "F12", "F13", "F14",
    "F15", "Pause", "Count"
};

void change_controls(screens *screen, settings *setting)
{
    char *temp = NULL;

    if (screen->event.type == sfEvtKeyPressed) {
        if (screen->event.key.code != -1) {
            temp = strdup(keycode[screen->event.key.code]);
            sfText_setString(setting->controls.text->text, temp);
            sfText_setPosition(setting->controls.text->text, (sfVector2f){550 - strlen(temp) / 2 * 20, 500});
            setting->controls.wait_key = false;
        }
    }
    if (temp != NULL)
        free(temp);
}

void controls_events(screens *screen, settings *setting)
{
    if (screen->event.type == sfEvtMouseButtonPressed &&
        screen->event.mouseButton.button == sfMouseLeft) {
        if (mouse_clicked_button(screen, setting->controls.sprite[0].sprite,
            (sfVector2f){256, 116}) == true) {
            setting->controls.wait_key = true;
            change_controls(screen, setting);
        }
    }
    if (setting->controls.wait_key == true)
        change_controls(screen, setting);
}