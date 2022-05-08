/*
** EPITECH PROJECT, 2022
** RPG
** File description:
** check_each_scene_assets
*/

#include "global.h"

int check_screen_properties(void)
{
    char **array_settings = find_screen_properties_from_file();
    FILE *fd;

    if (array_settings[13] == NULL)
        return (84);
    if ((fd = fopen(array_settings[11], "r")) == NULL) {
        return (84);
    }
    fclose(fd);
    free_array(array_settings);
    return (0);
}

int check_menu_properties(void)
{
    char **array_settings = find_menu_properties_from_file();
    FILE *fd;

    for (int i = 1; i <= 11; i += 2) {
        if ((fd = fopen(array_settings[i], "r")) == NULL) {
            return (84);
        }
        fclose(fd);
    }
    free_array(array_settings);
    return (0);
}

int check_settings_properties(void)
{
    char **array_settings = find_settings_properties_from_file();
    FILE *fd;

    for (int i = 1; i <= 21; i += 2) {
        if ((fd = fopen(array_settings[i], "r")) == NULL) {
            return (84);
        }
        fclose(fd);
    }
    free_array(array_settings);
    return (0);
}

int check_how_to_play_properties(void)
{
    char **array_settings = find_how_to_play_properties_from_file();
    FILE *fd;

    if ((fd = fopen(array_settings[1], "r")) == NULL) {
        return (84);
    }
    fclose(fd);
    free_array(array_settings);
    return (0);
}

int check_level1_properties(void)
{
    char **array_settings = find_level1_properties_from_file();
    FILE *fd;

    for (int i = 1; i <= 5; i += 2) {
        if ((fd = fopen(array_settings[i], "r")) == NULL) {
            return (84);
        }
        fclose(fd);
    }
    free_array(array_settings);
    return (0);
}
