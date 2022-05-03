/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "menu_screen.h"

static void set_music(menus *menu)
{
    menu->background_music = init_music(menu->background_music,
    menu->name_music);
    menu->music_click = init_music(menu->music_click,
    menu->name_music_click);
    sfMusic_play(menu->background_music);
    sfMusic_setLoop(menu->music_click, sfFalse);
}

static void set_sprite(screens *global, menus *menu)
{
    menu->texture_dark = sfTexture_createFromFile(
        "assets/pictures/sign/long_sign_dark.png", NULL);
    menu->texture_click = sfTexture_createFromFile(
        "assets/pictures/sign/long_sign_click.png", NULL);
    for (int i = 0, x = 425; i < 4; i++, x += 150) {
        menu->signs[i] = init_sprite(menu->name_sign, (sfVector2f) {1, 1},
        (sfVector2f) {704, x});
        menu->name_options[i] = init_text(30, (sfVector2f) {825, x + 35},
        global->theme_color);
    }
}

static void set_text(screens *global, menus *menu)
{
    menu->title = init_text(75, (sfVector2f) {275, 125}, global->theme_color);
    sfText_setString(menu->title.text, global->name_screen);
    sfText_setString(menu->name_options[0].text, "      START");
    sfText_setString(menu->name_options[1].text, "  SETTINGS");
    sfText_setString(menu->name_options[2].text, "HOW TO PLAY");
    sfText_setString(menu->name_options[3].text, "       QUIT");
    global->list_key[0] = "Q";
    global->list_key[1] = "D";
    global->list_key[2] = "Z";
    global->list_key[3] = "S";
    global->list_key[4] = "I";
}

void set_menu(screens *global, menus *menu)
{
    set_music(menu);
    set_sprite(global, menu);
    set_text(global, menu);
    global->inv_is_set = false;
}
