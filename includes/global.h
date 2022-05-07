/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** libmy.a in this file
*/

#pragma once

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdbool.h>
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/System.h>
#include <SFML/Audio.h>
#include <time.h>


typedef enum {LEFT, RIGHT, DOWN, UP, INVENTORY} key_name;


struct sprite {
    sfSprite *sprite;
    sfTexture *texture;
};

struct text {
    sfText *text;
    sfFont *font;
};

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

typedef struct screens {
    unsigned int size_screen_length;
    unsigned int size_screen_width;
    unsigned short bits_per_pixel;
    unsigned short fps;
    sfKeyCode list_key[5];
    char *name_screen;
    char *name_background;
    char *name_music[2];
    sfMusic *music[2];
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    struct sprite background;
    sfColor theme_color;
    bool inv_is_set;
} screens;

struct sprite init_sprite(char *filepath, sfVector2f size, sfVector2f pos);
struct text init_text(int size, sfVector2f pos, sfColor theme_color);
sfMusic *init_music(sfMusic *background_music, char *filepath);

char *open_and_read_file(char *filepath);
char **str_to_word_array(char *str);
sfColor recognition_color(char *color);
void free_array(char **array);

void init_screen_struct(screens *screen);
void set_screen(screens *screen);
void main_screen(void);
void level1_screen(screens *screen, menus *menu);
void how_to_play_screen(screens *screen);
bool settings_screen(screens *screen);
