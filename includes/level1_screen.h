/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** libmy.a in this file
*/

#pragma once

#include "global.h"

typedef struct level1 {
    sfColor theme_color;
    struct sprite player;
} level1;

void init_level1_struct(level1 *game);
void set_level1(level1 *game);
void free_level1(level1 *game);
void draw_level1(screens *screen, level1 *game);
bool event_level1(screens *screen);
