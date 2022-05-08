/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "settings_screen.h"

char **find_settings_properties_from_file(void)
{
    char *buffer;
    char **array;

    buffer = open_and_read_file("properties/settings.properties");
    if (buffer == NULL) {
        free(buffer);
        return (NULL);
    }
    array = str_to_word_array(buffer);
    free(buffer);
    return (array);
}

void init_settings_struct(settings *setting)
{
    char **array_settings = find_settings_properties_from_file();

    for (int i = 0; i < 11; i++) {
        setting->asset_btn[i] = strdup(array_settings[i * 2 + 1]);
    }
    free_array(array_settings);
}
