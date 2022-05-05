/*
** EPITECH PROJECT, 2022
** Wtaer
** File description:
** to complete
*/

#include "level1_screen.h"

void remove_snow(frame_buffer *frame)
{
    static float e = 0;

    e++;
    for (int i = 0; i != (1920 * 1080) * (e / 100); i += 64) {
        put_pixel_line(sfTransparent, frame, i);
        if (e >= 400)
            e = 400;
    }
    sfTexture_updateFromPixels(frame->texture, frame->pixels,
    1920, 1080, 0, 0);
}

void create_snow(frame_buffer *frame)
{
    static float e = 0;

    e++;
    for (int i = 0; i != (1920 * 1080) * (e / 100); i += 8) {
        if (rand() % 8 == 0) {
            put_pixel_line(sfWhite, frame, i);
        }
        if (rand() % 2 == 0) {
            put_pixel_line(sfTransparent, frame, i);
        }
        if (e >= 400)
            e = 400;
    }
    sfTexture_updateFromPixels(frame->texture, frame->pixels,
    1920, 1080, 0, 0);
}
