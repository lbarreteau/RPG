/*
** EPITECH PROJECT, 2022
** event_management_fight_screen
** File description:
** event management fight screen
*/

#include "fight_screen.h"
#include "global.h"

bool event_management_fight_screen(screens *screen, fight_screen *fight)
{
    int keytape[50] = {sfKeyA, sfKeyB, sfKeyC, sfKeyD, sfKeyE, sfKeyF, sfKeyG,
                        sfKeyH, sfKeyI, sfKeyJ, sfKeyK, sfKeyL, sfKeyM, sfKeyN,
                        sfKeyO, sfKeyP, sfKeyQ, sfKeyR, sfKeyS, sfKeyT, sfKeyU,
                        sfKeyV, sfKeyW, sfKeyX, sfKeyY, sfKeyZ};
    if (screen->event.type == sfEvtClosed || screen->event.key.code == sfKeyF) {
        return (true);
    }
    if (screen->event.type == sfEvtKeyPressed) {
        int random = rand() % 26;
        my_putchar(keytape[random] + 'a');
        sfText *press_key = sfText_create();
        sfText_setString(press_key, "press key ");
        sfText *key_to_pressed = sfText_create();
        sfText_setString(key_to_pressed, keytape[random]);
        sfText_setFont(press_key, fight->font);
        sfText_setFont(key_to_pressed, fight->font);
        sfRenderWindow_drawText(screen->window, press_key, NULL);
        sfRenderWindow_drawText(screen->window, key_to_pressed, NULL);
        if (screen->event.key.code == keytape[random] && fight->bull.is_activ == false) {
            sfClock_restart(fight->bull.clock);
            fight->bull.is_activ = true;
        }
    }
    return (false);
}
