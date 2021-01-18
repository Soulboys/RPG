/*
** EPITECH PROJECT, 2019
** MUL_my_rpg_2018
** File description:
** __DESCRIPTION__
*/

#include <stdlib.h>
#include "lib.h"
#include "define.h"
#include "prototype.h"

void move_enemy(rpg_t *rpg, int attribut[2], int i)
{
    VF posmobs = sfSprite_getPosition(rpg->enemy->mobs[i]->sprite);
    VF posplayer = sfSprite_getPosition(rpg->player->player_sp.sprite);

    if (posmobs.x < posplayer.x - attribut[0])
        move_mobs(MOBS(i), attribut[1], 54, (int[3]){36, 0, 18});
    else if (posmobs.y < posplayer.y - attribut[0])
        move_mobs(MOBS(i), attribut[1], 18, (int[3]){0, 1, 18});
    else {
        if (posmobs.y > posplayer.y + attribut[0])
            move_mobs(MOBS(i), -attribut[1], 126, (int[3]){108, 1, 18});
        else if (posmobs.x > posplayer.x + attribut[0])
            move_mobs(MOBS(i), -attribut[1], 90, (int[3]){72, 0, 18});
    }
}

static int check_enemy_move(sprite_t *mob, char **map, int j)
{
    int x = j == 0 || j == 3 ? j == 0 ? -1 : 1 : 0;
    int y = j == 1 || j == 2 ? j == 1 ? -1 : 1 : 0;

    if ((int)mob->map_pos[0] + y * 2 < 0
        || (int)mob->map_pos[0] + y * 2 > tab_size(map)
        || (int)mob->map_pos[1] + x * 2 < 0
        || (int)mob->map_pos[1] + x * 2 > my_strlen(map[0]))
        return (0);
    if (map[(int)mob->map_pos[0] + y * 2][(int)mob->map_pos[1] + x * 2] == ' ')
        return (1);
    return (0);
}

static const int max[4] = {18, 54, 90, 126};
static const float speed[4] = {2, 2, -2, -2};
static const int debut[4] = {0, 36, 72, 108};
static const int orientation[4] = {1, 0, 0, 1};

static void randomly_move_enemy(sprite_t *mob, char **map)
{
    int j;
    static int x = 0;

    mob->statistic[2] = mob->statistic[2] == 75 ? 0: mob->statistic[2];
    if (!mob->statistic[2])
        mob->statistic[3] = rand() % 4;
    j = mob->statistic[3];
    mob->statistic[2]++;
    x++;
    if (check_enemy_move(mob, map, j))
        move_mobs(mob, speed[j], max[j], (int[3]){debut[j],
            orientation[j], 18});
    else {
        mob->statistic[2] = 0;
        if (x < 10)
            return (randomly_move_enemy(mob, map));
    }
    x = 0;
}

int enemy(rpg_t *rpg, int i, int scene)
{
    if (!pythagor(PLAYER->player_sp.sprite, rpg->enemy->mobs[i]->sprite, 200))
        move_enemy(rpg, (int[2]){20, 5}, i);
    else
        randomly_move_enemy(rpg->enemy->mobs[i], rpg->house[scene]->map);
    return (0);
}
