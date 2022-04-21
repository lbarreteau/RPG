/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** libmy.a in this file
*/

#pragma once

#include "global.h"

typedef struct level1 {
    struct sprite player;
    struct sprite map;
    sfClock *clock;
    sfTime time;
    int move_direction;
    float seconds;
} level1;

void init_level1_struct(level1 *game);
void set_level1(level1 *game);
void free_level1(level1 *game);
void draw_level1(screens *screen, level1 *game);
bool event_level1(screens *screen, level1 *game);
void move_player(level1 *game, screens *screen);
