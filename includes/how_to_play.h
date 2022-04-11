/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** libmy.a in this file
*/

#pragma once

#include "global.h"

typedef struct how_to_play {
    char *name_player_sprite;
    struct sprite player;
    char *name_background_sign;
    struct sprite how_to_play_sign;
    struct sprite exemple_map;
    char *name_exemple_map;
} how_to_play;

