##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

CC	=	gcc
SRC	=	archi.c	\
		translation_matrix.c	\
		check_arg.c	\
		scaling_matrix.c	\
		rotation_matrix.c	\
		reflection_matrix.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	102architect

all:	$(NAME)


$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -lm

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean	all

auteur:
	echo $(USER) > auteur
