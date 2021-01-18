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

void disp_hud(info_t *info, player_t *player)
{
    draw_sprite(player->hud[0].sprite, (VF){player->player_sp.pos.x - 630,
        player->player_sp.pos.y - 400}, (IR){36, 0, 28, 50}, WIN);
    draw_sprite(player->hud[1].sprite, (VF){player->player_sp.pos.x + 320,
        player->player_sp.pos.y - 400}, (IR){175, 0, 50, 23}, WIN);
    disp_life(player, info);
}

void disp_game_second(info_t *info, rpg_t *rpg)
{
    if (SCENE(1) == NONE)
        draw_sprite(rpg->house[0]->sprite, (VF){0, 0},
        rpg->house[0]->sp.rec, WIN);
    disp_item_select(rpg, info);
    disp_hud(info, PLAYER);
    disp_inventory(ITEM, info, PLAYER->player_sp.pos);
    disp_item(ITEM, info, PLAYER->player_sp.pos);
}

void enemy_management(info_t *info, rpg_t *rpg)
{
    int ti = get_time(info->pclock, &info->clock_c[0], 80000);
    int hit = get_time(info->pclock, &info->clock_c[4], 1000000);

    for (int i = 0;!info->scene[1] && i < ENEMY_MAX; i++) {
        if (!ti)
            enemy(rpg, i, SCENE(1));
        if (rpg->enemy->mobs[i]->statistic[0] > 0)
            draw_sprite_t(rpg->enemy->mobs[i], WIN);
        rpg->enemy->killed += rpg->enemy->mobs[i]->statistic[0] > 0 ? 0: 1;
        if (!pythagor(PLAYER->player_sp.sprite,
            rpg->enemy->mobs[i]->sprite, 30) && !hit
            && rpg->enemy->mobs[i]->statistic[0] > 0)
            PLAYER->player_sp.statistic[2] -= 0.5;
    }
}

void disp_game(info_t *info, rpg_t *rpg)
{
    int ti = get_time(info->pclock, &info->clock_c[2], 100000);

    if (!PLAYER->player_sp.statistic[2])
        SCENE(2) = END;
    disp_house(rpg->house[SCENE(1)], WIN);
    disp_npc(rpg->npc, info);
    rpg->enemy->killed = 0;
    enemy_management(info, rpg);
    if (info->scene[1] == LINK_HOUSE)
        disp_link_house(rpg, info, ti);
    else if (SCENE(1) == NONE)
        disp_none_house(rpg, info, ti);
    disp_player(&PLAYER->player_sp, info);
    disp_game_second(info, rpg);
    display_end(rpg->end, info, PLAYER->player_sp);
}
