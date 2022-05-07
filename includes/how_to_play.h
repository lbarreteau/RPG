/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** libmy.a in this file
*/

#pragma once

#include "global.h"

typedef struct how_to_play {
    char *name_player_sprite;
    struct sprite player;
    char *name_background_sign;
    struct sprite how_to_play_sign;
    struct sprite exemple_map;
    char *name_exemple_map;
    char *name_title;
    struct sprite title;
    struct sprite next_step;
    unsigned short step;
} how_to_play;

void init_how_to_play_struct(how_to_play *game);
void how_to_play_screen(screens *screen);
void set_how_to_play(how_to_play *game);
void draw_how_to_play(screens *screen, how_to_play *game);
void free_how_to_play(how_to_play *game);
bool event_how_to_play(screens *screen);
