/*
** EPITECH PROJECT, 2022
** enemy.h
** File description:
** enemy.h
*/

#pragma once

#include "global.h"

typedef struct enemy_s
{
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
    bool is_alive;
    sfVector2f position;
    sfIntRect hitbox;
    sfVector2f scale;
} enemy_t;
