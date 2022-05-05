/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "level1_screen.h"

static void movement_redirection(screens *screen, level1 *game)
{
    if (screen->event.key.code == sfKeyRight) {
        game->move_direction = 1;
    }
    if (screen->event.key.code == sfKeyLeft) {
        game->move_direction = 2;
    }
    if (screen->event.key.code == sfKeyUp) {
        game->move_direction = 3;
    }
    if (screen->event.key.code == sfKeyDown) {
        game->move_direction = 4;
    }
}

static void scroll(screens *screen, level1 *game)
{
    sfVector2f scale = sfSprite_getScale(game->map.sprite);
    sfVector2f pos = sfSprite_getPosition(game->map.sprite);

    scale.x += (screen->event.mouseWheelScroll.delta) / 250;
    scale.y += (screen->event.mouseWheelScroll.delta) / 250;
    pos.x -= (screen->event.mouseWheelScroll.delta) * 2.1;
    pos.y -= (screen->event.mouseWheelScroll.delta) * 2.1;
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

bool event_level1(screens *screen, level1 *game)
{
    if (screen->event.type == sfEvtClosed) {
        return (true);
    }
    if (screen->event.type == sfEvtKeyPressed) {
        movement_redirection(screen, game);
    }
    if (sfMouse_isButtonPressed(sfMouseMiddle) == true) {
        reset_zoom(game);
    }
    if (screen->event.type == sfEvtMouseWheelScrolled) {
        scroll(screen, game);
    }
    if (screen->event.type == sfEvtKeyReleased) {
        if (screen->event.key.code == sfKeyDown || screen->event.key.code == sfKeyUp || screen->event.key.code == sfKeyLeft || screen->event.key.code == sfKeyRight) {
            game->move_direction = 0;
        }
    }
    return (false);
}
