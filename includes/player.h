/*
** EPITECH PROJECT, 2022
** player.h
** File description:
** player.h
*/

#pragma once

#include "global.h"

typedef struct player {
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    int status;
    sfVector2f position;
    sfIntRect hitbox;
    sfVector2f scale;
} player;

void set_player(player *player1);
