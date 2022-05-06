/*
** EPITECH PROJECT, 2022
** set_items
** File description:
** set_items
*/

#include "inventory.h"
#include "level1_screen.h"

void move_items(level1 *game, sfVector2f movement)
{
    sfVector2f new_pos = {0, 0};

    for (int i = 0; i < 1; i++) {
        if (game->item[i].is_pick == false) {
            new_pos = sfSprite_getPosition(game->item[i].sprite);
            new_pos.x += movement.x;
            new_pos.y += movement.y;
            sfSprite_setPosition(game->item[i].sprite, new_pos);
            game->item[0].rect.top = new_pos.y;
            game->item[0].rect.left = new_pos.x;
        }
    }
}

void set_items(level1 *game, inventory *stock)
{
    game->item[0].texture = sfTexture_createFromFile(stock->asset[8], NULL);
    game->item[0].sprite = sfSprite_create();
    sfSprite_setTexture(game->item[0].sprite, game->item[0].texture, sfFalse);
    sfSprite_setPosition(game->item[0].sprite, (sfVector2f){600, 2000});
    sfSprite_setScale(game->item[0].sprite, (sfVector2f){0.5, 0.5});
    game->item[0].rect.height = sfTexture_getSize(game->item[0].texture).y;
    game->item[0].rect.width = sfTexture_getSize(game->item[0].texture).x;
    game->item[0].rect.top = 600;
    game->item[0].rect.left = 2000;
    game->item[0].type = WEAPON;
    game->item[0].is_pick = false;
}
