/*
** EPITECH PROJECT, 2021
** My_strlen
** File description:
** This script counts and returns the number of characters found.
*/

int my_strlen(char const *str)
{
    int size_str = 0;

    while (str[size_str] != '\0') {
        size_str++;
    }
    return (size_str);
}
