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
    sfRenderWindow_drawSprite(screen->window, fight->player_fight.sprite, NULL);
    fight->bubble.time = sfClock_getElapsedTime(fight->bubble.clock);
    fight->bubble.seconds = fight->bubble.time.microseconds / 1000000.0;
    if (fight->bubble.seconds > 2) {
        fight->bubble.is_activ = false;
    }
    if (fight->bubble.seconds > 1.8 && fight->bubble.seconds < 1.82 &&
        fight->bubble.is_activ == true) {
        fight->random = rand() % 26;
        init_key_to_press(fight, fight->key_to_press,
            (sfVector2f) {1100, 500}, conv_nbr_into_key(fight->random + 97));
    }
    if (fight->bubble.is_activ == true && fight->bubble.seconds < 1) {
        sfRenderWindow_drawSprite(screen->window, fight->bubble.sprite.sprite, NULL);
    }
    sfRenderWindow_drawText(screen->window, fight->key_press, NULL);
    sfRenderWindow_drawText(screen->window, fight->key_to_press, NULL);
    for (int i = 0; i < 10; i++) {
        if (fight->attack[i].is_activ == true) {
            fireball_animation(&fight->attack[i]);
            sfRenderWindow_drawSprite(screen->window,
                fight->attack[i].sprite.sprite, NULL);
        }
    }
    sfRenderWindow_display(screen->window);
}
