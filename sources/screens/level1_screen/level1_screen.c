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

void set_all(level1 *game, player *player1)
{
    init_level1_struct(game);
    set_player(player1);
    set_level1(game, player1);
    init_all_collisions(game);
    init_inventory_struct(&game->stock);
    set_inventory(&game->stock);
    set_items(game, &game->stock);
}

void level1_screen(screens *screen)
{
    struct level1 game;
    struct player player1;
    struct frame_buffer *buffer;
    bool exit = false;

    srand(time(NULL));
    set_all(&game, &player1);
    buffer = create_buffer(1920, 1080);
    while (sfRenderWindow_isOpen(screen->window)) {
        while (sfRenderWindow_pollEvent(screen->window, &screen->event)) {
            exit = event_level1(screen, &game, &player1, buffer);
        }
        if (exit == true) {
            free_level1(&game);
            // free buffer particules
            sfSprite_destroy(buffer->sprite);
            sfTexture_destroy(buffer->texture);
            free(buffer->pixels);
            free(buffer);
            return;
        }
        // sfSprite_setTexture(buffer->sprite, buffer->texture, sfFalse);
        // create_snow(buffer);
        move_player(&game, &player1);
        pick_up_item(&game, &player1, &game.stock);
        check_equipment(&player1, &game.stock);
        check_stats(&player1);
        draw_level1(screen, &game, &player1, buffer);
        sfRenderWindow_display(screen->window);
    }
    free_level1(&game);
}
