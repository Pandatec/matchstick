##
## EPITECH PROJECT, 2019
## Makefile
## File description:
## Makefile
##

SRC	=	src/main.c			\
		src/my_bot.c			\
		src/my_engine.c			\
		src/my_error.c			\
		src/my_get.c			\
		src/my_map.c			\
		src/my_put.c			\
		src/my_utils.c			\
		src/get_next_line.c

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Werror -Wextra -I include -lm

NAME	=	matchstick

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ) $(CFLAGS)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re
