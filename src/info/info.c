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

static const ressource_t RES[] = {
    {"res/texture/intro.png", {0, 0, 0, 0}, {0, 0}, {0, 0}},
    {"res/texture/menu.png", {0, 0, 0, 0}, {0, 0}, {0, 0}},
    {"res/texture/player_move.png", {0, 0, 0, 0}, {0, 0}, {0, 0}},
    {"res/texture/HUD.png", {0, 0, 0, 0}, {0, 0}, {0, 0}},
    {"res/texture/menu_button.png", {0, 0, 0, 0}, {0, 0}, {0, 0}},
    {"res/texture/save.png", {0, 0, 0, 0}, {0, 0}, {0, 0}},
    {"res/texture/npc.png", {0, 0, 0, 0}, {0, 0}, {0, 0}},
    {"res/texture/text.png", {0, 0, 0, 0}, {0, 0}, {0, 0}},
    {"res/texture/link_house.png", {0, 0, 0, 0}, {0, 0}, {0, 0}},
    {"res/texture/enemy.png", {0, 0, 0, 0}, {0, 0}, {0, 0}},
    {"res/texture/house.png", {0, 0, 0, 0}, {0, 0}, {0, 0}},
    {"res/texture/item.png", {0, 0, 0, 0}, {0, 0}, {0, 0}},
    {"res/texture/status.png", {0, 0, 0, 0}, {0, 0}, {0, 0}},
    {"res/texture/map_tx.png", {0, 0, 0, 0}, {0, 0}, {0, 0}},
    {"res/texture/option.png", {0, 0, 0, 0}, {0, 0}, {0, 0}},
    {"res/texture/button_volume.png", {0, 0, 0, 0}, {0, 0}, {0, 0}},
    {"res/texture/over_map.png", {0, 0, 0, 0}, {0, 0}, {0, 0}},
    {"res/texture/game_over.png", {0, 0, 0, 0}, {0, 0}, {0, 0}},
    {"res/texture/use_move.png", {0, 0, 0, 0}, {0, 0}, {0, 0}},
    {"res/texture/Interaction.png", {0, 0, 0, 0}, {0, 0}, {0, 0}},
    {"res/texture/inventory.png", {0, 0, 0, 0}, {0, 0}, {0, 0}},
    {"res/texture/attack.png", {0, 0, 0, 0}, {0, 0}, {0, 0}},
};

static sfTexture **init_texture(void)
{
    int nb = 22;
    sfTexture **texture = malloc(sizeof(sfTexture *) * (nb + 1));

    if (!texture)
        return (NULL);
    texture[nb] = NULL;
    for (int i = 0; i < nb; i++) {
        texture[i] = sfTexture_createFromFile(RES[i].name, NULL);
        if (!texture[i])
            return (NULL);
    }
    return (texture);
}

sfView **init_view(void)
{
    sfView **view = malloc(sizeof(sfView *) * 8);

    if (!view)
        return (NULL);
    for (int i = 0; i < 7; i++) {
        view[i] = sfView_create();
        if (!view[i])
            return (NULL);
        sfView_setCenter(view[i], (VF){640, 360});
        sfView_setSize(view[i], (VF){1280, 720});
    }
    return (view);
}

int init_info(info_t *info)
{
    info->pclock = sfClock_create();
    info->texture = init_texture();
    info->font = malloc(sizeof(sfFont *) * 2);

    info->view = init_view();
    if (!info->pclock || !info->texture || !info->font || !info->view)
        return (ERROR);
    info->font[0] = sfFont_createFromFile("res/font/font.otf");
    info->font[1] = sfFont_createFromFile("res/font/font3.otf");
    if (!info->font[0] || !info->font[1])
        return (ERROR);
    for (int i = 0; i < 3; i++) {
        info->save[i] = 0;
        for (int j = 0; j < 7; j++)
            info->saved_stat[i][j] = 0;
    }
    for (int i = 0; i < 4; i++) {
        info->clock_c[i] = 1;
        info->scene[i] = i == 0 ? INTRO: i == 1 ? LINK_HOUSE: i == 2 ? 1: 0;
    }
    return (SUCCESS);
}

void destroy_info(info_t *info)
{
    sfClock_destroy(info->pclock);
    sfRenderWindow_destroy(info->win);
    for (int i = 0; info->texture[i]; i++)
        sfTexture_destroy(info->texture[i]);
    sfFont_destroy(info->font[0]);
    sfFont_destroy(info->font[1]);
    for (int i = 0; i < 7; i++)
        sfView_destroy(info->view[i]);
    free(info->view);
    free(info->font);
    free(info->texture);
}
