/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "global.h"

sfColor recognition_color(char *color)
{
    if (strcmp(color, "WHITE") == 0)
        return (sfWhite);
    if (strcmp(color, "BLACK") == 0)
        return (sfBlack);
    if (strcmp(color, "RED") == 0)
        return (sfRed);
    if (strcmp(color, "BLUE") == 0)
        return (sfBlue);
    if (strcmp(color, "GREEN") == 0)
        return (sfGreen);
    else
        return (sfWhite);
}
