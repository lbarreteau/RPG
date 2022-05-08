/*
** EPITECH PROJECT, 2022
** set_health
** File description:
** set_health
*/

#include "player.h"

void set_health_rect(stats *stat)
{
    stat->rect[0].height = 52;
    stat->rect[0].width = 60 * stat->health;
    stat->rect[0].top = 0;
    stat->rect[0].left = 0;
    stat->rect[1].height = 52;
    stat->rect[1].width = 0;
    stat->rect[1].top = 0;
    stat->rect[1].left = 0;
}

void set_health_bar(stats *stat, sfVector2f pos_bar)
{
    stat->sprite[0] = sfSprite_create();
    stat->sprite[1] = sfSprite_create();
    stat->texture[0] = sfTexture_createFromFile(
        "assets/pictures/inventory/hearth.png", NULL);
    stat->texture[1] = sfTexture_createFromFile(
        "assets/pictures/inventory/no_hearth.png", NULL);
    set_health_rect(stat);
    sfSprite_setTexture(stat->sprite[0], stat->texture[0], sfFalse);
    sfSprite_setTexture(stat->sprite[1], stat->texture[1], sfFalse);
    sfSprite_setTextureRect(stat->sprite[0], stat->rect[0]);
    sfSprite_setTextureRect(stat->sprite[1], stat->rect[1]);
    sfSprite_setPosition(stat->sprite[0], pos_bar);
    sfSprite_setPosition(stat->sprite[1], pos_bar);
}

void set_text_stat(stats *stat)
{
    stat->text_stat[0].text = sfText_create();
    stat->text_stat[0].font = sfFont_createFromFile(
        "assets/families/global_font.ttf");
    sfText_setFont(stat->text_stat[0].text, stat->text_stat[0].font);
    sfText_setString(stat->text_stat[0].text, "2");
    sfText_setPosition(stat->text_stat[0].text, (sfVector2f){735, 740});
    stat->text_stat[1].text = sfText_create();
    stat->text_stat[1].font = sfFont_createFromFile(
        "assets/families/global_font.ttf");
    sfText_setFont(stat->text_stat[1].text, stat->text_stat[1].font);
    sfText_setString(stat->text_stat[1].text, "level : 1");
    sfText_setPosition(stat->text_stat[1].text, (sfVector2f){735, 805});
    sfText_setScale(stat->text_stat[1].text, (sfVector2f){0.5, 0.5});
}

void set_stats(stats *stat)
{
    stat->health = 3;
    stat->max_health = 3;
    stat->dammage = 1;
    stat->xp = 0;
    stat->level1 = false;
    set_health_bar(stat, (sfVector2f) {50, 50});
    set_text_stat(stat);
}
