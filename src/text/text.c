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

speech_t *init_text(sfTexture *texture)
{
    speech_t *speech = malloc(sizeof(speech_t));
    char **text = malloc(sizeof(char *) * (3 + 1));
    int *skip = malloc(sizeof(int) * (3 + 1));
    char *str[] = {"res/text/gf_speech.txt", "res/text/gf_die_speech.txt",
                    "res/text/gf_die_quest.txt"};

    if (!speech || !text || !skip)
        return (NULL);
    text[3] = NULL;
    for (int i = 0; i < 3; i++) {
        text[i] = get_str(str[i]);
        if (!text[i])
            return (NULL);
        skip[i] = 0;
    }
    if (init_sprite(&speech->rec, texture, (IR){0, 0, 222, 51},
        (float[2]){2, 2}))
        return (NULL);
    speech->rec.statistic[0] = 0;
    speech->text = text;
    return (speech->skip = skip, speech);
}

char *display_each_char(char *str)
{
    static char *prev = NULL;
    static char *text = NULL;
    char *tmp;
    char each[2] = {str[my_strlen(prev)], '\0'};

    if (!str)
        return (NULL);
    if (!text)
        text = str;
    if (my_strcmp(str, text) != 0) {
        free(prev);
        prev = NULL;
        text = str;
    }
    each[0] = str[my_strlen(prev)];
    tmp = prev;
    prev = my_strcat(each, prev);
    my_free(tmp);
    return (prev);
}

void display_speech(sprite_t *rec, char *str, info_t *info, VF pos)
{
    sfText *text = NULL;

    draw_sprite(rec->sprite, pos, rec->rec, info->win);
    text = create_text(str, 25, info->font[0]);
    if (!text)
        return;
    draw_text(text, (VF){pos.x + 15, pos.y + 10}, info->win);
    sfText_destroy(text);
}

void destroy_text(speech_t *speech)
{
    sfSprite_destroy(speech->rec.sprite);
    free_tab(speech->text);
    my_free(speech->skip);
    my_free(speech);
}
