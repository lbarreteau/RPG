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
    sfText *text;
    int max_health;
    int health;
    int damage;
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
void set_health_bar(stats *stat, sfVector2f pos_bar);
void check_health(player *player1);