/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include <stdlib.h>
#include "lib.h"
#include "define.h"
#include "prototype.h"

void disp_life(player_t *player, info_t *info)
{
    int nb = player->player_sp.statistic[2];
    int max = player->player_sp.statistic[3];
    int value = 0;
    int x = 0;
    int y = -1;

    for (int j = 0; j < max / 2; j++) {
        value = nb - 2 >= 0 ? 0: (nb - 2) % 2 == 0 ? 2: 1;
        x = (j % 3 == 0) ? 0: x + 1;
        y += (j % 3 == 0) ? 1: 0;
        draw_sprite(player->heart[value]->sprite,
            (VF){player->player_sp.pos.x + 370 + x * 50,
            player->player_sp.pos.y - 320 + y * 30},
            player->heart[value]->rec, info->win);
        nb -= nb - 2 >= 0 || (nb - 2) % 2 == 0 ? 2: 1;
    }
}

void move_player(sprite_t *player, int move, int pos[2])
{
    if (player->statistic[0] != FIGHT && player->statistic[0] != FIGHT_L) {
        player->rec.left += 17 * move;
        if (player->rec.left > 120 || player->rec.left < 0)
            player->rec.left = player->statistic[0] == LEFT ? 120: 0;
        player->pos.x += pos[1] * 8;
        player->pos.y += pos[0] * 10.5;
    }
}

void disp_player(sprite_t *player, info_t *info)
{
    int nb = player->statistic[0] == FIGHT_L ? -1: 1;
    int rec = player->statistic[0] == LEFT ? 120 : 0;
    VF pos = player->pos;

    if (player->statistic[0] != FIGHT && player->statistic[0] != FIGHT_L) {
        if (player->statistic[0] != player->statistic[1])
            player->rec.left = player->statistic[0] == LEFT ? 120: 0;
        player->statistic[1] = player->statistic[0];
        player->rec.top = player->statistic[0] * 23;
    } else {
        if (!get_time(info->pclock, &info->clock_c[1], 100000))
            player->rec.left += 30 * nb;
        if ((player->rec.left > 120 && player->statistic[0] == FIGHT)
            || (player->rec.left < 0 && player->statistic[0] == FIGHT_L)) {
            player->statistic[0] = player->statistic[0] == FIGHT_L ? LEFT:RIGHT;
            player->rec = (IR){rec, player->statistic[0] * 23, 16, 21};
        }
    }
    draw_sprite(player->sprite, pos, player->rec, info->win);
}
