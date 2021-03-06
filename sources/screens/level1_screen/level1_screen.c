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
#include "menu_screen.h"

void set_all(level1 *game, player *player1)
{
    game->buffer = create_buffer(1920, 1080);
    game->hitbox_pnj = (sfIntRect) {0, 0, 0, 0};
    game->hitbox_pnj2 = (sfIntRect) {0, 0, 0, 0};
    init_level1_struct(game);
    set_player(player1);
    set_level1(game, player1);
    init_all_collisions(game);
    init_inventory_struct(&game->stock);
    set_inventory(&game->stock);
    set_items(game, &game->stock);
    game->dialog_active = false;
    game->dialog_active_2 = false;
    game->buffer->water_active = false;
    game->buffer->snow_active = false;
}

bool check_exit(level1 *game, screens *screen, menus *menu, bool exit)
{
    while (game->pause_event == true) {
        while (sfRenderWindow_pollEvent(screen->window, &screen->event))
            exit = event_menu_pause(screen, menu);
        draw_menu(screen, menu);
        if (exit == true) {
            game->pause_event = false;
            exit = false;
        }
    }
    if (screen->quit_game == true)
        return (true);
    if (exit == true) {
        free_level1(game);
        sfSprite_destroy(game->buffer->sprite);
        sfTexture_destroy(game->buffer->texture);
        free(game->buffer->pixels);
        free(game->buffer);
    }
    return (exit);
}

bool check_event(level1 *game, player *player1, screens *screen)
{
    move_player(game, player1, screen);
    pick_up_item(game, player1, &game->stock);
    check_equipment(player1, &game->stock);
    check_stats(player1);
    draw_level1(screen, game, player1);
    sfRenderWindow_display(screen->window);
    if (screen->is_dead == true) {
        screen->is_dead = false;
        return (false);
    }
    return (true);
}

bool level1_screen(screens *screen, menus *menu)
{
    struct level1 game;
    struct player player1;
    bool exit = false;

    set_all(&game, &player1);
    while (sfRenderWindow_isOpen(screen->window)) {
        while (sfRenderWindow_pollEvent(screen->window, &screen->event) &&
        game.pause_event == false)
            exit = event_level1(screen, &game, &player1);
        if (check_exit(&game, screen, menu, exit) == true || exit == true) {
            return (true);
        }
        if (check_event(&game, &player1, screen) == false)
            return (false);
    }
    free_level1(&game);
    return (true);
}
