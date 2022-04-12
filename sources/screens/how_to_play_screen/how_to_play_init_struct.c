/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "how_to_play.h"

static char **find_how_to_play_properties_from_file(void)
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

    game->name_player_sprite = strdup(array_settings[1]);
    game->name_background_sign = strdup(array_settings[3]);
    game->name_exemple_map = strdup(array_settings[5]);
    game->name_title = strdup(array_settings[7]);
    free_array(array_settings);
}
