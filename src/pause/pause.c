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

sprite_t **init_pause(sfTexture **texture)
{
    sprite_t **pause = malloc(sizeof(sprite_t) * 5);
    IR rec[4] = {{0, 0, 30, 20}, {0, 60, 30, 20}, {0, 40, 30, 20},
        {0, 0, 48, 48}};
    VF pos[4] = {{525, 50}, {540, 250}, {540, 450}, {10, 600}};

    if (!pause)
        return (NULL);
    pause[4] = NULL;
    for (int i = 0; i < 4; i++) {
        pause[i] = malloc(sizeof(sprite_t));
        if (!pause[i] || init_sprite(pause[i], texture[i == 3 ? 5: 4], rec[i],
            i == 3 ? (float[2]){2, 2}: (float[2]){7, 7}))
            return (NULL);
        pause[i]->pos = pos[i];
    }
    return (pause);
}

void disp_pause(info_t *info, rpg_t *rpg)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(info->win);
    sfFloatRect rec;
    int restart = restart_clock(info, 500000);
    short scene[4] = {GAME, SELECT, OPTION, -1};

    for (int i = 0; i < 4; i++) {
        rec = sfSprite_getGlobalBounds(rpg->pause[i]->sprite);
        rpg->pause[i]->rec.left = sfFloatRect_contains(&rec, m.x, m.y)
            && i < 3 ? rpg->pause[i]->rec.left != 30 ? 60: 30: 0;
        if (!restart && i < 3 && rpg->pause[i]->rec.left == 30)
            info->scene[0] = scene[i];
        if (i == 3 && sfFloatRect_contains(&rec, m.x, m.y))
            sfSprite_setScale(rpg->pause[i]->sprite, (VF){2.5, 2.5});
        else if (i == 3)
            sfSprite_setScale(rpg->pause[i]->sprite, (VF){2, 2});
        draw_sprite_t(rpg->pause[i], info->win);
    }
}
