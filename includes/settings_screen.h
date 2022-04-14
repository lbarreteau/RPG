/*
** EPITECH PROJECT, 2022
** settings_screen
** File description:
** settings_screen
*/

#pragma once

#include "global.h"

typedef struct controls {
    struct sprite sprite[2];
    struct text text[1];
    bool wait_key;
} controls;

typedef struct volume {
    struct sprite sprite[4];
    sfVector2f pos_btn_vlm;
    sfVector2f size_btn;
    bool vlm_is_click;
} volume;

typedef struct fps {
    struct sprite sprite[3];
    sfIntRect rect;
} fps;

typedef struct settings {
    sfColor theme_color;
    char *asset_btn[10];
    struct volume vlm;
    struct fps fps;
    struct controls controls;
} settings;

void init_settings_struct(settings *setting);
void set_settings(settings *setting);
bool event_settings(screens *screen, settings *setting);
void free_settings(screens *screen, settings *setting);
void draw_settings(screens *screen, settings *setting);
void volume_events(screens *screen, settings *setting);
sfVector2f set_pos_mouse_f(screens *screen);
void check_volume_box(settings *setting, sfVector2f set_pos_sprite);
bool mouse_clicked_button(screens *screen, sfSprite *sprite, sfVector2f size);

void fps_events(screens *screen, settings *setting);
void controls_events(screens *screen, settings *setting);
