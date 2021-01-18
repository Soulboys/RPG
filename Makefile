#Colors
REDDARK	=	\033[31;2m
RED		=	\033[31;1m
GREEN	=	\033[32;1m
YEL		=	\033[33;1m
BLUE	=	\033[34;1m
PINK	=	\033[35;1m
CYAN	=	\033[36;1m
RES		=	\033[0m

#Makefile
NAME 		= 	my_rpg
CC			=	gcc
SRC_DIR 	= 	src
SRC_FILES	=	/event/event_panel.c /event/click.c	/event/game_event.c 	\
				/event/inventory_event.c /event/somewhere_event.c	\
				/info/info.c /info/window.c	\
				/intro/intro.c	\
				/menu/menu.c /menu/init_menu.c /menu/destroy_menu.c	\
				/player/player.c /player/destroy_player.c /player/init_player.c	\
				/save/write_save.c /save/read_save.c /save/decrypt_save.c /save/apply_save.c	\
				/save/reload.c	\
				/save/add_name.c	\
				/loop.c /main.c /scene_manager.c /sprite.c	\
				/game.c /npc/npc.c /house/house.c /house/disp_house.c	\
				/enemy/enemy_move.c /enemy/init_enemy.c /enemy/destroy_enemy.c	\
				/utils/utils.c /utils/pythagor.c /utils/clock.c	/utils/get_map.c	\
				/move_mobs.c	\
				/text/text.c	\
				/house/destroy_house.c	\
				/item/item.c /item/destroy_item.c /item/disp_item.c	\
				/pause/pause.c	\
				/option/option.c /option/destroy_option.c	\
				/particle/create_vertex.c	\
				/help/help.c	\
				/end.c

SRC			= 	$(addprefix $(SRC_DIR), $(SRC_FILES))
BUILD		=	$(SRC:.c=.o)
CFLAGS		= 	-Wall -Wextra -I include/ -g
CSFMLFLAGS  =	-lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system
LFLAGS		= 	-L./lib -lmy -lm

## RULES
all:	library $(NAME)

library:
		@make --no-print-directory -sC ./lib

%.o:	%.c
	@gcc $(CFLAGS) -o $@ -c $<

$(NAME):	$(BUILD)
			@echo -e " [$(RED)BINARY FILES$(RES)]        $(GREEN)DONE$(RES)"
			@$(CC) $(BUILD) $(CFLAGS) -o $(NAME) $(LFLAGS) $(CSFMLFLAGS)
			@echo -e " [$(RED)GCC BINARY$(RES)]          $(GREEN)DONE$(RES)"

clean:
		@find -name '*.gc*' -delete -or -name 'vgcore.*' -delete -o -name '*.o' -delete
		@make --no-print-directory clean -C ./lib

fclean:		clean
			@rm -rf $(NAME)
			@make --no-print-directory fclean -C ./lib
			@echo -e " [$(RED)FCLEAN$(RES)]              $(GREEN)DONE$(RES)"

re:		fclean all

.PHONY: all library clean fclean re
