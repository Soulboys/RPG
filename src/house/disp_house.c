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

int disp_item_tempory(sprite_t *item, int time, info_t *info, int other)
{
    int nb = get_time(info->pclock, &info->clock_c[3], time);

    if (nb == FAIL && !other) {
        sfSprite_setScale(item->sprite, (VF){2, 2});
        draw_sprite_t(item, WIN);
        return (0);
    }
    return (1);
}

static void disp_link_open(item_t *item, info_t *info)
{
    int nb = get_time(info->pclock, &info->clock_c[5], 1000000);
    static int i = 0;

    if (nb == FAIL)
        i++;
    draw_sprite(item->chest.sprite, item->chest_pos[0],
        (IR){136, 53, 16, 16}, WIN);
    if (!item->possesses[0][0]) {
        item->item[0].pos = (VF){item->chest_pos[0].x + 20,
        item->chest_pos[0].y -20};
        for (int j = 0; j < 2; j++) {
            update_vertex(item->vertex[j].array, item->item[0].pos, !j ?
                i: i / 1.5);
            sfRenderWindow_drawVertexArray(WIN, item->vertex[j].array, NULL);
        }
        item->possesses[0][0] = disp_item_tempory(&item->item[0],
        1000000, info, item->possesses[0][0]);
        item->item[0].pos.y = 720;
    } else
        i = 0;
}

void disp_link_house(rpg_t *rpg, info_t *info, int ti)
{
    static char *str = NULL;
    sprite_t sp = rpg->npc[0]->c;
    sprite_t rec = SPEECH->rec;

    if (!ti)
        str = SPEECH->skip[0] ? SPEECH->text[0]:
            display_each_char(SPEECH->text[0]);
    if (!my_strcmp(str, SPEECH->text[0]))
        SPEECH->rec.statistic[0] = 1;
    if (!ti) {
        if (info->scene[2] == GF_MOVE)
            move_mobs(&rpg->npc[0]->c, 4, 393, (int[3]){369, 1, 24});
        update_fog(rpg->fog);
    }
    sfRenderWindow_drawVertexArray(info->win, rpg->fog.array, NULL);
    if (info->scene[2] == GF_SPEECH) {
        display_speech(&SPEECH->rec, str, info,
            (VF){sp.pos.x + 15, sp.pos.y - 60 - rec.rec.height});
    }
    if (ITEM->open[0] == 1)
        disp_link_open(ITEM, info);
}

void disp_none_house(rpg_t *rpg, info_t *info, int ti)
{
    static char *str = NULL;
    sprite_t sp = rpg->npc[0]->c;
    sprite_t rec = SPEECH->rec;
    int nb = SCENE(2) == GF_DIE_SPEECH ? 1: 2;

    if (!ti)
        str = SPEECH->skip[nb] ? SPEECH->text[nb]:
            display_each_char(SPEECH->text[nb]);
    if (!my_strcmp(str, SPEECH->text[nb]) && SCENE(2) == GF_DIE_SPEECH)
        SCENE(2) = GF_DIE_QUEST;
    if (SCENE(2) == GF_DIE_SPEECH || SCENE(2) == GF_DIE_QUEST)
        display_speech(&SPEECH->rec, str, info,
            (VF){sp.pos.x + 15, sp.pos.y - 60 - rec.rec.height});
    if (SCENE(2) == GF_DIE_UNEQUIPED && rpg->enemy->killed >= 5
        && !ITEM->possesses[3][0]) {
        info->clock_c[3] = 1000000;
        ITEM->item[3].pos = PLAYER->player_sp.pos;
        ITEM->possesses[3][0] = disp_item_tempory(&ITEM->item[3],
            1000000, info, ITEM->possesses[3][0]);
        ITEM->item[3].pos.y = 720;
    }
}
