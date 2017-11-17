##
## Makefile for emacs in /home/detroy_j/delivery/CPool_Day10/lib/my
## 
## Made by jean-baptiste detroyes
## Login   <detroy_j@epitech.net>
## 
## Started on  Fri Oct 14 07:47:24 2016 jean-baptiste detroyes
## Last update Sun Jan 22 17:46:12 2017 detroy_j
##

SRCS	=	srcs/main.c	\
		srcs/my_getenv.c	\
		srcs/misc.c	\
		srcs/list.c	\
		srcs/list2.c	\
		srcs/my_cmd_cd.c	\
		srcs/my_cmd_env.c	\
		srcs/my_fork.c	\
		srcs/my_exceve.c

FLAGS	=	-Llib -lmy

CFLAGS	+=	-g -Wextra -Wall -Werror -I include

OBJ	=	$(SRCS:.c=.o)

NAME	=	mysh

all:	$(NAME)

auteur:
	echo $(USER) > auteur

$(NAME):	$(OBJ)
	gcc $(OBJ) -o $(NAME) $(FLAGS) 

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
