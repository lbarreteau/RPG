/*
** EPITECH PROJECT, 2022
** fight_screen.h
** File description:
** fight_screen.h
*/

#pragma once

#include "global.h"
#include "player.h"

typedef struct protection {
    struct sprite sprite;
    sfIntRect hitbox;
    bool is_activ;
    sfClock *clock;
    sfTime time;
    float seconds;
} protection;

typedef struct attack_s {
    struct sprite sprite;
    sfIntRect rect;
    sfIntRect hitbox;
    bool is_activ;
    bool exist;
    sfClock *animation;
    sfClock *movement;
    sfClock *reload;
    sfVector2f pos;
    sfTime time;
    float seconds;
} attack_t;

typedef struct ennemies_s {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    int life;
    int experience;
    sfVector2f position;
    sfIntRect hitbox;
    sfVector2f scale;
} ennemies_t;

typedef struct fight_screen
{
    struct player player_fight;
    struct sprite map;
    struct protection bubble;
    struct ennemies_s ennemy[3];
    struct attack_s attack_ennemy[10];
    struct attack_s attack_player;
    sfFont *font;
    sfText *key_press;
    sfText *key_to_press;
    int random;
    bool check_rand;
    sfClock *attack_clock;
    sfTime time;
    float seconds;
} fight_screen;

void fight_scrn(screens *screen, player *player1);
void free_fight_screen(fight_screen *fight);
void set_fight_screen(fight_screen *fight);
void init_fight_screen_struct(fight_screen *fight);
bool event_management_fight_screen(screens *screen, fight_screen *fight);
void draw_fight_screen(screens *screen, fight_screen *fight);
void set_player_fight(fight_screen *fight, player *player1);
void init_text_to_display(fight_screen *fight, sfText *text, sfVector2f pos,
                        char *str);
void set_attack_ennemy(attack_t *attack, sfIntRect rect, int i);
void fireball_animation(attack_t *fireball, int movement);
bool check_collisions_fireball_player(fight_screen *fight);
void destroy_attack(attack_t *attack);
void set_ennemy_fight(fight_screen *fight);
void set_attack_player(attack_t *attack, sfIntRect rect, int i);
bool check_collisions_fireball_ennemy(fight_screen *fight);
char *conv_nbr_into_key(int key);
void init_key_to_press(fight_screen *fight, sfText *text, sfVector2f pos,
                            char *str);
void init_text_to_display(fight_screen *fight, sfText *text, sfVector2f pos,
                            char *str);
