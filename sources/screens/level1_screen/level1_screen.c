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

void set_all(level1 *game, player *player1, inventory *stock, frame_buffer *buffer)
{
    init_level1_struct(game);
    set_player(player1);
    set_level1(game);
    init_all_collisions(game);
    init_inventory_struct(stock);
    set_health_bar(&player1->stat, (sfVector2f) {50, 50});
    set_inventory(stock);
    set_items(game, stock);
}

void level1_screen(screens *screen)
{
    struct level1 game;
    struct player player1;
    struct frame_buffer *buffer;
    bool exit = false;

    srand(time(NULL));
    set_all(&game, &player1, &game.stock, buffer);
    buffer = create_buffer(1920, 1080);
    while (sfRenderWindow_isOpen(screen->window)) {
        while (sfRenderWindow_pollEvent(screen->window, &screen->event)) {
            exit = event_level1(screen, &game, &player1, buffer);
        }
        if (exit == true) {
            free_level1(&game);
            return;
        }
        // sfSprite_setTexture(buffer->sprite, buffer->texture, sfFalse);
        // create_snow(buffer);
        move_player(&game, screen, &player1);
        pick_up_item(&game, &player1, &game.stock);
        check_health(&player1);
        draw_level1(screen, &game, &player1, buffer);
        if (screen->inv_is_set == true)
            draw_inventory(screen, &game.stock);
        sfRenderWindow_display(screen->window);
    }
    free_level1(&game);
}
