/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"
#include "menu_screen.h"

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

void init_menu_struct(menus *menu)
{
    char **array_settings = find_menu_properties_from_file();

    menu->name_sign = strdup(array_settings[1]);
    menu->name_sign_dark = strdup(array_settings[3]);
    menu->name_music = strdup(array_settings[5]);
    free_array(array_settings);
}
