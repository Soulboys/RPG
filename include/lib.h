/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#include <SFML/Graphics.h>
#include <stdarg.h>

#ifndef LIB_H
    #define LIB_H

typedef struct print_s {
    char type;
    int (*function)();
}print_t;

/**number.c**/
int my_getnbr(char const *);
char *int_to_str(int);
int get_int_size(int);

/**put.c**/
int my_putchar(char);
void my_putstr(char const *);
void my_put_nbr(long long);
char *my_strlowcase(char *);

/**str_to_array.c**/
char **str_to_array(char *, char);

/**str_utils.c**/
char *my_strcpy(char *, char const *);
int my_strlen(char const *);
char *my_revstr(char *);
char *my_strcat(char *, char *);
int my_strcmp(char const *, char const *);

/**math.c**/
int my_pow(int, int);
int my_sqrt(int);

/**my_printf.c**/
int my_printf(char *, ...);
int count_putchar(va_list to_print);
int count_putstr(va_list to_print);
int count_putnbr(va_list to_print);

int my_perror(char *, ...);
int count_putchar_err(va_list to_print);
int count_putstr_err(va_list to_print);
int count_putnbr_err(va_list to_print);

/***cfsml_utils.c***/
sfSprite *create_sprite(sfTexture *, sfIntRect, const float[2]);
sfText *create_text(char *, int, sfFont *);
void draw_sprite(sfSprite *, sfVector2f, sfIntRect, sfRenderWindow *);
void draw_text(sfText *, sfVector2f, sfRenderWindow *);
sfFloatRect mouse_resize(sfRenderWindow *, sfFloatRect);

/**tab_lib**/
char **tab_copy(char **);
char **init_tab(int);
int tab_size(char **);
void free_tab(char **);

#endif
