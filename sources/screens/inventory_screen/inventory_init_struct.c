/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "inventory.h"

static char **find_inventory_properties_from_file(void)
{
    char *buffer;
    char **array;

    buffer = open_and_read_file("properties/inventory.properties");
    if (buffer == NULL) {
        free(buffer);
        return (NULL);
    }
    array = str_to_word_array(buffer);
    free(buffer);
    return (array);
}

void init_inventory_struct(inventory *stock)
{
    char **array_settings = find_inventory_properties_from_file();

    for (int i = 0; i < 10; i++) {
        stock->asset[i] = strdup(array_settings[i * 2 + 1]);
    }
    free_array(array_settings);
}
