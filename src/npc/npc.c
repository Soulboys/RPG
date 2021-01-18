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

npc_t **init_npc(sfTexture **texture)
{
    npc_t **npc = malloc(sizeof(npc_t *) * (1 + 1));
    IR rec[1] = {{321, 587, 20, 27}};

    if (!npc)
        return (NULL);
    npc[1] = NULL;
    for (int i = 0; i < 1; i++) {
        npc[i] = malloc(sizeof(npc_t));
        if (!npc[i])
            return (NULL);
        if (init_sprite(&npc[i]->c, texture[6], rec[i], (float[2]){2, 2}))
            return (NULL);
        npc[i]->c.pos = (VF){205, 80};
        npc[i]->c.statistic[0] = LEFT;
    }
    return (npc);
}

void disp_gf(sprite_t *c, info_t *info)
{
    if (c->pos.y > 280 && SCENE(2) < GF_DIE_EQUIPED) {
        SCENE(2) = GF_DIE_EQUIPED;
    } else if (SCENE(2) >= GF_DIE_EQUIPED && SCENE(2) < GF_DIE_UNEQUIPED) {
        c->pos.x = 1434;
        c->pos.y = 2780;
        c->rec.left = 547;
        c->rec.width = 28;
        c->rec.height = 31;
    } else
        if (SCENE(2) == GF_DIE_UNEQUIPED) {
            c->rec.left = 578;
            c->rec.width = 28;
        }
}

void disp_npc(npc_t **npc, info_t *info)
{
    for (int i = 0; npc[i]; i++) {
        disp_gf(&npc[i]->c, info);
        draw_sprite_t(&npc[i]->c, info->win);
    }
}

void destroy_npc(npc_t **npc)
{
    for (int i = 0; i < 1; i++) {
        sfSprite_destroy(npc[i]->c.sprite);
        my_free(npc[i]);
    }
    my_free(npc);
}
