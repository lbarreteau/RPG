/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "global.h"

int is_alnum(char c)
{
    if (c <= '\n' || c == ':' || c >= 127) {
        return (0);
    }
    return (1);
}

int word_count(char *str)
{
    int i = 0;
    int word = 0;

    while (str != NULL && str[i]) {
        if (is_alnum(str[i]) == 1 && is_alnum(str[i + 1]) == 0) {
            word = word + 1;
        }
        i = i + 1;
    }
    return (word);
}

char **str_to_word_array(char *str)
{
    int j = 0;
    int i = 0;
    char **wordtab;
    int len = 0;

    wordtab = malloc((word_count(str) + 1) * sizeof(char *));
    while (str != NULL && str[i]) {
        if (is_alnum(str[i]))
            len = len + 1;
        if (is_alnum(str[i]) == 1 && is_alnum(str[i + 1]) == 0) {
            wordtab[j] = malloc(len + 1);
            my_strncpy(wordtab[j], &str[i - len + 1], len);
            wordtab[j][len] = '\0';
            len = 0;
            j++;
        }
        i++;
    }
    wordtab[j] = NULL;
    return (wordtab);
}
