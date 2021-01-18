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

void disp_name(char *name, sfRenderWindow *win, sfFont *font)
{
    static sfText *text = NULL;

    if (!name)
        return;
    if (text)
        sfText_destroy(text);
    text = create_text(name, 60, font);
    draw_text(text, (VF){220, 280}, win);
}

void disp_create(info_t *info, rpg_t *rpg)
{
    menu_t *menu = rpg->menu;
    sfVector2i m = sfMouse_getPositionRenderWindow(info->win);
    sfText *text;

    draw_sprite_t(menu->rec[0], info->win);
    for (int i = 0; menu->alpha[i]; i++) {
        text = resize_a_text(menu->alpha[i]->text, m, 50, 60);
        draw_text(text, menu->alpha[i]->pos, info->win);
    }
    for (int i = 0; i < 2; i++) {
        text = resize_a_text(menu->supp[i]->text, m, 70, 80);
        draw_text(text, menu->supp[i]->pos, info->win);
    }
    draw_text(menu->title[0]->text, menu->title[0]->pos, info->win);
    disp_name(menu->name, info->win, info->font[0]);
}

void disp_player_menu(player_t *player, info_t *info, int i)
{
    int nb = info->saved_stat[i][8];
    int max = info->saved_stat[i][9];
    int value = 0;

    if (sfClock_getElapsedTime(info->pclock).microseconds > 100000) {
        player->player_sp.rec.top = 0;
        player->player_sp.rec.left += 17;
        player->player_sp.rec.left =
        player->player_sp.rec.left > 124 ? 0: player->player_sp.rec.left;
        sfClock_restart(info->pclock);
    }
    draw_sprite(player->player_sp.sprite, (VF){225, 200 + i * 100},
    player->player_sp.rec, info->win);
    for (int j = 0; j < max / 2; j++) {
        value = nb - 2 >= 0 ? 0: (nb - 2) % 2 == 0 ? 2: 1;
        draw_sprite(player->heart[value]->sprite,
            (VF){700 + j * 65, 220 + i * 100},
            player->heart[value]->rec, info->win);
        nb -= nb - 2 >= 0 || (nb - 2) % 2 == 0 ? 2: 1;
    }
}

void display_rec(sprite_t **rec, sfRenderWindow *win, sfVector2i m)
{
    draw_sprite_t(rec[1], win);
    if (m.y >= 400 && m.y <= 500)
        rec[2]->pos.y = 410;
    else if (m.y >= 300 && m.y < 400)
        rec[2]->pos.y = 310;
    else
        rec[2]->pos.y = 210;
    draw_sprite_t(rec[2], win);
}

void disp_select(info_t *info, rpg_t *rpg)
{
    sfVector2i m = sfMouse_getPositionRenderWindow(info->win);
    sfText *text = NULL;
    display_rec(MENU->rec, info->win, m);
    draw_text(MENU->title[1]->text, MENU->title[1]->pos, info->win);
    for (int i = 0; i < 3; i++) {
        if (!MENU->player_name[i])
            continue;
        draw_text(MENU->player_name[i]->text, MENU->player_name[i]->pos, WIN);
        disp_player_menu(rpg->player, info, i);
    }
    for (int i = 2; MENU->supp[i]; i++) {
        text = MENU->supp[i]->text;
        text = i > 4 ? resize_a_text(text, m, 80, 90): text;
        if (i == 5 && MENU->del_mode[0])
            sfText_setCharacterSize(text, 90);
        draw_text(text, MENU->supp[i]->pos, info->win);
    }
    if (MENU->del_mode[1])
        display_speech(&SPEECH->rec, L_TAB "Warning ! You have to delete\n"
        L_TAB "\t\tthe file manualy !\n", info, (VF){400, 300});
}
