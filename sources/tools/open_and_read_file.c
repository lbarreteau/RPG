/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static long file_size(char const *filepath)
{
    struct stat s_stat;

    stat(filepath, &s_stat);
    return (s_stat.st_size);
}

char *open_and_read_file(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int size = file_size(filepath);
    char *buffer = malloc(sizeof(char) * (size + 1));
    int ret = -1;

    if (fd == -1) {
        free(buffer);
        return (NULL);
    }
    ret = read(fd, buffer, size);
    if (ret == -1) {
        free(buffer);
        return (NULL);
    }
    buffer[size] = '\0';
    if (close(fd) == -1)
        return (NULL);
    return (buffer);
}
