/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "menu_screen.h"

void set_menu(menus *menu)
{
    for (int i = 0, x = 425; i < 4; i++, x += 150) {
        menu->signs[i] = init_sprite(menu->name_sign, (sfVector2f) {1, 1},
        (sfVector2f) {704, x});
        menu->name_options[i] = init_text(30, (sfVector2f) {825, x + 35},
        menu->theme_color);
    }
    sfText_setString(menu->name_options[0].text, "      START");
    sfText_setString(menu->name_options[1].text, "  SETTINGS");
    sfText_setString(menu->name_options[2].text, "HOW TO PLAY");
    sfText_setString(menu->name_options[3].text, "       QUIT");
}
