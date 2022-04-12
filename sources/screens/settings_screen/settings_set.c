/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "settings_screen.h"

void set_volume_settings(settings *setting)
{
    setting->vlm.sprite[0] = init_sprite(setting->asset_btn[0],
        (sfVector2f) {1, 1}, (sfVector2f) {1200, 350});
    setting->vlm.sprite[1] = init_sprite(setting->asset_btn[1],
        (sfVector2f) {1, 1}, (sfVector2f) {1200, 350});
    setting->vlm.sprite[2] = init_sprite(setting->asset_btn[2],
        (sfVector2f) {0.75, 0.75}, (sfVector2f) {1070, 355});
    setting->vlm.sprite[3] = init_sprite(setting->asset_btn[3],
        (sfVector2f) {0.75, 0.75}, (sfVector2f) {1070, 355});
    setting->vlm.size_btn = (sfVector2f) {80, 80};
    setting->vlm.pos_btn_vlm = (sfVector2f) {1200, 350};
    sfSprite_setColor(setting->vlm.sprite[2].sprite,
        sfTransparent);
    setting->vlm.vlm_is_click = false;
}

void set_fps_settings(settings *setting)
{
    setting->fps.rect.height = 118;
    setting->fps.rect.width = 118;
    setting->fps.rect.top = 0;
    setting->fps.rect.left = 0;
    for (int i = 0; i < 3; i++) {
        setting->fps.sprite[i] = init_sprite(setting->asset_btn[i + 4],
            (sfVector2f) {1, 1}, (sfVector2f) {1200 + i * 200, 555});
        sfSprite_setTextureRect(setting->fps.sprite[i].sprite,
            setting->fps.rect);
    }
}

void set_settings(settings *setting)
{
    set_volume_settings(setting);
    set_fps_settings(setting);
}