/*
** EPITECH PROJECT, 2022
** init_fight_screen_struct
** File description:
** init fight screen struct
*/

#include "fight_screen.h"
#include "global.h"

static char **find_menu_properties_from_file(void)
{
    char *buffer;
    char **array;

    buffer = open_and_read_file("properties/fight.properties");
    if (buffer == NULL) {
        free(buffer);
        return (NULL);
    }
    array = str_to_word_array(buffer);
    free(buffer);
    return (array);
}

void init_fight_screen_struct(fight_screen *fight)
{
    char **array_settings = find_menu_properties_from_file();

    free_array(array_settings);
}
