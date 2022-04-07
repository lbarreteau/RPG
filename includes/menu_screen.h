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
} menus;

struct text init_text(int size, sfVector2f pos, sfColor theme_color);
void init_menu_struct(menus *menu);
void set_menu(menus *menu);
void draw_menu(screens *screen, menus *menu);
bool event_menu(screens *screen, menus *menu);
void free_menu(screens *screen, menus *menu);
