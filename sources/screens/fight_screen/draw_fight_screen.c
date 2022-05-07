/*
** EPITECH PROJECT, 2022
** draw_fight_screen
** File description:
** draw fight screen
*/

#include "fight_screen.h"
#include "global.h"

static void check_display_of_bubble(fight_screen *fight, screens *screen)
{
    if (fight->bubble.seconds > 2) {
        fight->bubble.is_activ = false;
    }
    if (fight->bubble.seconds > 1.8 && fight->bubble.seconds < 1.82 &&
        fight->bubble.is_activ == true) {
        fight->random = rand() % 26;
        init_key_to_press(fight,
            (sfVector2f) {1100, 500}, conv_nbr_into_key(fight->random + 97));
    }
    if (fight->bubble.is_activ == true && fight->bubble.seconds < 2) {
        sfRenderWindow_drawSprite(screen->window, fight->bubble.sprite.sprite,
        NULL);
    }
}

static void check_draw_fireballs(fight_screen *fight, screens *screen)
{
    for (int i = 0; i < 10; i++) {
        if (fight->attack_ennemy[i].is_activ == true) {
            fireball_animation(&fight->attack_ennemy[i], -20);
            sfRenderWindow_drawSprite(screen->window,
                fight->attack_ennemy[i].sprite.sprite, NULL);
        }
    }
    if (fight->attack_player.is_activ == true) {
        fireball_animation(&fight->attack_player, 20);
        sfRenderWindow_drawSprite(screen->window,
            fight->attack_player.sprite.sprite, NULL);
    }
}

void draw_fight_screen(screens *screen, fight_screen *fight)
{
    sfRenderWindow_clear(screen->window, sfBlack);
    sfRenderWindow_drawSprite(screen->window, fight->map.sprite, NULL);
    sfRenderWindow_drawSprite(screen->window, fight->player_fight.sprite, NULL);
    sfRenderWindow_drawSprite(screen->window, fight->ennemy[0].sprite, NULL);
    fight->bubble.time = sfClock_getElapsedTime(fight->bubble.clock);
    fight->bubble.seconds = fight->bubble.time.microseconds / 1000000.0;
    check_display_of_bubble(fight, screen);
    sfRenderWindow_drawText(screen->window, fight->key_press, NULL);
    sfRenderWindow_drawText(screen->window, fight->key_to_press, NULL);
    sfRenderWindow_drawSprite(screen->window, fight->player_fight.stat.sprite[0], NULL);
    sfRenderWindow_drawSprite(screen->window, fight->player_fight.stat.sprite[1], NULL);
    sfRenderWindow_drawSprite(screen->window, fight->ennemy[0].stat.sprite[0], NULL);
    sfRenderWindow_drawSprite(screen->window, fight->ennemy[0].stat.sprite[1], NULL);
    check_draw_fireballs(fight, screen);
    sfRenderWindow_display(screen->window);
}
