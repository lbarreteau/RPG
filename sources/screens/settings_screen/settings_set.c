/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "settings_screen.h"

void set_settings(settings *setting)
{
    setting->vlm_setting.sprite_vlm[0] = init_sprite(
        setting->asset_btn_vlm[0], (sfVector2f) {1, 1},
            (sfVector2f) {1200, 350});
    setting->vlm_setting.sprite_vlm[1] = init_sprite(
        setting->asset_btn_vlm[1], (sfVector2f) {1, 1},
            (sfVector2f) {1200, 350});
    setting->vlm_setting.sprite_vlm[2] = init_sprite(
        setting->asset_btn_vlm[2], (sfVector2f) {0.75, 0.75},
            (sfVector2f) {1070, 355});
    setting->vlm_setting.pos_btn_vlm = (sfVector2f) {1200, 350};
    setting->vlm_setting.sprite_vlm[3] = init_sprite(
        setting->asset_btn_vlm[3], (sfVector2f) {0.75, 0.75},
            (sfVector2f) {1070, 355});
    setting->vlm_setting.size_btn = (sfVector2f) {80, 80};
    sfSprite_setColor(setting->vlm_setting.sprite_vlm[2].sprite,
        sfTransparent);
    setting->vlm_setting.vlm_is_click = false;
}
