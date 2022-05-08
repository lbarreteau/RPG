/*
** EPITECH PROJECT, 2022
** player.h
** File description:
** player.h
*/

#pragma once

#include "global.h"

typedef struct stats {
    sfSprite *sprite[2];
    sfTexture *texture[2];
    sfIntRect rect[2];
    struct text text_dammage;
    sfBool level1;
    int max_health;
    int health;
    int dammage;
    int xp;
} stats;

typedef struct player {
    struct stats stat;
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    int status;
    sfVector2f position;
    sfIntRect hitbox;
    sfVector2f scale;
} player;

void set_player(player *player1);
void set_stats(stats *stat);
void check_stats(player *player1);
void check_health(player *player1);
void set_health_bar(stats *stat, sfVector2f pos_bar);
