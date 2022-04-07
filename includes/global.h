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

struct sprite {
    sfSprite *sprite;
    sfTexture *texture;
};

struct text {
    sfText *text;
    sfFont *font;
};

typedef struct screens {
    unsigned int size_screen_length;
    unsigned int size_screen_width;
    unsigned short bits_per_pixel;
    unsigned short fps;
    char *name_screen;
    char *name_background;
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    struct sprite background;
} screens;

struct sprite init_sprite(char *filepath, sfVector2f size, sfVector2f pos);

char *open_and_read_file(char *filepath);
char **str_to_word_array(char *str);
sfColor recognition_color(char *color);
void free_array(char **array);

void init_screen_struct(screens *screen);
void set_screen(screens *screen);
void main_screen(void);
