/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"

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
