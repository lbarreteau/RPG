/*
** EPITECH PROJECT, 2022
** settings_screen
** File description:
** settings_screen
*/

#pragma once

#include "global.h"

typedef struct settings {
    sfColor theme_color;
} settings;

void init_settings_struct(settings *setting);
void set_settings(settings *setting);
bool event_settings(screens *screen, settings *setting);
void free_settings(screens *screen, settings *setting);
void draw_settings(screens *screen, settings *setting);