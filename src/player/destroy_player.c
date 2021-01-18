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

void destroy_player(player_t *player)
{
    sfSprite_destroy(player->hud[0].sprite);
    sfSprite_destroy(player->hud[1].sprite);
    my_free(player->hud);
    sfSprite_destroy(player->player_sp.sprite);
    free_sprite_t(player->heart);
    my_free(player);
}
