/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "level1_screen.h"
#include "inventory.h"

static void movement_redirection(screens *screen, level1 *game)
{
    if (screen->event.key.code == screen->list_key[1]) {
        game->move_direction = 1;
    }
    if (screen->event.key.code == screen->list_key[0]) {
        game->move_direction = 2;
    }
    if (screen->event.key.code == screen->list_key[2]) {
        game->move_direction = 3;
    }
    if (screen->event.key.code == screen->list_key[3]) {
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

bool event_level1(screens *screen, level1 *game, inventory *stock)
{
    if (screen->event.type == sfEvtClosed) {
        return (true);
    }
    if (screen->event.type == sfEvtKeyPressed) {
        if (screen->event.key.code == screen->list_key[4]) {
            screen->inv_is_set = !screen->inv_is_set;
        }
        movement_redirection(screen, game);
    }
    if (screen->event.type == sfEvtMouseWheelScrolled) {
        scroll(screen, game);
    }
    if (screen->event.type == sfEvtKeyReleased) {
        if (screen->event.key.code == screen->list_key[0]
        || screen->event.key.code == screen->list_key[1]
        || screen->event.key.code == screen->list_key[2]
        || screen->event.key.code == screen->list_key[3]) {
            game->move_direction = 0;
        }
    }
    if (screen->inv_is_set == true)
        event_inventory(screen, stock);
    return (false);
}
