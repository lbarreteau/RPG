/*
** EPITECH PROJECT, 2022
** set_fight_screen
** File description:
** set_fight_screen
*/

#include "fight_screen.h"
#include "global.h"

void init_text_to_display(fight_screen *fight, sfText *text, sfVector2f pos,
                            char *str)
{
    sfText_setFont(fight->key_press, fight->font);
    sfText_setString(fight->key_press, str);
    sfText_setOutlineColor(fight->key_press, sfRed);
    sfText_setCharacterSize(fight->key_press, 50);
    sfText_setColor(fight->key_press, sfRed);
    sfText_setPosition(fight->key_press, pos);
}

void init_key_to_press(fight_screen *fight, sfText *text, sfVector2f pos,
                            char *str)
{
    sfText_setFont(fight->key_to_press, fight->font);
    sfText_setString(fight->key_to_press, str);
    sfText_setOutlineColor(fight->key_to_press, sfRed);
    sfText_setCharacterSize(fight->key_to_press, 50);
    sfText_setColor(fight->key_to_press, sfRed);
    sfText_setPosition(fight->key_to_press, pos);
}

void set_fight_screen(fight_screen *fight)
{
    fight->map = init_sprite("assets/pictures/map/map_fight.png",
        (sfVector2f) {5, 5}, (sfVector2f) {-400, -500});
    fight->bubble.sprite = init_sprite("assets/pictures/sprite/bull.png",
        (sfVector2f) {0.7, 0.7}, (sfVector2f) {600, 300});
    fight->bubble.clock = sfClock_create();
    fight->bubble.is_activ = false;
    fight->font = sfFont_createFromFile("assets/families/global_font.ttf");
    fight->key_press = sfText_create();
    fight->key_to_press = sfText_create();
    fight->random = 0;
    fight->bubble.hitbox = (sfIntRect) {0, 0, 208.6, 208.6};
    fight->check_rand = false;
    fight->attack_clock = sfClock_create();
    init_text_to_display(fight, fight->key_press, (sfVector2f) {500, 500},
                                    "Press key ");
    for (int i = 0; i < 10; i++)
        set_attack_ennemy(&fight->attack[i], (sfIntRect){0, 0, 64, 64}, 0);
}
