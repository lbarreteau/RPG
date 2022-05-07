/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "settings_screen.h"

void free_volume(settings *setting)
{
    for (int i = 0; i < 4; i++) {
        sfTexture_destroy(setting->vlm.sprite[i].texture);
        sfSprite_destroy(setting->vlm.sprite[i].sprite);
        free(setting->asset_btn[i]);
    }
}

void free_fps(settings *setting)
{
    for (int i = 0; i < 3; i++) {
        sfTexture_destroy(setting->fps.sprite[i].texture);
        sfSprite_destroy(setting->fps.sprite[i].sprite);
        free(setting->asset_btn[i + 4]);
    }
}

void free_controls(settings *setting)
{
    for (int i = 0; i < 10; i++) {
        sfTexture_destroy(setting->controls.sprite[i].texture);
        sfSprite_destroy(setting->controls.sprite[i].sprite);
    }
    for (int i = 0; i < 5; i++) {
        sfText_destroy(setting->controls.text[i].text);
        sfFont_destroy(setting->controls.text[i].font);
    }
    free(setting->asset_btn[7]);
    free(setting->asset_btn[8]);
    free(setting->asset_btn[9]);
}

void free_settings(settings *setting)
{
    free_volume(setting);
    free_fps(setting);
    free_controls(setting);
    for (int i = 0; i < 6; i++) {
        sfRectangleShape_destroy(setting->color_text.rect[i]);
    }
    sfSprite_destroy(setting->exit.sprite);
    sfTexture_destroy(setting->exit.texture);
    sfSprite_destroy(setting->background);
    sfTexture_destroy(setting->background_texture);
    free(setting->asset_btn[10]);
}
