/*
** EPITECH PROJECT, 2022
** Wether gestion
** File description:
** to complete
*/

#include "level1_screen.h"

static void water_gestion(level1 *game, bool water_active)
{
    if (rand() % 500 == 0) {
        water_active = !water_active;
    }
    if (water_active == true) {
        create_water(game->buffer);
    } else {
        remove_water(game->buffer);
    }
}

static void snow_gestion(level1 *game, bool snow_active)
{
    if (rand() % 500 == 0) {
        snow_active = !snow_active;
    }
    if (snow_active == true) {
        create_snow(game->buffer);
    } else {
        remove_snow(game->buffer);
    }
}

void wether_gestion(level1 *game)
{
    static bool snow_active = false;
    static bool water_active = false;

    sfSprite_setTexture(game->buffer->sprite, game->buffer->texture, sfFalse);
    water_gestion(game, water_active);
    snow_gestion(game, snow_active);
}