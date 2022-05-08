/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "level1_screen.h"

char **find_level1_properties_from_file(void)
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
    char **array_settings = find_level1_properties_from_file();

    game->name_screen_background = strdup(array_settings[1]);
    game->name_pnj = strdup(array_settings[3]);
    game->name_pnj_2 = strdup(array_settings[5]);
    free_array(array_settings);
}
