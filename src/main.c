/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "prototype.h"
#include "define.h"
#include "lib.h"

static void init_other_struct(info_t *info, rpg_t *rpg)
{
    rpg->menu = init_menu(info->texture[1], info->font[0]);
    rpg->player_name = NULL;
    rpg->player = init_player_struct(info->texture);
    rpg->pause = init_pause(info->texture);
    rpg->npc = init_npc(info->texture);
    rpg->house = init_house(info->texture);
    rpg->enemy = init_enemy(info->texture[9]);
    rpg->speech = init_text(info->texture[7]);
    rpg->item = init_item(info->texture);
    rpg->opt = init_option();
    rpg->help = init_help(info->texture, info->font[0]);
    rpg->opt->menu = init_option_menu(info, info->texture);
    rpg->end = init_end(info->texture[17], info->font[0]);
    info->win = create_win();
}

static int init_struct(info_t *info, rpg_t *rpg)
{
    if (init_info(info) || init_intro(&rpg->intro,
        info->texture[0], &rpg->intro_text, info->font[0]))
        return (ERROR);
    init_other_struct(info, rpg);
    if (!rpg->menu || !rpg->pause || !rpg->house || !info->win || !rpg->item
    || init_saves(info, rpg, NULL) || !rpg->opt || !rpg->speech
        || !(rpg->fog.array = create_vertex_array((VF){345, 30},
        sfColor_fromRGB(36, 36, 36), sfPoints, 150)) || !rpg->end || !rpg->help)
        return (ERROR);
    return (rpg->fog.emmitter = (VF){345, 30}, SUCCESS);
}

static int init_random(void)
{
    int fd = open("/dev/urandom", O_RDONLY);
    unsigned seed;

    if (fd == -1)
        return (ERROR);
    read(fd, &seed, sizeof seed);
    srand(seed);
    close(fd);
    return (SUCCESS);
}

static void destroy_struct(info_t *info, rpg_t *rpg)
{
    destroy_sprite(&rpg->intro);
    sfText_destroy(rpg->intro_text.text);
    free_sprite_t(rpg->pause);
    destroy_player(rpg->player);
    destroy_menu(rpg->menu);
    destroy_item(rpg->item);
    destroy_house(rpg->house);
    destroy_enemy(rpg->enemy);
    destroy_option(rpg->opt);
    destroy_npc(rpg->npc);
    destroy_text(rpg->speech);
    destroy_end(rpg->end);
    destroy_help(rpg->help);
    my_free(rpg->player_name);
    destroy_info(info);
    sfVertexArray_destroy(rpg->fog.array);
}

int main(void)
{
    info_t info;
    rpg_t rpg;
    int value = 0;

    if (init_random() || init_struct(&info, &rpg))
        return (ERROR);
    value = loop(&info, &rpg);
    destroy_struct(&info, &rpg);
    return (value == 84 ? 84: 0);
}
