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

static const key_move_t MOVE[4] = {
    {sfKeyDown, 0, 1, DOWN}, {sfKeyRight, 1, 0, RIGHT},
    {sfKeyLeft, -1, 0, LEFT}, {sfKeyUp, 0, -1, UP},
};

void change_somewhere(info_t *info, rpg_t *rpg)
{
    int pos[1][5][2] = {{
        {238, 170}, {238, 171}, {238, 172}, {238, 173}, {238, 174}}};
    int save = SCENE(1);

    for (int j = 0; j < 1; j++)
        for (int i = 0; i < 5; i++) {
            SCENE(1) = (PLAYER->player_sp.map_pos[0]) == (float)pos[j][i][0]
            && (float)(PLAYER->player_sp.map_pos[1]) == pos[j][i][1]
            ? j + 1: SCENE(1);
        }
    SCENE(1) = save > 0 ? 0: SCENE(1);
    PLAYER->player_sp.map_pos[0] =
        (float)rpg->house[SCENE(1)]->spawn_coord[save][0];
    PLAYER->player_sp.map_pos[1] =
        (float)rpg->house[SCENE(1)]->spawn_coord[save][1];
    sfView_move(info->view[3], (VF){rpg->house[SCENE(1)]->spawn[save].x
        - PLAYER->player_sp.pos.x, rpg->house[SCENE(1)]->spawn[save].y
        - PLAYER->player_sp.pos.y});
    PLAYER->player_sp.pos.x = rpg->house[SCENE(1)]->spawn[save].x;
    PLAYER->player_sp.pos.y = rpg->house[SCENE(1)]->spawn[save].y;
}

static int check_player_can_move(sprite_t *player, house_t *house, int pos[2])
{
    short npos[2] = {player->map_pos[0] + pos[0], player->map_pos[1] + pos[1]};

    if (house->map[npos[0]][npos[1]] == ' '
        || house->map[npos[0]][npos[1]] == 'A'
        || house->map[npos[0]][npos[1]] == 'D') {
        player->map_pos[0] += pos[0];
        player->map_pos[1] += pos[1];
        return (1);
    }
    return (0);
}

void move_event(sfEvent event, rpg_t *rpg, info_t *info)
{
    int i = 0;

    for (; i < 4 && event.key.code != MOVE[i].key; i++);
    if (i == 4 || (SCENE(2) != NONE && SCENE(2) < GF_DIE_EQUIPED) || SCENE(3)
        || get_time(CLOCK, &C_COUNTER(1), 30000))
        return;
    if (i < 4)
        STAT(0) = MOVE[i].sp;
    if (rpg->house[SCENE(1)]->map[(int)PLAYER->player_sp.map_pos[0]]
        [(int)PLAYER->player_sp.map_pos[1]] == 'D') {
        change_somewhere(info, rpg);
    } else if (check_player_can_move(&PLAYER->player_sp, rpg->house[SCENE(1)],
        (int[2]){MOVE[i].y, MOVE[i].x}) && STAT(0) != FIGHT
        && STAT(0) != FIGHT_L) {
        move_player(&PLAYER->player_sp, STAT(0) == LEFT ? -1: 1,
            (int[2]){MOVE[i].y, MOVE[i].x});
        sfView_move(info->view[3], (VF){MOVE[i].x * 8, MOVE[i].y * 10.5});
    }
}

static void fight_event(sfEvent event, rpg_t *rpg, info_t *info)
{
    if (SCENE(2) > GF_DIE_EQUIPED && event.key.code == sfKeySpace
        && event.type == sfEvtKeyReleased) {
        STAT(0) = STAT(1) == LEFT ? FIGHT_L: FIGHT;
        PLAYER->player_sp.rec = STAT(0) == FIGHT || STAT(0) == FIGHT_L ?
        (IR){STAT(0) == FIGHT_L ? 120: 0, STAT(1) == RIGHT ? 95: 125, 30, 30}
        :PLAYER->player_sp.rec;
    }
    for (int i = 0; i < ENEMY_MAX; i++)
        if (event.key.code == sfKeySpace && event.type == sfEvtKeyReleased
            && info->scene[2] >= GF_DIE_UNEQUIPED
            && pythagor(PLAYER->player_sp.sprite,
            rpg->enemy->mobs[i]->sprite, 50) == SUCCESS)
            rpg->enemy->mobs[i]->statistic[0] -= 1;
    if (STAT(0) == FIGHT || STAT(0) == FIGHT_L) {
        sfMusic_stop(rpg->opt->music[2]);
        sfMusic_setVolume(rpg->opt->music[2], (float)(rpg->opt->value[1]));
        sfMusic_play(rpg->opt->music[2]);
    }
}

int game_event(sfEvent event, rpg_t *rpg, info_t *info)
{
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyEscape
        && (SCENE(0) == GAME || SCENE(0) == PAUSE))
        info->scene[0] = info->scene[0] == PAUSE ? GAME: PAUSE;
    if (info->scene[0] != GAME || SCENE(2) == END ||
        inventory_event(event, rpg, info))
        return (SUCCESS);
    move_event(event, rpg, info);
    if (STAT(0) != FIGHT_L && STAT(0) != FIGHT)
        fight_event(event, rpg, info);
    if (info->scene[1] == LINK_HOUSE)
        link_house_event(event, info, rpg);
    else
        none_house_event(event, info, rpg);
    return (SUCCESS);
}
