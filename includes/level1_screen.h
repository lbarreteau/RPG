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
#include "enemy.h"
#include "fight_screen.h"

typedef struct collisions_s {
    sfRectangleShape *border;
    sfVector2f scale;
    sfIntRect border_rect;
    sfVector2f border_pos;
    sfVector2f border_size;
} collision_t;

typedef struct level1 {
    struct items item[2];
    bool pause_event;
    struct sprite map;
    struct player *player1;
    struct inventory stock;
    struct frame_buffer *buffer;
    struct collisions_s *collisions;
    sfClock *clock;
    sfTime time;
    int move_direction;
    float seconds;
    char *name_screen_background;
    struct sprite pnj;
    sfIntRect hitbox_pnj;
    bool win;
    sfClock *win_screen_clock;
    sfFont *font;
    char *name_pnj;
    struct sprite pnj_2;
    sfIntRect hitbox_pnj2;
    char *name_pnj_2;
    struct sprite background_dialog;
    struct text dialog;
    struct sprite background_dialog_2;
    struct text dialog_2;
    bool dialog_active;
    bool dialog_active_2;
    struct enemy_s enemy[2];
} level1;

typedef struct frame_buffer {
    unsigned int width;
    unsigned int height;
    sfUint8 *pixels;
    sfTexture *texture;
    sfSprite *sprite;
    bool snow_active;
    bool water_active;
} frame_buffer;

void init_level1_struct(level1 *game);
void set_level1(level1 *game, player *player1);
void free_level1(level1 *game);
void init_all_collisions(level1 *game);
bool there_is_collision_up(level1 *game, player *player1);
bool there_is_collision_down(level1 *game, player *player1);
bool there_is_collision_right(level1 *game, player *player1);
bool there_is_collision_left(level1 *game, player *player1);
void modif_collisions_pos(level1 *game, sfVector2f movement);
void draw_level1(screens *screen, level1 *game, player *player1);
bool event_level1(screens *screen, level1 *game, player *player1);
void move_player(level1 *game, player *player1, screens *screen);
void move_down(level1 *game, player *player1, screens *screen);
void move_up(level1 *game, player *player1, screens *screen);
void move_left(level1 *game, player *player1, screens *screen);
void move_right(level1 *game, player *player1, screens *screen);
sfIntRect create_border_intrect(level1 *game, sfIntRect params, int i);
sfIntRect create_border_intrect(level1 *game, sfIntRect params, int i);
collision_t create_border(level1 *game,
sfVector2f size, sfVector2f pos, int i);
void create_map_border_collisions(level1 *game);
void create_first_five_collisions(level1 *game);
void create_ten_collisions(level1 *game);
void create_fifteen_collisions(level1 *game);
void create_twenty_collisions(level1 *game);
void create_water(frame_buffer *buffer);
void put_pixel_line(sfColor color, frame_buffer *frame, int i);
frame_buffer *create_buffer(unsigned int size_x, unsigned int size_y);
void remove_water(frame_buffer *buffer);
void battle_screen(screens *screen, level1 *game);
void set_items(level1 *game, inventory *stock);
void move_items(level1 *game, sfVector2f movement);
void pick_up_item(level1 *game, player *player1, inventory *stock);
void level1_event_mouse(screens *screen, level1 *game, player *player1);
bool event_menu_pause(screens *screen, menus *menu);
void level1_event_key(screens *screen, level1 *game);
void set_enemy(enemy_t *enemy);
sfBool check_hitbox_pnj(sfBool coll, level1 *game, player *player1);
sfBool check_colisions_border(sfBool coll, level1 *game, player *player1);
void create_snow(frame_buffer *frame);
void remove_particules(frame_buffer *frame);
void draw_snow(level1 *game, bool snow_active, bool water_active);
void draw_water(level1 *game, bool water_active, bool snow_active);
void wether_gestion(level1 *game);
void detect_enemy_collision(screens *screen, player *player1, level1 *game, sfVector2f pos);
