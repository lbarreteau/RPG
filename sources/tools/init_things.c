/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "menu_screen.h"

struct sprite init_sprite(char *filepath, sfVector2f size, sfVector2f pos)
{
    struct sprite background;

    background.texture = sfTexture_createFromFile(filepath, NULL);
    background.sprite = sfSprite_create();
    sfSprite_setPosition(background.sprite, pos);
    sfSprite_setScale(background.sprite, size);
    sfSprite_setTexture(background.sprite, background.texture, sfFalse);
    return (background);
}

sfCircleShape *init_circle(sfCircleShape *circle, unsigned int radius,
sfVector2f pos, menus *menu)
{
    circle = sfCircleShape_create();
    sfCircleShape_setFillColor(circle, menu->theme_color);
    sfCircleShape_setPosition(circle, pos);
    sfCircleShape_setRadius(circle, radius);
    sfCircleShape_setOutlineColor(circle, menu->theme_color);
    return (circle);
}
