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

int recup_save(info_t *info, char *new, int nb)
{
    char *str = my_strcat(new, "res/save/");
    char *tmp = str;
    char **tab = NULL;

    if (!str)
        return (ERROR);
    str = my_strcat(".save", str);
    free(tmp);
    if (!str)
        return (ERROR);
    tmp = read_save(str);
    free(str);
    if (!tmp)
        return (ERROR);
    tab = str_to_array(tmp, '\n');
    if (!tab)
        return (ERROR);
    my_free(tmp);
    decrypt_save(tab, info, nb);
    return (free_tab(tab), SUCCESS);
}

static int find_slot(text_t **name, char *str)
{
    int nb = 0;

    if (!str)
        return (-1);
    for (const char *new = NULL; name && name[nb]; nb++) {
        new = sfText_getString(name[nb]->text);
        if (!my_strcmp(new, str))
            break;
    }
    return (nb);
}

text_t **add_name(info_t *info, rpg_t *rpg, char **str, int write)
{
    text_t **name = rpg->menu->player_name;
    int nb = find_slot(name, *str);

    if (nb == 3 || nb == -1 || !(*str))
        return (name);
    name[nb] = malloc(sizeof(text_t));
    if (!name[nb])
        return (NULL);
    name[nb]->text = create_text(*str, 80, info->font[0]);
    if (!name[nb]->text)
        return (NULL);
    name[nb]->pos = (VF){400, nb * 100 + 190};
    info->save[nb] = 1;
    if (write) {
        write_save(rpg, *str, info);
        if (recup_save(info, *str, nb))
            return (NULL);
        free(*str);
        *str = NULL;
    }
    return (name);
}
