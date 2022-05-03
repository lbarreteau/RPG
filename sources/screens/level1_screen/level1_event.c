/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "level1_screen.h"
#include "fight_screen.h"

static void movement_redirection(screens *screen, level1 *game)
{
    if (screen->event.key.code == sfKeyI) {
        fight_scrn(screen);
    }
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

void modif_collisions(level1 *game, sfVector2f scale_modif, screens *screen,
                        player *player1)
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
    modif_collisions(game, scale, screen, player1);
    sfSprite_setScale(player1->sprite, scale_player);
    sfSprite_setScale(game->map.sprite, scale);
    sfSprite_setPosition(game->map.sprite, pos);
}

bool event_level1(screens *screen, level1 *game, player *player1)
{

    if (screen->event.type == sfEvtClosed) {
        return (true);
    }
    if (screen->event.type == sfEvtKeyPressed) {
        movement_redirection(screen, game);
    }
    if (screen->event.type == sfEvtMouseWheelScrolled) {
        scroll(screen, game, player1);
    }
    if (screen->event.type == sfEvtKeyReleased) {
        if (screen->event.key.code == sfKeyDown || screen->event.key.code ==
            sfKeyUp || screen->event.key.code == sfKeyLeft ||
            screen->event.key.code == sfKeyRight) {
            game->move_direction = 0;
        }
    }
    return (false);
}
