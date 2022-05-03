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
    char *name_sign;
    char *name_sign_dark;
    sfVector2u size_screen;
    struct sprite signs[4];
    struct text name_options[4];
    struct text title;
    sfTexture *texture_dark;
    sfTexture *texture_click;
} menus;

void init_menu_struct(screens *global, menus *menu);
void set_menu(screens *global, menus *menu);
void draw_menu(screens *screen, menus *menu);
bool event_menu(screens *screen, menus *menu);
void free_menu(screens *screen, menus *menu);
