/*
** EPITECH PROJECT, 2022
** volume_events
** File description:
** volume_events
*/

#include "settings_screen.h"

void set_volume_icon(settings *setting, sfVector2f set_pos_sprite)
{
    if (set_pos_sprite.x >= 1070 && set_pos_sprite.x <= 1167 &&
    set_pos_sprite.y >= 355 && set_pos_sprite.y <= 430) {
        set_pos_sprite.x = 1200;
        set_pos_sprite.y = sfSprite_getPosition(
            setting->vlm.sprite[1].sprite).y;
        sfSprite_setColor(setting->vlm.sprite[2].sprite, sfTransparent);
        sfSprite_setColor(setting->vlm.sprite[3].sprite, sfWhite);
        sfSprite_setPosition(
            setting->vlm.sprite[1].sprite, set_pos_sprite);
    }
    if (sfSprite_getPosition(setting->vlm.sprite[1].sprite).x != 1200) {
        sfSprite_setColor(setting->vlm.sprite[3].sprite, sfTransparent);
        sfSprite_setColor(setting->vlm.sprite[2].sprite, sfWhite);
    }
}

void check_volume_box(settings *setting, sfVector2f set_pos_sprite)
{
    if (set_pos_sprite.x >= 1200 && set_pos_sprite.x <= 1760 &&
    set_pos_sprite.y >= 350 && set_pos_sprite.y <= 430) {
        set_pos_sprite.x -= 40;
        set_pos_sprite.y = sfSprite_getPosition(
            setting->vlm.sprite[1].sprite).y;
        sfSprite_setPosition(
            setting->vlm.sprite[1].sprite, set_pos_sprite);
    }
    set_volume_icon(setting, set_pos_sprite);
}

void check_volume_slidebar(screens *screen, settings *setting)
{
    sfVector2f set_pos_sprite = set_pos_mouse_f(screen);

    set_pos_sprite.x -= 40;
    set_pos_sprite.y =
    sfSprite_getPosition(setting->vlm.sprite[1].sprite).y;
    if (setting->vlm.vlm_is_click == true) {
        if (set_pos_sprite.x >= 1200)
            sfSprite_setPosition(
            setting->vlm.sprite[1].sprite, set_pos_sprite);
        if (set_pos_sprite.x < 1200) {
            set_pos_sprite.x = 1200;
            sfSprite_setPosition(
            setting->vlm.sprite[1].sprite, set_pos_sprite);
        }
        if (set_pos_sprite.x > 1680) {
            set_pos_sprite.x = 1680;
            sfSprite_setPosition(
            setting->vlm.sprite[1].sprite, set_pos_sprite);
        }
    }
}

void change_volume(sfMusic *music, settings *setting)
{
    float set_pos_vlm =
        sfSprite_getPosition(setting->vlm.sprite[1].sprite).x;

    set_pos_vlm = (set_pos_vlm - 1200) / 4.8;
    sfMusic_setVolume(music, set_pos_vlm);
}

void volume_events(screens *screen, settings *setting)
{
    if (screen->event.type == sfEvtMouseButtonPressed &&
    screen->event.mouseButton.button == sfMouseLeft) {
        if (mouse_clicked_button(screen, setting->vlm.sprite[1].sprite,
        setting->vlm.size_btn) == true)
            setting->vlm.vlm_is_click = true;
        check_volume_box(setting, set_pos_mouse_f(screen));
    }
    if (screen->event.type == sfEvtMouseButtonReleased) {
        setting->vlm.vlm_is_click = false;
    }
    check_volume_slidebar(screen, setting);
    change_volume(screen->music[0], setting);
}
