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
    sfBool coll = sfFalse;

    player1->hitbox.width += 4;
    for (int i = 0; i < 21; i++) {
        if (sfIntRect_intersects(&player1->hitbox,
            &game->collisions[i].border_rect, NULL) == sfTrue) {
            coll = sfTrue;
            break;
        }
    }
    if (sfIntRect_intersects(&player1->hitbox, &game->hitbox_pnj, NULL) ==
    sfTrue || sfIntRect_intersects(&player1->hitbox, &game->hitbox_pnj2, NULL)
    == sfTrue) {
        printf("coll");
        coll = sfTrue;
    }
    if (coll == sfFalse) {
        modif_collisions_pos(game, (sfVector2f){-4, 0});
        move_items(game, (sfVector2f){-4, 0});
        pos_player.x -= 4;
        sfSprite_setPosition(game->map.sprite, pos_player);
    }
    player1->hitbox.width -= 4;
    player1->rect.top = 144;
}

void move_left(level1 *game, player *player1)
{
    sfVector2f pos_player = sfSprite_getPosition(game->map.sprite);
    sfBool coll = sfFalse;

    player1->hitbox.left -= 4;
    for (int i = 0; i < 21; i++) {
        if (sfIntRect_intersects(&player1->hitbox,
            &game->collisions[i].border_rect, NULL) == sfTrue) {
                coll = sfTrue;
                break;
        }
    }
    if (sfIntRect_intersects(&player1->hitbox, &game->hitbox_pnj, NULL) ==
    sfTrue || sfIntRect_intersects(&player1->hitbox, &game->hitbox_pnj2, NULL)
    == sfTrue) {
        printf("coll");
        coll = sfTrue;
    }
    if (coll == sfFalse) {
        modif_collisions_pos(game, (sfVector2f){4, 0});
        move_items(game, (sfVector2f){4, 0});
        pos_player.x += 4;
        sfSprite_setPosition(game->map.sprite, pos_player);
    }
    player1->hitbox.left += 4;
    player1->rect.top = 72;
}

void move_up(level1 *game, player *player1)
{
    sfVector2f pos_player = sfSprite_getPosition(game->map.sprite);
    sfBool coll = sfFalse;

    player1->hitbox.top -= 4;
    for (int i = 0; i < 21; i++) {
        if (sfIntRect_intersects(&player1->hitbox,
            &game->collisions[i].border_rect, NULL) == sfTrue) {
            coll = sfTrue;
            break;
        }
    }
    if (sfIntRect_intersects(&player1->hitbox, &game->hitbox_pnj, NULL) ==
    sfTrue || sfIntRect_intersects(&player1->hitbox, &game->hitbox_pnj2, NULL)
    == sfTrue) {
        printf("coll");
        coll = sfTrue;
    }
    if (coll == sfFalse) {
        modif_collisions_pos(game, (sfVector2f){0, 4});
        move_items(game, (sfVector2f){0, 4});
        pos_player.y += 4;
        sfSprite_setPosition(game->map.sprite, pos_player);
    }
    printf("pos_player y = %i  x = %i\n", player1->hitbox.top, player1->hitbox.left);
    printf("pos_coll_pnj y = %i  x = %i\n", game->hitbox_pnj.top , game->hitbox_pnj2.top);

    player1->hitbox.top += 4;
    player1->rect.top = 216;
}

void move_down(level1 *game, player *player1)
{
    sfVector2f pos_player = sfSprite_getPosition(game->map.sprite);
    sfBool coll = sfFalse;

    player1->hitbox.height += 4;
    for (int i = 0; i < 21; i++) {
        if (sfIntRect_intersects(&player1->hitbox,
            &game->collisions[i].border_rect, NULL) == sfTrue) {
            coll = sfTrue;
            break;
        }
    }
    if (sfIntRect_intersects(&player1->hitbox, &game->hitbox_pnj, NULL) ==
    sfTrue || sfIntRect_intersects(&player1->hitbox, &game->hitbox_pnj2, NULL)
    == sfTrue) {
        printf("coll");
        coll = sfTrue;
    }
    if (coll == sfFalse) {
        modif_collisions_pos(game, (sfVector2f){0, -4});
        move_items(game, (sfVector2f){0, -4});
        pos_player.y -= 4;
        sfSprite_setPosition(game->map.sprite, pos_player);
    }
    player1->hitbox.height -= 4;
    player1->rect.top = 0;
}
