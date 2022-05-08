/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "menu_screen.h"

static void set_music(screens *global)
{
    global->music[0] = init_music(global->music[0],
    global->name_music[0]);
    global->music[1] = init_music(global->music[1],
    global->name_music[1]);
    sfMusic_play(global->music[0]);
    sfMusic_setLoop(global->music[1], sfFalse);
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
    global->list_key[0] = sfKeyQ;
    global->list_key[1] = sfKeyD;
    global->list_key[2] = sfKeyZ;
    global->list_key[3] = sfKeyS;
    global->list_key[4] = sfKeyI;
}

void set_menu(screens *global, menus *menu)
{
    set_music(global);
    set_sprite(global, menu);
    set_text(global, menu);
    global->quit_game = false;
    global->inv_is_set = false;
    global->menu = menu;
}
