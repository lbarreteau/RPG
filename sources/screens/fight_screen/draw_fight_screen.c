/*
** EPITECH PROJECT, 2022
** draw_fight_screen
** File description:
** draw fight screen 
*/

#include "fight_screen.h"
#include "global.h"

void draw_fight_screen(screens *screen, fight_screen *fight)
{
    sfRenderWindow_clear(screen->window, sfBlack);
    sfRenderWindow_drawSprite(screen->window, fight->map.sprite, NULL);
    fight->bull.time = sfClock_getElapsedTime(fight->bull.clock);
    fight->bull.seconds = fight->bull.time.microseconds / 1000000.0;
    if (fight->bull.seconds > 2) {
        fight->bull.is_activ = false;
    }
    if (fight->bull.is_activ == true && fight->bull.seconds < 1) {
        sfRenderWindow_drawSprite(screen->window, fight->bull.sprite.sprite, NULL);
    }
    sfRenderWindow_display(screen->window);
}
