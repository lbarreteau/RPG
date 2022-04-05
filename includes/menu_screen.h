/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** libmy.a in this file
*/

#pragma once

#include <time.h>

#include "global.h"

typedef struct menus {
    time_t ltime;
    bool display_time;
    sfColor theme_color;
    char *name_start_game;
    struct sprite start_game;
} menus;


sfCircleShape *init_circle(sfCircleShape *circle, unsigned int radius, sfVector2f pos, menus *menu);
void init_menu_struct(menus *menu);
void set_menu(menus *menu);
void draw_menu(screens *screen, menus *menu);
bool event_menu(screens *screen, menus *menu);
void free_menu(screens *screen, menus *menu);
