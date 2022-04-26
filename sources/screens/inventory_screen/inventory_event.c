/*
** EPITECH PROJECT, 2022
** Check_error
** File description:
** to complete
*/

#include "inventory.h"

sfVector2f set_pos_mouse(screens *screen)
{
    sfVector2i pos_mouse = sfMouse_getPositionRenderWindow(screen->window);
    sfVector2f pos_mousef;

    pos_mousef.x = pos_mouse.x;
    pos_mousef.y = pos_mouse.y;
    return (pos_mousef);
}

void mouse_on_rect(screens *screen, sfVector2f pos, sfRectangleShape *rect)
{
    sfVector2f pos_mouse = set_pos_mouse(screen);
    sfVector2f size = sfRectangleShape_getSize(rect);

    if (pos_mouse.x > pos.x && pos_mouse.x < pos.x + size.x &&
        pos_mouse.y > pos.y && pos_mouse.y < pos.y + size.y) {
        sfRectangleShape_setFillColor(rect,
            sfColor_fromRGBA(254,80,24,175));
            // sfColor_fromRGBA(139,127,114,175));
    } else {
        sfRectangleShape_setFillColor(rect,
            sfColor_fromRGBA(0,0,0,0));
    }
}

void change_rect(screens *screen, inventory *stock)
{
    for (int i = 0; i < 26; i++) {
        if (i < 20) {
            mouse_on_rect(screen, stock->spot[i].pos, stock->spot[i].rect);
        } else {
            mouse_on_rect(screen, stock->equipment[i - 20].pos,
                stock->equipment[i - 20].rect);
        }
    }
}

bool event_inventory(screens *screen, inventory *stock)
{
    if (screen->event.type == sfEvtClosed) {
        return (true);
    }
    change_rect(screen, stock);
    return (false);
}
