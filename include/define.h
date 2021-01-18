/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#ifndef DEFINE_H
    #define DEFINE_H
    #define ERROR 84
    #define SUCCESS 0
    #define FAIL 1
    #define ENEMY_MAX 5
    #define VF sfVector2f
    #define IR sfIntRect
    #define P_POS PLAYER->player_sp.pos
    #define ITEM rpg->item
    #define REC ITEM->inventory[1]
    #define SPEECH rpg->speech
    #define WIN info->win
    #define MENU rpg->menu
    #define L_TAB "\t\t\t\t"
    #define CLOCK info->pclock
    #define OPT rpg->opt
    #define STOP rpg->pause
    #define PLAYER rpg->player
    #define STAT(x) rpg->player->player_sp.statistic[x]
    #define MOBS(x) rpg->enemy->mobs[x]
    #define C_COUNTER(x) info->clock_c[x]
    #define SCENE(x) info->scene[x]

    enum somewhere {
        NONE,
        LINK_HOUSE,
        HYURULE_CASTLE,
    };
    enum event {
        GF_SPEECH = 1,
        GF_MOVE,
        GF_DIE_EQUIPED,
        GF_DIE_SPEECH,
        GF_DIE_QUEST,
        GF_DIE_UNEQUIPED,
        END,
        BUY,
    };
    enum scene {
        INTRO,
        CREATE,
        SELECT,
        GAME,
        PAUSE,
        OPTION,
        HELP,
    };
    enum help_event {
        MOVEMENT = 1,
        INTERACTION,
        INVENTORY,
        ATTACK,
    };
    enum movement {
        DOWN,
        RIGHT,
        LEFT,
        UP,
        FIGHT,
        FIGHT_L,
    };
#endif /* DEFINE_H */
