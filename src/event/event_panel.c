/*
** EPITECH PROJECT, 2018
** PROJECT
** File description:
** File
*/

#include "prototype.h"
#include "define.h"
#include "lib.h"

static int main_event(sfEvent event, sfRenderWindow *win, info_t *info)
{
    if (event.type == sfEvtClosed || sfKeyboard_isKeyPressed(sfKeyQ))
        sfRenderWindow_close(win);
    if (sfKeyboard_isKeyPressed(sfKeyEnter) && info->scene[0] == INTRO)
        info->scene[0] =
        !info->save[0] && !info->save[1] && !info->save[2] ? CREATE: SELECT;
    return (SUCCESS);
}

static int menu_event(sfEvent event, rpg_t *rpg, info_t *info)
{
    sfVector2i mouse;
    int value = 0;

    if (info->scene[0] != CREATE && info->scene[0] != SELECT)
        return (SUCCESS);
    mouse = sfMouse_getPositionRenderWindow(info->win);
    if (event.type == sfEvtMouseButtonReleased
        && event.mouseButton.button == sfMouseLeft) {
        value = info->scene[0] == CREATE ?
            click_create(rpg, info, mouse, NULL): click_select(rpg, info,
                mouse, 0);
        sfClock_restart(info->pclock);
        return (value);
    }
    return (SUCCESS);
}

static int pause_event(sfEvent event, rpg_t *rpg, info_t *info)
{
    sfVector2i m;

    if (info->scene[0] != PAUSE)
        return (SUCCESS);
    m = sfMouse_getPositionRenderWindow(info->win);
    if (event.type == sfEvtMouseButtonReleased
        && event.mouseButton.button == sfMouseLeft)
        click_pause(rpg, info, m);
    return (SUCCESS);
}

static int help_event(sfEvent event, info_t *info, rpg_t *rpg)
{
    if (SCENE(0) != HELP)
        return (0);
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeyEnter) {
        SCENE(1) == ATTACK ? SCENE(0) = SELECT : SCENE(1)++;
        if (SCENE(0) == SELECT)
            SCENE(1) = 1;
        for (int i = 0; SCENE(0) != SELECT && i < 4; i++)
            sfSprite_setScale(rpg->help->action[i].sprite, (VF){0, 0});
    }
    return (0);
}

int event_panel(info_t *info, rpg_t *rpg)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(info->win, &event)) {
        game_event(event, rpg, info);
        if (main_event(event, info->win, info))
            return (ERROR);
        if (SCENE(2) && event.type == sfEvtKeyReleased
            && event.key.code == sfKeyEnter) {
            SCENE(0) = SELECT;
            SCENE(2) = 1;
        } else if (SCENE(2) != BUY && SCENE(2) != END
            && (menu_event(event, rpg, info) || pause_event(event, rpg, info)
            || help_event(event, info, rpg)))
            return (ERROR);
    }
    return (SUCCESS);
}
