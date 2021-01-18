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

int click_create(rpg_t *rpg, info_t *i, sfVector2i m, char *tmp)
{
    char new[2] = {'a', 0};

    if (text_contain(i->win, MENU->supp[0]->text, m)) {
        i->scene[0] = SELECT;
        if (!(MENU->player_name = add_name(i, rpg, &MENU->name, 1)))
            return (ERROR);
    } else if (MENU->name && text_contain(i->win, MENU->supp[1]->text, m)) {
        if (my_strlen(MENU->name) - 1 == 0) {
            free(MENU->name);
            MENU->name = NULL;
        } else
            MENU->name[my_strlen(MENU->name) - 1] = '\0';
    }
    for (int j = 0; MENU->alpha[j]; j++)
        if (text_contain(i->win, MENU->alpha[j]->text, m)) {
            new[0] = j + 'a';
            tmp = MENU->name;
            MENU->name = my_strcat(new, MENU->name);
            my_free(tmp);
        }
    return (SUCCESS);
}

int load_game(sfVector2i m)
{
    if (m.y >= 400 && m.y <= 500)
        return (2);
    else if (m.y >= 300 && m.y < 400)
        return (1);
    else
        if (m.y < 300 && m.y >= 200)
            return (0);
    return (-1);
}

static int verif_height(rpg_t *rpg, info_t *i, sfVector2i m, int value)
{
    int j = 0;

    for (; MENU->player_name[j]; j++);
    value = load_game(m);
    if (value != -1 && value < j) {
        if (!MENU->del_mode[0] && i->saved_stat[value][1] != 7) {
            i->scene[0] = GAME;
            return (apply_save(i, rpg, value));
        } else if (!MENU->del_mode[1] && MENU->del_mode[0]) {
            sfText_destroy(MENU->player_name[value]->text);
            free(MENU->player_name[value]);
            MENU->player_name[value] = NULL;
            MENU->del_mode[0] = 0;
        }
    }
    MENU->del_mode[1] = 0;
    return (SUCCESS);
}

int click_select(rpg_t *rpg, info_t *i, sfVector2i m, int value)
{
    if (text_contain(i->win, MENU->supp[6]->text, m) && (!i->save[0]
        || !i->save[1] || !i->save[2])) {
        i->scene[0] = CREATE;
        MENU->del_mode[0] = 0;
    } else if (text_contain(i->win, MENU->supp[5]->text, m)) {
        MENU->del_mode[1] = !MENU->del_mode[0] ? 1: 0;
        MENU->del_mode[0] = !MENU->del_mode[0] ? 1: 0;
        return (SUCCESS);
    } else {
        if (text_contain(i->win, MENU->supp[8]->text, m))
            sfRenderWindow_close(i->win);
        else if (text_contain(i->win, MENU->supp[7]->text, m))
            i->scene[0] = HELP;
    }
    return (verif_height(rpg, i, m, value));
}

int click_pause(rpg_t *rpg, info_t *i, sfVector2i m)
{
    sfFloatRect rec = sfSprite_getGlobalBounds(STOP[0]->sprite);
    int j = 0;

    for (; STOP[j]; j++, rec = sfSprite_getGlobalBounds(STOP[j]->sprite))
        if (sfFloatRect_contains(&rec, m.x, m.y)) {
            STOP[j]->rec.left = j < 3 ? 30: 0;
            sfClock_restart(i->pclock);
            break;
        }
    if (j == 1)
        sfSprite_setScale(PLAYER->player_sp.sprite, (VF){5, 3});
    for (int z = 0; j == 1 && z < 3; z++)
        sfSprite_setScale(PLAYER->heart[z]->sprite, (VF){7.5, 4.8});
    if ((j == 1 || j == 3) && (write_save(rpg, rpg->player_name, i)
        || recup_save(i, rpg->player_name, i->num_of_scene) 
        || (j == 1 && reload(rpg, i))))
        return (ERROR);
    return (SUCCESS);
}
