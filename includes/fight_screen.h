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

typedef struct fight_screen
{
    struct player player_fight;
    struct sprite map;
    struct protection bubble;
    sfFont *font;
} fight_screen;

void fight_scrn(screens *screen);
void free_fight_screen(fight_screen *fight);
void set_fight_screen(fight_screen *fight);
void init_fight_screen_struct(fight_screen *fight);
bool event_management_fight_screen(screens *screen, fight_screen *fight);
void draw_fight_screen(screens *screen, fight_screen *fight);
void set_player_fight(fight_screen *fight);
