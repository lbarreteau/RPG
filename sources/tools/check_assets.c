/*
** EPITECH PROJECT, 2022
** check_assets
** File description:
** check_assets
*/

#include "global.h"

int check_first_part_assets(void)
{
    FILE *fd;

    if ((fd = fopen("assets/pictures/inventory/hearth.png", "r")) == NULL)
        return (84);
    fclose(fd);
    if ((fd = fopen("assets/pictures/inventory/no_hearth.png", "r")) == NULL)
        return (84);
    fclose(fd);
    if ((fd = fopen("assets/pictures/sign/long_sign_dark.png", "r")) == NULL)
        return (84);
    fclose(fd);
    if ((fd = fopen("assets/pictures/sign/long_sign_click.png", "r")) == NULL)
        return (84);
    fclose(fd);
    return (0);
}

int check_second_part_assets(void)
{
    FILE *fd;

    if ((fd = fopen("assets/pictures/sprite/fireball.png", "r")) == NULL)
        return (84);
    fclose(fd);
    if ((fd = fopen("assets/pictures/sprite/npc_sprite.png", "r")) == NULL)
        return (84);
    fclose(fd);
    if ((fd = fopen("assets/families/global_font.ttf", "r")) == NULL)
        return (84);
    fclose(fd);
    if ((fd = fopen("assets/pictures/map/map_fight.png", "r")) == NULL)
        return (84);
    fclose(fd);
    if ((fd = fopen(
        "assets/pictures/settings/sliderbar_button.png", "r")) == NULL)
        return (84);
    fclose(fd);
    return (0);
}

int check_assets(void)
{
    if (check_screen_properties() == 84)
        return (84);
    if (check_menu_properties() == 84)
        return (84);
    if (check_settings_properties() == 84)
        return (84);
    if (check_how_to_play_properties() == 84)
        return (84);
    if (check_level1_properties() == 84)
        return (84);
    if (check_first_part_assets() == 84)
        return (84);
    if (check_second_part_assets() == 84)
        return (84);
    return (0);
}
