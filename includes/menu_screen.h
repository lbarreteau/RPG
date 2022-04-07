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
    struct sprite signs[4];
    sfText *name_options[4];
} menus;

sfText *init_text(sfText *text, char *label, int size, sfVector2f pos);
void init_menu_struct(menus *menu);
void set_menu(menus *menu);
void draw_menu(screens *screen, menus *menu);
bool event_menu(screens *screen, menus *menu);
void free_menu(screens *screen, menus *menu);
