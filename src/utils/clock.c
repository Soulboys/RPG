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

int restart_clock(info_t *i, int nb)
{
    if (sfClock_getElapsedTime(i->pclock).microseconds > nb) {
        sfClock_restart(i->pclock);
        for (int j = 0; j < 7; j++)
            i->clock_c[j] = 0;
        return (SUCCESS);
    }
    return (ERROR);
}

int get_time(sfClock *clock, long long int *counter, int time)
{
    long long int elapsed = sfClock_getElapsedTime(clock).microseconds;

    if (elapsed - *counter > time) {
        (*counter) = elapsed;
        return (SUCCESS);
    }
    return (FAIL);
}
