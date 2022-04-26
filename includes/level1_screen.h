/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** libmy.a in this file
*/

#pragma once

#include "global.h"
#include "player.h"

typedef struct collisions_s {
    sfRectangleShape *border;
    sfVector2f border_pos;
    sfVector2f border_size;
} collision_t;
typedef struct level1 {
    struct sprite map;
    struct collisions_s *collisions;
    sfClock *clock;
    sfTime time;
    int move_direction;
    float seconds;

    char *name_screen_background;
} level1;

void init_level1_struct(level1 *game);
void set_level1(level1 *game);
void free_level1(level1 *game);
void init_all_collisions(level1 *game);
void modif_collisions_pos(level1 game, sfVector2f movement);
void draw_level1(screens *screen, level1 *game, player *player1);
bool event_level1(screens *screen, level1 *game);
void move_player(level1 *game, screens *screen, player *player1);
