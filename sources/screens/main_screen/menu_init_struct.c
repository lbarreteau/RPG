/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "menu_screen.h"

static char **find_screen_properties_from_file(void)
{
    char *buffer;
    char **array;

    buffer = open_and_read_file("properties/window.properties");
    if (buffer == NULL) {
        free(buffer);
        return (NULL);
    }
    array = str_to_word_array(buffer);
    free(buffer);
    return (array);
}

void init_screen_struct(screens *screen)
{
    char **array_settings = find_screen_properties_from_file();

    screen->size_screen_length = atoi(array_settings[1]);
    screen->size_screen_width = atoi(array_settings[3]);
    screen->bits_per_pixel = atoi(array_settings[5]);
    screen->name_screen = strdup(array_settings[7]);
    screen->mode.height = screen->size_screen_width;
    screen->mode.width = screen->size_screen_length;
    screen->mode.bitsPerPixel = screen->bits_per_pixel;
    screen->fps = atoi(array_settings[9]);
    screen->name_background = strdup(array_settings[11]);
    free_array(array_settings);
}

static char **find_menu_properties_from_file(void)
{
    char *buffer;
    char **array;

    buffer = open_and_read_file("properties/menu.properties");
    if (buffer == NULL) {
        free(buffer);
        return (NULL);
    }
    array = str_to_word_array(buffer);
    free(buffer);
    return (array);
}

static sfColor recognition_color(char *color)
{
    if (strcmp(color, "WHITE") == 0)
        return (sfWhite);
    if (strcmp(color, "BLACK") == 0)
        return (sfBlack);
    if (strcmp(color, "RED") == 0)
        return (sfRed);
    if (strcmp(color, "BLUE") == 0)
        return (sfBlue);
    if (strcmp(color, "GREEN") == 0)
        return (sfGreen);
    else
        return (sfWhite);
}

void init_menu_struct(menus *menu)
{
    char **array_settings = find_menu_properties_from_file();

    if (strcmp("ON", array_settings[1]) == 0) {
        menu->display_time = true;
    } else {
        menu->display_time = false;
    }
    menu->theme_color = recognition_color(array_settings[3]);
    free_array(array_settings);
}