/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "settings_screen.h"

extern const char *keycode[];

void set_volume_settings(screens *screen, settings *setting)
{
    float music_vol = sfMusic_getVolume(screen->music[0]);

    setting->vlm.sprite[0] = init_sprite(setting->asset_btn[0],
        (sfVector2f) {1, 1}, (sfVector2f) {1200, 350});
    setting->vlm.sprite[1] = init_sprite(setting->asset_btn[1],
        (sfVector2f) {1, 1}, (sfVector2f) {1200 + 480 * music_vol / 100, 350});
    setting->vlm.sprite[2] = init_sprite(setting->asset_btn[2],
        (sfVector2f) {0.75, 0.75}, (sfVector2f) {1070, 355});
    setting->vlm.sprite[3] = init_sprite(setting->asset_btn[3],
        (sfVector2f) {0.75, 0.75}, (sfVector2f) {1070, 355});
    setting->vlm.size_btn = (sfVector2f) {80, 80};
    setting->vlm.pos_btn_vlm = (sfVector2f) {1200, 350};
    sfSprite_setColor(setting->vlm.sprite[3].sprite,
        sfTransparent);
    setting->vlm.vlm_is_click = true;
}

void set_fps_settings(settings *setting, unsigned short fps_nb)
{
    setting->fps.rect.height = 118;
    setting->fps.rect.width = 118;
    setting->fps.rect.top = 0;
    setting->fps.rect.left = 0;
    for (int i = 0; i < 3; i++) {
        setting->fps.sprite[i] = init_sprite(setting->asset_btn[i + 4],
            (sfVector2f) {1, 1}, (sfVector2f) {1200 + i * 200, 555});
        if (i == (fps_nb / 30 - 1))
            setting->fps.rect.left += 118;
        sfSprite_setTextureRect(setting->fps.sprite[i].sprite,
            setting->fps.rect);
        setting->fps.rect.left = 0;
    }
}

void set_controls_settings(screens *screen, settings *setting)
{
    for (int i = 0; i < 5; i++) {
        setting->controls.text[i].font =
        sfFont_createFromFile(setting->asset_btn[7]);
        setting->controls.text[i].text = sfText_create();
        sfText_setFont(setting->controls.text[i].text,
            setting->controls.text->font);
        sfText_setPosition(setting->controls.text[i].text,
            (sfVector2f){540 - my_strlen(keycode[screen->list_key[i]])
            * 20 / 2, 490 + i * 100});
        sfText_setCharacterSize(setting->controls.text[i].text, 20);
        sfText_setString(setting->controls.text[i].text,
            keycode[screen->list_key[i]]);
        setting->controls.sprite[i * 2] = init_sprite(setting->asset_btn[8],
            (sfVector2f) {1, 1}, (sfVector2f) {650, 450 + i * 100});
        setting->controls.sprite[i * 2 + 1] = init_sprite(setting->asset_btn[9],
            (sfVector2f) {1, 1}, (sfVector2f) {650, 450 + i * 100});
        setting->controls.wait_key[i] = false;
    }
}

void set_color_text(settings *setting)
{
    setting->color_text.color[0] = sfWhite;
    setting->color_text.color[1] = sfBlack;
    setting->color_text.color[2] = sfRed;
    setting->color_text.color[3] = sfBlue;
    setting->color_text.color[4] = sfGreen;
    setting->color_text.color[5] = sfYellow;
    for (int i = 0; i < 6; i++) {
        setting->color_text.rect[i] = sfRectangleShape_create();
        sfRectangleShape_setFillColor(setting->color_text.rect[i],
            setting->color_text.color[i]);
        sfRectangleShape_setPosition(setting->color_text.rect[i],
            (sfVector2f){1200 + i * 100, 850});
        sfRectangleShape_setSize(setting->color_text.rect[i],
            (sfVector2f){80, 80});
        sfRectangleShape_setOutlineColor(setting->color_text.rect[i], sfBlack);
        sfRectangleShape_setOutlineThickness(setting->color_text.rect[i], 3);
    }
    sfRectangleShape_setSize(setting->color_text.rect[5], (sfVector2f){30, 30});
    sfRectangleShape_setPosition(setting->color_text.rect[5],
        (sfVector2f){1225 , 875});
}

void set_settings(screens *screen, settings *setting)
{
    setting->exit.texture =
        sfTexture_createFromFile(setting->asset_btn[1], NULL);
    setting->exit.sprite = sfSprite_create();
    sfSprite_setPosition(setting->exit.sprite, (sfVector2f){125, 125});
    sfSprite_setTexture(setting->exit.sprite, setting->exit.texture, sfFalse);
    setting->background_texture =
        sfTexture_createFromFile(setting->asset_btn[10], NULL);
    setting->background = sfSprite_create();
    sfSprite_setPosition(setting->background, (sfVector2f){0, 0});
    sfSprite_setTexture(setting->background,
        setting->background_texture, sfFalse);
    set_volume_settings(screen, setting);
    set_fps_settings(setting, screen->fps);
    set_controls_settings(screen, setting);
    set_color_text(setting);
}
