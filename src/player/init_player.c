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

static int init_player(sprite_t *player, sfTexture *texture)
{
    if (init_sprite(player, texture, (IR){0, 0, 17, 23},
        (float[2]){5, 3}))
        return (ERROR);
    player->statistic[0] = DOWN;
    player->statistic[1] = 90;
    player->statistic[2] = 6;
    player->statistic[3] = 6;
    player->statistic[4] = 1;
    player->pos.x = 104;
    player->pos.y = 112;
    player->map_pos[0] = 8;
    player->map_pos[1] = 9;
    return (SUCCESS);
}

sprite_t *init_hud(sfTexture *texture)
{
    sprite_t *hud = malloc(sizeof(sprite_t) * 2);

    if (!hud || init_sprite(&hud[0], texture, (IR){175, 0, 23, 225},
        (float[2]){5, 3.21}) || init_sprite(&hud[1], texture,
        (IR){0, 0, 0, 0}, (float[2]){5, 3.21}))
        return (NULL);
    return (hud);
}

player_t *init_player_struct(sfTexture **texture)
{
    player_t *player = malloc(sizeof(player_t));

    if (!player)
        return (NULL);
    player->heart = malloc(sizeof(sprite_t *) * 4);
    if (!player->heart || init_player(&player->player_sp, texture[2]))
        return (NULL);
    player->heart[3] = NULL;
    for (int j = 0; j < 3; j++) {
        player->heart[j] = malloc(sizeof(sprite_t));
        if (!player->heart[j]
            || init_sprite(player->heart[j], texture[3],
            (IR){161 + 8 * j, 24, 7, 7}, (float[2]){5 *1.5, 3.21 * 1.5}))
            return (NULL);
    }
    player->hud = init_hud(texture[3]);
    return (player);
}
