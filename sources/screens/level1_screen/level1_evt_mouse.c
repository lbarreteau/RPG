/*
** EPITECH PROJECT, 2022
** level1_evt_mouse
** File description:
** level1_evt_mouse
*/

#include "level1_screen.h"

void modif_collisions(level1 *game, sfVector2f scale_modif, screens *screen)
{
    sfVector2f pos[21];

    for (int i = 0; i < 21; i++) {
        pos[i] = sfRectangleShape_getPosition(game->collisions[i].border);
    }
    for (int i = 0; i < 21; i++) {
        game->collisions[i].scale = scale_modif;
        pos[i].x -= (screen->event.mouseWheelScroll.delta) * 2.1;
        pos[i].y -= (screen->event.mouseWheelScroll.delta) * 2.1;
    }
}

static void scroll(screens *screen, level1 *game, player *player1)
{
    sfVector2f scale = sfSprite_getScale(game->map.sprite);
    sfVector2f scale_player = sfSprite_getScale(player1->sprite);
    sfVector2f pos = sfSprite_getPosition(game->map.sprite);

    scale.x += (screen->event.mouseWheelScroll.delta) / 250;
    scale.y += (screen->event.mouseWheelScroll.delta) / 250;
    scale_player.x += (screen->event.mouseWheelScroll.delta) / 250;
    scale_player.y += (screen->event.mouseWheelScroll.delta) / 250;
    pos.x -= (screen->event.mouseWheelScroll.delta) * 2.1;
    pos.y -= (screen->event.mouseWheelScroll.delta) * 2.1;
    modif_collisions(game, scale, screen);
    sfSprite_setScale(player1->sprite, scale_player);
    sfSprite_setScale(game->map.sprite, scale);
    sfSprite_setPosition(game->map.sprite, pos);
}

static void reset_zoom(level1 *game)
{
    sfVector2f scale = sfSprite_getScale(game->map.sprite);

    scale.x = 4;
    scale.y = 4;
    sfSprite_setScale(game->map.sprite, scale);
}

void level1_event_mouse(screens *screen, level1 *game, player *player1)
{
    if (sfMouse_isButtonPressed(sfMouseMiddle) == true) {
        reset_zoom(game);
    }
    if (screen->event.type == sfEvtMouseWheelScrolled) {
        scroll(screen, game, player1);
    }
}
