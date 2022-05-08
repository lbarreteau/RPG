/*
** EPITECH PROJECT, 2022
** free_fight_screen
** File description:
** free fight screen
*/

#include "fight_screen.h"
#include "global.h"

static void free_sprite(fight_screen *fight)
{
    sfSprite_destroy(fight->ennemy[0].sprite);
    sfTexture_destroy(fight->ennemy[0].texture);
    sfSprite_destroy(fight->player_fight.sprite);
    sfTexture_destroy(fight->player_fight.texture);
    sfSprite_destroy(fight->bubble.sprite.sprite);
    sfTexture_destroy(fight->bubble.sprite.texture);
    sfClock_destroy(fight->bubble.clock);
    sfClock_destroy(fight->attack_clock);
}

static void free_character(fight_screen *fight)
{
    sfSprite_destroy(fight->attack_player.sprite.sprite);
    sfTexture_destroy(fight->attack_player.sprite.texture);
    sfClock_destroy(fight->attack_player.animation);
    sfClock_destroy(fight->attack_player.movement);
    sfClock_destroy(fight->attack_player.reload);
    for (int i = 0; i < 10; i++) {
        sfSprite_destroy(fight->attack_ennemy[i].sprite.sprite);
        sfTexture_destroy(fight->attack_ennemy[i].sprite.texture);
        sfClock_destroy(fight->attack_ennemy[i].animation);
        sfClock_destroy(fight->attack_ennemy[i].movement);
        sfClock_destroy(fight->attack_ennemy[i].reload);
    }
}

void free_fight_screen(fight_screen *fight)
{
    free_sprite(fight);
    free_character(fight);
    sfFont_destroy(fight->font);
    sfText_destroy(fight->key_press);
    sfText_destroy(fight->key_to_press);
    sfSprite_destroy(fight->map.sprite);
    sfTexture_destroy(fight->map.texture);
    sfSprite_destroy(fight->ennemy[0].stat.sprite[0]);
    sfSprite_destroy(fight->ennemy[0].stat.sprite[1]);
    sfTexture_destroy(fight->ennemy[0].stat.texture[0]);
    sfTexture_destroy(fight->ennemy[0].stat.texture[1]);
}
