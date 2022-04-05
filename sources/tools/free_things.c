/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include <stdlib.h>

void free_array(char **array)
{
    for (int y = 0; array[y] != NULL; y++) {
        free(array[y]);
    }
    free(array);
}
