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
    background.texture_dark = sfTexture_createFromFile(
        "assets/pictures/long_sign_dark.png", NULL);
    background.sprite = sfSprite_create();
    sfSprite_setPosition(background.sprite, pos);
    sfSprite_setScale(background.sprite, size);
    sfSprite_setTexture(background.sprite, background.texture, sfFalse);
    return (background);
}

struct text init_text(int size, sfVector2f pos, sfColor theme_color)
{
    struct text text;

    text.font = sfFont_createFromFile("assets/families/global_font.ttf");
    text.text = sfText_create();
    sfText_setFont(text.text, text.font);
    sfText_setCharacterSize(text.text, size);
    sfText_setColor(text.text, theme_color);
    sfText_setPosition(text.text, pos);
    sfText_setString(text.text, " ");
    return (text);
}
