/*
** EPITECH PROJECT, 2022
** set_movement
** File description:
** set_movement
*/

#include "level1_screen.h"
#include "player.h"

void move_right(level1 *game, player *player1)
{
    sfVector2f pos_player = sfSprite_getPosition(game->map.sprite);
    sfVector2f pos_pnj = sfSprite_getPosition(game->pnj.sprite);
    sfBool coll = sfFalse;

    player1->hitbox.width += 4;
    for (int i = 0; i < 21; i++) {
        if (sfIntRect_intersects(&player1->hitbox,
            &game->collisions[i].border_rect, NULL) == sfTrue) {
            coll = sfTrue;
            break;
        }
    }
    if (coll == sfFalse) {
        modif_collisions_pos(game[0], (sfVector2f){-4, 0});
        move_items(game, (sfVector2f){-4, 0});
        pos_player.x -= 4;
        pos_pnj.x -= 4;
        sfSprite_setPosition(game->map.sprite, pos_player);
        sfSprite_setPosition(game->pnj.sprite, pos_pnj);
    }
    player1->hitbox.width -= 4;
    player1->rect.top = 144;
}

void move_left(level1 *game, player *player1)
{
    sfVector2f pos_player = sfSprite_getPosition(game->map.sprite);
    sfVector2f pos_pnj = sfSprite_getPosition(game->pnj.sprite);
    sfBool coll = sfFalse;

    player1->hitbox.left -= 4;
    for (int i = 0; i < 21; i++) {
        if (sfIntRect_intersects(&player1->hitbox,
            &game->collisions[i].border_rect, NULL) == sfTrue) {
                coll = sfTrue;
                break;
        }
    }
    if (coll == sfFalse) {
        modif_collisions_pos(game[0], (sfVector2f){4, 0});
        move_items(game, (sfVector2f){4, 0});
        pos_player.x += 4;
        pos_pnj.x += 4;
        sfSprite_setPosition(game->map.sprite, pos_player);
        sfSprite_setPosition(game->pnj.sprite, pos_pnj);
    }
    player1->hitbox.left += 4;
    player1->rect.top = 72;
}

void move_up(level1 *game, player *player1)
{
    sfVector2f pos_player = sfSprite_getPosition(game->map.sprite);
    sfVector2f pos_pnj = sfSprite_getPosition(game->pnj.sprite);
    sfBool coll = sfFalse;

    player1->hitbox.top -= 4;
    for (int i = 0; i < 21; i++) {
        if (sfIntRect_intersects(&player1->hitbox,
            &game->collisions[i].border_rect, NULL) == sfTrue) {
            coll = sfTrue;
            break;
        }
    }
    if (coll == sfFalse) {
        modif_collisions_pos(game[0], (sfVector2f){0, 4});
        move_items(game, (sfVector2f){0, 4});
        pos_player.y += 4;
        pos_pnj.y += 4;
        sfSprite_setPosition(game->map.sprite, pos_player);
        sfSprite_setPosition(game->pnj.sprite, pos_pnj);
    }
    player1->hitbox.top += 4;
    player1->rect.top = 216;
}

void move_down(level1 *game, player *player1)
{
    sfVector2f pos_player = sfSprite_getPosition(game->map.sprite);
    sfVector2f pos_pnj = sfSprite_getPosition(game->pnj.sprite);
    sfBool coll = sfFalse;

    player1->hitbox.height += 4;
    for (int i = 0; i < 21; i++) {
        if (sfIntRect_intersects(&player1->hitbox,
            &game->collisions[i].border_rect, NULL) == sfTrue) {
            coll = sfTrue;
            break;
        }
    }
    if (coll == sfFalse) {
        modif_collisions_pos(game[0], (sfVector2f){0, -4});
        move_items(game, (sfVector2f){0, -4});
        pos_player.y -= 4;
        pos_pnj.y -= 4;
        sfSprite_setPosition(game->map.sprite, pos_player);
        sfSprite_setPosition(game->pnj.sprite, pos_pnj);
    }
    player1->hitbox.height -= 4;
    player1->rect.top = 0;
}
