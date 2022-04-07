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

sfText *init_text(sfText *text, char *label, int size, sfVector2f pos)
{
    text = sfText_create();
    sfText_setFont(text, sfFont_createFromFile("assets/families/global_font.ttf"));
    sfText_setCharacterSize(text, size);
    sfText_setColor(text, sfWhite);
    sfText_setPosition(text, pos);
    sfText_setString(text, label);
    return (text);
}
