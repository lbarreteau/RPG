/*
** EPITECH PROJECT, 2022
** fight_screen.h
** File description:
** fight_screen.h
*/

#pragma once

#include "global.h"

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
    struct sprite player;
    struct sprite map;
    struct protection bull;
} fight_screen;

void init_level1_struct(fight_screen *fight);
void free_fight_screen(fight_screen *fight);
void set_fight_screen(fight_screen *fight);
void init_fight_screen_struct(fight_screen *fight);
bool event_management_fight_screen(screens *screen, fight_screen *fight);
void draw_fight_screen(screens *screen, fight_screen *fight);
