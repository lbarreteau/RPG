/*
** EPITECH PROJECT, 2022
** fight_screen.h
** File description:
** fight_screen.h
*/

#pragma once

#include "global.h"
#include "player.h"

typedef struct protection
{
    struct sprite sprite;
    bool is_activ;
    sfClock *clock;
    sfTime time;
    float seconds;
} protection;

typedef struct attack_s {
    struct sprite sprite;
    bool is_activ;
    sfClock *clock;
    sfTime time;
    float seconds;
} attack_t;

typedef struct ennemies_s {
    struct sprite sprite;
    sfClock *clock;
    sfTime time;
    float seconds;
} ennemies_t;

typedef struct fight_screen
{
    struct player player_fight;
    struct sprite map;
    struct protection bubble;
    struct ennemies_s ennemi[3];
    struct attack_s attack[3];
    sfFont *font;
    sfText *key_press;
    sfText *key_to_press;
    int random;
    bool check_rand;
} fight_screen;

void fight_scrn(screens *screen);
void free_fight_screen(fight_screen *fight);
void set_fight_screen(fight_screen *fight);
void init_fight_screen_struct(fight_screen *fight);
bool event_management_fight_screen(screens *screen, fight_screen *fight);
void draw_fight_screen(screens *screen, fight_screen *fight);
void set_player_fight(fight_screen *fight);
void init_text_to_display(fight_screen *fight, sfText *text, sfVector2f pos,
                        char *str);
