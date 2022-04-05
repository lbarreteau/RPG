/*
** EPITECH PROJECT, 2022
** button is clicked
** File description:
** button is clicked
*/

#include "menu_screen.h"

void increase_circle(menus *menu, int i_circle)
{
    if (sfCircleShape_getRadius(menu->options_circles[i_circle]) <= 125) {
        sfCircleShape_setRadius(menu->options_circles[i_circle], (sfCircleShape_getRadius(menu->options_circles[i_circle]) + 1));
    }
}

void decrease_circle(menus *menu, int i_circle)
{
    if (sfCircleShape_getRadius(menu->options_circles[i_circle]) >= 100) {
            sfCircleShape_setRadius(menu->options_circles[i_circle], (sfCircleShape_getRadius(menu->options_circles[i_circle]) - 1));
        }
}

void is_on_circle(screens *screen, menus *menu)
{
    sfVector2i mouse_pos = sfMouse_getPositionRenderWindow(screen->window);
    sfVector2f circle_pos;

    for (int i = 0; i != 6; i++) {
        circle_pos = sfCircleShape_getPosition(menu->options_circles[i]);
        if (mouse_pos.x >= circle_pos.x && mouse_pos.x <= (circle_pos.x + 200) &&
        mouse_pos.y >= circle_pos.y && mouse_pos.y <= (circle_pos.y + 175)) {
            increase_circle(menu, i);
        } else {
            decrease_circle(menu, i);
        }
    }
}
