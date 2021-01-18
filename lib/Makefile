##
# EPITECH PROJECT, 2018
# makefile
# File description:
# make things
##

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
NAME	=	libmy.a
SRC		=	number.c	\
			put.c	\
			str_to_array.c	\
			str_utils.c	\
			utils_csfml.c	\
			my_printf.c	\
			my_perror.c	\
			tab_lib.c	\
			math.c

OBJ	=	$(SRC:.c=.o)

%.o:	%.c
	@gcc $(CFLAGS) -o $@ -c $<

#Rules
all: $(NAME)

$(NAME):	$(OBJ)
	@ar	rc	$(NAME) $(OBJ)
	@ranlib $(NAME)
	@make --no-print-directory clean
	@cp lib.h ../include

clean:
	@rm -rf $(OBJ)

fclean:	clean
		@rm -rf $(NAME)

re:	fclean	all
