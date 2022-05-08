/*
** EPITECH PROJECT, 2022
** controls_events
** File description:
** controls_events
*/

#include "settings_screen.h"

const char *keycode[] = {
    "A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M", "N",
    "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z", "Num0", "Num1",
    "Num2", "Num3", "Num4", "Num5", "Num6", "Num7", "Num8", "Num9", "Escape",
    "LControl", "LShift", "LAlt", "LSystem", "RControl", "RShift", "RAlt",
    "RSystem", "Menu", "LBracket", "RBracket", "SemiColon", "Comma", "Period",
    "Quote", "Slash", "BackSlash", "Tilde", "Equal", "Dash", "Space", "Return",
    "Back", "Tab", "PageUp", "PageDown", "End", "Home", "Insert", "Delete",
    "Add", "Subtract", "Multiply", "Divide", "Left", "Right", "Up", "Down",
    "Numpad0", "Numpad1", "Numpad2", "Numpad3", "Numpad4", "Numpad5",
    "Numpad6", "Numpad7", "Numpad8", "Numpad9", "F1", "F2", "F3", "F4", "F5",
    "F6", "F7", "F8", "F9", "F10", "F11", "F12", "F13", "F14", "F15",
    "Pause", "Count"
};

bool check_other_key(settings *setting, const char *str_keycode)
{
    for (int i = 0; i < 5; i++) {
        if (my_strcmp(sfText_getString(setting->controls.text[i].text),
            str_keycode) == 0)
            return (true);
    }
    return (false);
}

void change_controls(screens *screen, settings *setting, int i)
{
    char *temp = NULL;

    if (screen->event.type == sfEvtKeyPressed) {
        if (screen->event.key.code != -1 &&
        check_other_key(setting, keycode[screen->event.key.code]) == false) {
            temp = my_strdup(keycode[screen->event.key.code]);
            sfText_setString(setting->controls.text[i].text, temp);
            sfText_setPosition(setting->controls.text[i].text,
                (sfVector2f){540 - my_strlen(temp) * 20 / 2, 490 + i * 100});
            screen->list_key[i] = screen->event.key.code;
            setting->controls.wait_key[i] = false;
        }
    }
    if (temp != NULL)
        free(temp);
}

void click_button_controls(screens *screen, settings *setting, int i)
{
    if (screen->event.type == sfEvtMouseButtonPressed &&
        screen->event.mouseButton.button == sfMouseLeft) {
        if (mouse_clicked_button(screen,
            setting->controls.sprite[i * 2].sprite,
            (sfVector2f){256, 116}) == true) {
            setting->controls.wait_key[i] = true;
        }
    }
}

void controls_events(screens *screen, settings *setting)
{
    for (int i = 0; i < 5; i++) {
        if (setting->controls.wait_key[0] == false &&
        setting->controls.wait_key[1] == false &&
        setting->controls.wait_key[2] == false &&
        setting->controls.wait_key[3] == false &&
        setting->controls.wait_key[4] == false) {
            click_button_controls(screen, setting, i);
        }
        if (setting->controls.wait_key[i] == true)
            change_controls(screen, setting, i);
    }
}
