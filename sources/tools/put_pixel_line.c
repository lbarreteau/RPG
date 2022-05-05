/*
** EPITECH PROJECT, 2022
** Put pixel line
** File description:
** to complete
*/

#include "level1_screen.h"

void put_pixel_line(sfColor color, frame_buffer *frame, int i)
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

frame_buffer *create_buffer(unsigned int size_x, unsigned int size_y)
{
    frame_buffer *buffer;

    buffer = malloc(sizeof(frame_buffer));
    buffer->width = size_x;
    buffer->height = size_y;
    buffer->pixels = malloc(size_x * size_y * sizeof(sfUint8) * 4);
    buffer->texture = sfTexture_create(1920, 1080);
    buffer->sprite = sfSprite_create();
    return (buffer);
}
