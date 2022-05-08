/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "how_to_play.h"

char **find_how_to_play_properties_from_file(void)
{
    char *buffer;
    char **array;

    buffer = open_and_read_file("properties/how_to_play.properties");
    if (buffer == NULL) {
        free(buffer);
        return (NULL);
    }
    array = str_to_word_array(buffer);
    free(buffer);
    return (array);
}

void init_how_to_play_struct(how_to_play *game)
{
    char **array_settings = find_how_to_play_properties_from_file();

    game->background = my_strdup(array_settings[1]);
    free_array(array_settings);
}
