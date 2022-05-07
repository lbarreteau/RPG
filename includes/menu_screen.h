/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** libmy.a in this file
*/

#pragma once

#include "global.h"

void init_menu_struct(screens *global, menus *menu);
void set_menu(screens *global, menus *menu);
void draw_menu(screens *screen, menus *menu);
bool event_menu(screens *screen, menus *menu);
void free_menu(screens *screen, menus *menu);
