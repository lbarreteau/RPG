/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"

sfColor recognition_color(char *color)
{
    if (my_strcmp(color, "WHITE") == 0)
        return (sfWhite);
    if (my_strcmp(color, "BLACK") == 0)
        return (sfBlack);
    if (my_strcmp(color, "RED") == 0)
        return (sfRed);
    if (my_strcmp(color, "BLUE") == 0)
        return (sfBlue);
    if (my_strcmp(color, "GREEN") == 0)
        return (sfGreen);
    else
        return (sfWhite);
}
