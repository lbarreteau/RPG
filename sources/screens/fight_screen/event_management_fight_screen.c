/*
** EPITECH PROJECT, 2022
** event_management_fight_screen
** File description:
** event management fight screen
*/

#include "fight_screen.h"
#include "global.h"

char *conv_nbr_into_key(int key)
{
    char *key_letter = malloc(sizeof(char) * 2);

    key_letter[0] = key;
    key_letter[1] = '\0';
    return (key_letter);

}

void display_first_key(fight_screen *fight)
{
    if (fight->check_rand == false) {
    fight->random = rand() % 26;
    fight->check_rand = true;
    init_key_to_press(fight, fight->key_to_press, (sfVector2f) {1100, 500},
                            conv_nbr_into_key(fight->random + 97));
    }
}

bool event_management_fight_screen(screens *screen, fight_screen *fight)
{
    int keytape[26] = {sfKeyA, sfKeyB, sfKeyC, sfKeyD, sfKeyE, sfKeyF, sfKeyG,
                        sfKeyH, sfKeyI, sfKeyJ, sfKeyK, sfKeyL, sfKeyM, sfKeyN,
                        sfKeyO, sfKeyP, sfKeyQ, sfKeyR, sfKeyS, sfKeyT, sfKeyU,
                        sfKeyV, sfKeyW, sfKeyX, sfKeyY, sfKeyZ};
    if (screen->event.type == sfEvtClosed || screen->event.key.code == sfKeyEscape) {
        return (true);
    }
    display_first_key(fight);
    if (screen->event.type == sfEvtKeyPressed) {
        //if (screen->event.key.code == sfKeyA) {
        //    fight->attack[0].is_activ = true;
        //}
        if (screen->event.key.code == keytape[fight->random]
        && fight->bubble.is_activ == false) {
            sfClock_restart(fight->bubble.clock);
            fight->bubble.is_activ = true;
        } else if (fight->bubble.is_activ == false) {
            fight->random = rand() % 26;
            init_key_to_press(fight, fight->key_to_press,
            (sfVector2f) {1100, 500}, conv_nbr_into_key(fight->random + 97));
        }
    }
    return (false);
}
