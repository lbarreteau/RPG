/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** libmy.a in this file
*/

#pragma once

#include "global.h"
#include "player.h"
#include "inventory.h"

typedef struct collisions_s {
    sfRectangleShape *border;
    sfIntRect border_rect;
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
bool there_is_collision_up(level1 *game, player *player1);
bool there_is_collision_down(level1 *game, player *player1);
bool there_is_collision_right(level1 *game, player *player1);
bool there_is_collision_left(level1 *game, player *player1);
void modif_collisions_pos(level1 game, sfVector2f movement);
void draw_level1(screens *screen, level1 *game, player *player1);
bool event_level1(screens *screen, level1 *game, inventory *stock);
void move_player(level1 *game, screens *screen, player *player1);
sfIntRect create_border_intrect(level1 *game, sfIntRect params, int i);
sfIntRect create_border_intrect(level1 *game, sfIntRect params, int i);
collision_t create_border(level1 *game, sfVector2f size,
                sfVector2f pos, int i);
void create_map_border_collisions(level1 *game);
void create_first_five_collisions(level1 *game);
void create_ten_collisions(level1 *game);
void create_fifteen_collisions(level1 *game);
void create_twenty_collisions(level1 *game);
