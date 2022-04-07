/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "level1_screen.h"

static char **find_menu_properties_from_file(void)
{
    char *buffer;
    char **array;

    buffer = open_and_read_file("properties/level1.properties");
    if (buffer == NULL) {
        free(buffer);
        return (NULL);
    }
    array = str_to_word_array(buffer);
    free(buffer);
    return (array);
}

void init_level1_struct(level1 *game)
{
    char **array_settings = find_menu_properties_from_file();

    game->theme_color = recognition_color(array_settings[1]);
    free_array(array_settings);
}
