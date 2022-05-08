/*
** EPITECH PROJECT, 2022
** move_player
** File description:
** move the player
*/

#include "level1_screen.h"
#include "player.h"

void static_position(level1 *game, player *player1)
{
    (void) game;
    player1->rect.left = 52;
}

sfBool check_hitbox_pnj(sfBool coll, level1 *game, player *player1)
{
    if (sfIntRect_intersects(&player1->hitbox, &game->hitbox_pnj, NULL) ==
    sfTrue) {
        coll = sfTrue;
        game->dialog_active_2 = true;
    }
    if (sfIntRect_intersects(&player1->hitbox, &game->hitbox_pnj2, NULL)
    == sfTrue) {
        coll = sfTrue;
        game->dialog_active = true;
    }
    return (coll);
}

sfBool check_colisions_border(sfBool coll, level1 *game, player *player1)
{
    for (int i = 0; i < 21; i++) {
        if (sfIntRect_intersects(&player1->hitbox,
            &game->collisions[i].border_rect, NULL) == sfTrue) {
            coll = sfTrue;
            return (coll);
        }
    }
    return (coll);
}

void move_player(level1 *game, player *player1)
{
    void (*orientation[5])(level1 *, player *) = {&static_position,
        &move_right, &move_left, &move_up, &move_down};

    game->time = sfClock_getElapsedTime(game->clock);
    game->seconds = game->time.microseconds / 1000000.0;
    if (player1->rect.left == 0) {
        player1->status = 1;
    }
    if (player1->rect.left == 104) {
        player1->status = -1;
    }
    if (game->seconds > 0.14) {
        player1->rect.left += 52 * player1->status;
        wether_gestion(game);
        sfClock_restart(game->clock);
    }
    orientation[game->move_direction](game, player1);
}
