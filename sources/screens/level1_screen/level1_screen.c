/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "level1_screen.h"
#include "player.h"
#include "inventory.h"

void set_all(level1 *game, player *player1, inventory *stock)
{
    init_level1_struct(game);
    set_player(player1);
    set_level1(game);
    init_all_collisions(game);
    init_inventory_struct(stock);
    set_inventory(stock);
    set_items(game, stock);
}

void level1_screen(screens *screen)
{
    struct level1 game;
    struct inventory stock;
    struct player player1;
    bool exit = false;

    set_all(&game, &player1, &stock);
    while (sfRenderWindow_isOpen(screen->window)) {
        while (sfRenderWindow_pollEvent(screen->window, &screen->event)) {
            exit = event_level1(screen, &game, &player1, &stock);
        }
        if (exit == true) {
            free_level1(&game);
            return;
        }
        move_player(&game, screen, &player1);
        pick_up_item(&game, &player1, &stock);
        draw_level1(screen, &game, &player1, &stock);
    }
    free_level1(&game);
}
