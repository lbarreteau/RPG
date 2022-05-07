/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** libmy.a in this file
*/

#pragma once

#include "global.h"

typedef struct how_to_play {
    char *background;
    struct sprite how_to_play;
    struct sprite exit;
} how_to_play;

void init_how_to_play_struct(how_to_play *game);
void set_how_to_play(how_to_play *game);
void draw_how_to_play(screens *screen, how_to_play *game);
void free_how_to_play(how_to_play *game);
int event_how_to_play(screens *screen, how_to_play *game);
