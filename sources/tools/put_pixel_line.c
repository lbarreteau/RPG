/*
** EPITECH PROJECT, 2022
** Put pixel line
** File description:
** to complete
*/

#include "level1_screen.h"

void put_pixel_line(sfColor color, buffer_t *frame, int i)
{
    frame->pixels[i] = color.r;
    frame->pixels[i + 1] = color.g;
    frame->pixels[i + 2] = color.b;
    frame->pixels[i + 3] = color.a;
    frame->pixels[i + 4] = color.r;
    frame->pixels[i + 5] = color.g;
    frame->pixels[i + 6] = color.b;
    frame->pixels[i + 7] = color.a;
}

buffer_t *create_buffer(unsigned int size_x, unsigned int size_y)
{
    buffer_t *buffer;

    buffer = malloc(sizeof(buffer_t));
    buffer->size_x = size_x;
    buffer->size_y = size_y;
    buffer->pixels = malloc(size_x * size_y * sizeof(sfUint8) * 4);
    return (buffer);
}
