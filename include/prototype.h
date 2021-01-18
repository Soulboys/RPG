/*
** EPITECH PROJECT, 2018
** my.h
** File description:
** my.h
*/

#include "struct.h"

int init_saves(info_t *, rpg_t *, char **);
sfRenderWindow *create_win(void);

/**INFO**/
int init_info(info_t *);
void destroy_info(info_t *);

/**SPRITE**/
int init_sprite(sprite_t *, sfTexture *, sfIntRect, const float[2]);
sprite_t **init_sprite_t(int, sfIntRect *, float(*scale)[2], sfTexture *);
void draw_sprite_t(sprite_t *, sfRenderWindow *);
void destroy_sprite(sprite_t *);
void free_sprite_t(sprite_t **);

/**LOOP**/
int loop(info_t *, rpg_t *);

/**SCENE**/
void disp_scene(info_t *, rpg_t *);

/**EVENT**/
int inventory_event(sfEvent, rpg_t *, info_t *);
int link_house_event(sfEvent, info_t *, rpg_t *);
int none_house_event(sfEvent, info_t *, rpg_t *);
int game_event(sfEvent, rpg_t *, info_t *);
int event_panel(info_t *, rpg_t *);

/**INTRO**/
int init_intro(sprite_t *, sfTexture *, text_t *, sfFont *);
void disp_intro(info_t *, rpg_t *);

/**MENU**/
menu_t *init_menu(sfTexture *, sfFont *);
void disp_create(info_t *, rpg_t *);
void disp_select(info_t *, rpg_t *);
void destroy_menu(menu_t *);

/**CLICK**/
int click_create(rpg_t *, info_t *, sfVector2i, char *);
int click_select(rpg_t *, info_t *, sfVector2i, int);
int click_pause(rpg_t *, info_t *, sfVector2i);

/**GAME**/
void disp_game(info_t *, rpg_t *);
void disp_player(sprite_t *, info_t *);

/**PLAYER**/
player_t *init_player_struct(sfTexture **);
void move_player(sprite_t *, int, int[2]);
void destroy_player(player_t *);
void disp_life(player_t *, info_t *);

/**PAUSE**/
sprite_t **init_pause(sfTexture **);
void disp_pause(info_t *, rpg_t *);

/**SAVES**/
char *read_save(char *);
int apply_save(info_t *, rpg_t *, int);
int recup_save(info_t *, char *, int);
char **read_dir(char ***, char *, int);
int write_save(rpg_t *, char *, info_t *);
text_t **add_name(info_t *, rpg_t *, char **, int);
int reload(rpg_t *, info_t *);
int decrypt_save(char **, info_t *, int);

/**NPC**/
npc_t **init_npc(sfTexture **);
void disp_npc(npc_t **, info_t *);
void destroy_npc(npc_t **);

/**HOUSE**/
house_t **init_house(sfTexture **);
void disp_house(house_t *, sfRenderWindow *);
void disp_link_house(rpg_t *, info_t *, int);
void disp_none_house(rpg_t *, info_t *, int);
void destroy_house(house_t **);
void destroy_option(option_t *);

/**HELP**/
help_t *init_help(sfTexture **, sfFont *);
void display_help(info_t *, rpg_t *);
void destroy_help(help_t *);

/**ENEMY**/
enemy_t *init_enemy(sfTexture *);
int move_mobs(sprite_t *, float, int, int[3]);
void randomly_move(sprite_t *);
void move_enemy(rpg_t *, int[2], int);
int enemy(rpg_t *, int, int);
void destroy_enemy(enemy_t *);

/**ITEM**/
item_t *init_item(sfTexture **);
void disp_inventory(item_t *, info_t *, sfVector2f);
void disp_item(item_t *, info_t *, sfVector2f);
int disp_item_select(rpg_t *, info_t *);
void destroy_item(item_t *);

/**TEXT**/
speech_t *init_text(sfTexture *);
char *display_each_char(char *);
void display_speech(sprite_t *, char *, info_t *, sfVector2f);
void destroy_text(speech_t *);

/**UTILS**/
void my_free(void *);
int restart_clock(info_t *, int);
void free_text_t(text_t **);
int text_contain(sfRenderWindow *, sfText *, sfVector2i);
int get_time(sfClock *, long long int *, int);
sfText *resize_a_text(sfText *, sfVector2i, int, int);
int pythagor(sfSprite *, sfSprite *, int);

char *get_str(char *);
char **get_map(char *);

/**PARTICULE**/
pixel_t *create_particule(rpg_t *);
void update_vertex(sfVertexArray *, sfVector2f, float);
void update_fog(pixel_t);
sfVertexArray *create_vertex_array(sfVector2f, sfColor, sfPrimitiveType, int);

/**END**/
end_t *init_end(sfTexture *, sfFont *);
void display_end(end_t *, info_t *, sprite_t);
void destroy_end(end_t *);

/**OPTION**/
option_t *init_option(void);
option_menu_t *init_option_menu(info_t *info, sfTexture **);
void display_opt_menu(info_t *info, rpg_t *rpg);
