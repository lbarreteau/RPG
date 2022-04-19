/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "how_to_play.h"

static void update_patern(how_to_play *game)
{
    sfVector2f pos_background = sfSprite_getPosition(game->exemple_map.sprite);
    if (game->step == 0) {
        if (pos_background.y > -500) {
            pos_background.y -= 1;
        }
        if (pos_background.y == -500 && pos_background.x > -625) {
            pos_background.x -= 1;
        }
        if (pos_background.x == -625 && pos_background.y > -775) {
            pos_background.y -= 1;
        }
        if (pos_background.y == -775 && pos_background.x < -550) {
            pos_background.x += 1;
        }
        if (pos_background.y == -775 && pos_background.x == -550) {
            pos_background.x = -500;
            pos_background.y = -450;
        }
    }
    sfSprite_setPosition(game->exemple_map.sprite, pos_background);
}

void how_to_play_screen(screens *screen)
{
    struct how_to_play game;
    bool exit = false;

    init_how_to_play_struct(&game);
    set_how_to_play(&game);
    while (sfRenderWindow_isOpen(screen->window)) {
        while (sfRenderWindow_pollEvent(screen->window, &screen->event)) {
            exit = event_how_to_play(screen);
        }
        if (exit == true) {
            free_how_to_play(&game);
            return;
        }
        update_patern(&game);
        draw_how_to_play(screen, &game);
    }
}
