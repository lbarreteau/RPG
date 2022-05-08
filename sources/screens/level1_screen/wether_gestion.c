/*
** EPITECH PROJECT, 2022
** Wether gestion
** File description:
** to complete
*/

#include "level1_screen.h"

void draw_water(level1 *game, bool water_active, bool snow_active)
{
    if (water_active == true && snow_active == false) {
        create_water(game->buffer);
    }
    if (water_active == false) {
        remove_particules(game->buffer);
    }
}

void draw_snow(level1 *game, bool snow_active, bool water_active)
{
    if (snow_active == true && water_active == false) {
        create_snow(game->buffer);
    }
    if (snow_active == false) {
        remove_particules(game->buffer);
    }
}

void wether_gestion(level1 *game)
{
    sfSprite_setTexture(game->buffer->sprite, game->buffer->texture, sfFalse);
    if (rand() % 50 == 0) {
        game->buffer->water_active = !game->buffer->water_active;
    }
    if (rand() % 100 == 0) {
        game->buffer->snow_active = !game->buffer->snow_active;
    }
}