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
    char *name_sign;
    char *name_sign_dark;
    sfVector2u size_screen;
    struct sprite signs[4];
    struct text name_options[4];
    char *name_music;
    sfMusic *background_music;
    struct text title;
} menus;

void init_menu_struct(menus *menu);
void set_menu(screens *global, menus *menu);
void draw_menu(screens *screen, menus *menu);
bool event_menu(screens *screen, menus *menu);
void free_menu(screens *screen, menus *menu);
