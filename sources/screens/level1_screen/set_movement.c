/*
** EPITECH PROJECT, 2022
** set_movement
** File description:
** set_movement
*/

#include "level1_screen.h"
#include "player.h"

void move_right(level1 *game, player *player1, screens *screen)
{
    sfVector2f pos_player = sfSprite_getPosition(game->map.sprite);
    sfBool coll = sfFalse;

    player1->hitbox.width += 4;
    coll = check_colisions_border(coll, game, player1);
    coll = check_hitbox_pnj(coll, game, player1);
    if (coll == sfFalse) {
        game->dialog_active = false;
        game->dialog_active_2 = false;
        modif_collisions_pos(game, (sfVector2f){-4, 0});
        move_items(game, (sfVector2f){-4, 0});
        pos_player.x -= 4;
        sfSprite_setPosition(game->map.sprite, pos_player);
        detect_enemy_collision(screen, player1, game, (sfVector2f) {-4, 0});
    }
    player1->hitbox.width -= 4;
    player1->rect.top = 144;
}

void move_left(level1 *game, player *player1, screens *screen)
{
    sfVector2f pos_player = sfSprite_getPosition(game->map.sprite);
    sfBool coll = sfFalse;

    player1->hitbox.left -= 4;
    coll = check_colisions_border(coll, game, player1);
    coll = check_hitbox_pnj(coll, game, player1);
    if (coll == sfFalse) {
        game->dialog_active_2 = false;
        game->dialog_active = false;
        modif_collisions_pos(game, (sfVector2f){4, 0});
        move_items(game, (sfVector2f){4, 0});
        pos_player.x += 4;
        sfSprite_setPosition(game->map.sprite, pos_player);
        detect_enemy_collision(screen, player1, game, (sfVector2f) {4, 0});
    }
    player1->hitbox.left += 4;
    player1->rect.top = 72;
}

void move_up(level1 *game, player *player1, screens *screen)
{
    sfVector2f pos_player = sfSprite_getPosition(game->map.sprite);
    sfBool coll = sfFalse;

    player1->hitbox.top -= 4;
    coll = check_colisions_border(coll, game, player1);
    coll = check_hitbox_pnj(coll, game, player1);
    if (coll == sfFalse) {
        game->dialog_active_2 = false;
        game->dialog_active = false;
        modif_collisions_pos(game, (sfVector2f){0, 4});
        move_items(game, (sfVector2f){0, 4});
        pos_player.y += 4;
        sfSprite_setPosition(game->map.sprite, pos_player);
        detect_enemy_collision(screen, player1, game, (sfVector2f) {0, 4});
    }
    player1->hitbox.top += 4;
    player1->rect.top = 216;
}

void move_down(level1 *game, player *player1, screens *screen)
{
    sfVector2f pos_player = sfSprite_getPosition(game->map.sprite);
    sfBool coll = sfFalse;

    player1->hitbox.height += 4;
    coll = check_colisions_border(coll, game, player1);
    coll = check_hitbox_pnj(coll, game, player1);
    if (coll == sfFalse) {
        game->dialog_active = false;
        game->dialog_active_2 = false;
        modif_collisions_pos(game, (sfVector2f){0, -4});
        move_items(game, (sfVector2f){0, -4});
        pos_player.y -= 4;
        sfSprite_setPosition(game->map.sprite, pos_player);
        detect_enemy_collision(screen, player1, game, (sfVector2f) {0, -4});
    }
    player1->hitbox.height -= 4;
    player1->rect.top = 0;
}
