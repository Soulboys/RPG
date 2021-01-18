/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>

/**static const**/

typedef struct option_menu_s {
    sfText **text;
    sfSprite **sprite;
    int status;
} option_menu_t;

typedef struct pixel_s {
    sfVertexArray *array;
    long long int life;
    sfVector2f emmitter;
    sfVertexArray *save;
} pixel_t;

typedef struct option_s {
    option_menu_t *menu;
    int *value;
    sfMusic **music;
} option_t;

typedef struct ressource_s {
    char *name;
    sfIntRect rec;
    sfVector2f pos;
    float size[2];
} ressource_t;

typedef struct key_move_s {
    sfKeyCode key;
    int x;
    int y;
    int sp;
} key_move_t;

typedef struct scene_s {
    int scene;
    void (*function)();
} scene_t;

/**reusable struct**/
typedef struct sprite_s {
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rec;
    short statistic[5];
    float map_pos[2];
    sfVector2f pos_base;
    struct sprite_s *next;
} sprite_t;

typedef struct text_s {
    char *name;
    sfText *text;
    sfVector2f pos;
    sfColor color;
    unsigned short int size;
} text_t;

/**normal struct **/
typedef struct info_s {
    sfRenderWindow *win;
    sfTexture **texture;
    sfFont **font;
    sfClock *pclock;
    sfView **view;
    long long int clock_c[7];
    int saved_stat[3][18];
    short num_of_scene;
    short save[3];
    short scene[4];
} info_t;

typedef struct menu_s {
    sprite_t **rec;
    text_t **player_name;
    text_t **title;
    text_t **alpha;
    text_t **supp;
    char *name;
    short del_mode[2];
} menu_t;

typedef struct player_s {
    sprite_t player_sp;
    sprite_t **heart;
    sprite_t *hud;
} player_t;

typedef struct npc_s {
    sprite_t c;
} npc_t;

typedef struct house_s {
    sfSprite *sprite;
    char **map;
    sprite_t sp;
    sfVector2f *spawn;
    int(*spawn_coord)[2];
} house_t;

typedef struct enemy_s {
    sprite_t **mobs;
    int killed;
} enemy_t;

typedef struct speech_s {
    sprite_t rec;
    char **text;
    int *skip;
    char *save;
} speech_t;

typedef struct item_s {
    sprite_t chest;
    sprite_t *item;
    sprite_t *inventory;
    sfVector2f chest_pos[1];
    int open[1];
    int select;
    int possesses[4][2];
    pixel_t *vertex;
} item_t;

typedef struct end_s {
    sfRectangleShape *rec;
    sfSprite *game_over;
    sfText *text;
} end_t;

typedef struct help_s {
    sprite_t *action;
    sfText **text;
} help_t;

typedef struct rpg_s {
    pixel_t fog;
    option_t *opt;
    char *player_name;
    sprite_t intro;
    text_t intro_text;
    sprite_t **pause;
    help_t *help;
    enemy_t *enemy;
    player_t *player;
    npc_t **npc;
    house_t **house;
    menu_t *menu;
    speech_t *speech;
    item_t *item;
    end_t *end;
} rpg_t;


/*
OPTION
[0] = ambiant volume
[1] = sound volume
[2] = fps
*/
