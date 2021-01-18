/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include <stdlib.h>
#include "prototype.h"
#include "define.h"
#include "lib.h"

void disp_inventory(item_t *item, info_t *info, VF pos)
{
    sprite_t *inv = item->inventory;

    if (inv[0].pos.y > 0 && info->scene[3]) {
        inv[0].pos.y -= 10;
        inv[1].pos.y -= 10;
        for (int i = 0; i < 4; i++)
            item->item[i].pos.y -= 10;
    } else if (inv[0].pos.y < 720 && !info->scene[3]) {
        inv[0].pos.y += 10;
        inv[1].pos.y += 10;
        for (int i = 0; i < 4; i++)
            item->item[i].pos.y += 10;
    }
    sfSprite_setOrigin(inv[0].sprite, (VF){128, 112});
    sfSprite_setOrigin(inv[1].sprite, (VF){16, 16});
    draw_sprite(inv[0].sprite, (VF){pos.x, pos.y + inv[0].pos.y},
        inv[0].rec, WIN);
    draw_sprite(inv[1].sprite, (VF){pos.x - 445 + inv[1].pos.x,
        pos.y + inv[1].pos.y - 228.64}, inv[1].rec, WIN);
}

void disp_item(item_t *item, info_t *info, VF pos)
{
    sfVector2f npos;
    sfText *text = NULL;
    char *str = NULL;

    for (int i = 0; i < 4; free(str), i++) {
        npos = (VF){item->item[i].rec.width / 2, item->item[i].rec.height / 2};
        str = int_to_str(item->possesses[i][0]);
        text = create_text(str, 30, info->font[0]);
        if (!text)
            continue;
        sfSprite_setOrigin(item->item[i].sprite, npos);
        sfSprite_setScale(item->item[i].sprite, (VF){5, 3.21});
        draw_sprite(item->item[i].sprite, (VF){pos.x - 440 + i * 160,
            pos.y + item->item[i].pos.y - 228.64}, item->item[i].rec, WIN);
        draw_text(text, (VF){pos.x - 420 + i * 160,
            pos.y + item->item[i].pos.y - 228}, WIN);
        sfText_destroy(text);
    }
}

int disp_item_select(rpg_t *rpg, info_t *info)
{
    if (rpg->item->select != -1) {
        draw_sprite(rpg->item->item[rpg->item->select].sprite,
            (VF){PLAYER->player_sp.pos.x - 565, PLAYER->player_sp.pos.y - 300},
            rpg->item->item[rpg->item->select].rec, WIN);
    }
    return (SUCCESS);
}
