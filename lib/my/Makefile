##
## Makefile for emacs in /home/detroy_j/delivery/CPool_Day10/lib/my
## 
## Made by jean-baptiste detroyes
## Login   <detroy_j@epitech.net>
## 
## Started on  Fri Oct 14 07:47:24 2016 jean-baptiste detroyes
## Last update Mon Jan 16 11:23:36 2017 detroy_j
##

SRCS	=	my_putchar.c	\
		my_isneg.c	\
		my_put_nbr.c	\
		my_swap.c	\
		my_putstr.c	\
		my_strlen.c	\
		my_getnbr.c	\
		my_sort_int_tab.c	\
		my_power_rec.c	\
		my_square_root.c	\
		my_is_prime.c	\
		my_find_prime_sup.c	\
		my_strcpy.c	\
		my_strncpy.c	\
		my_revstr.c	\
		my_strstr.c	\
		my_strcmp.c	\
		my_strupcase.c	\
		my_strlowcase.c	\
		my_strcapitalize.c	\
		my_str_isalpha.c	\
		my_str_isnum.c	\
		my_str_islower.c	\
		my_str_isupper.c	\
		my_str_isprintable.c	\
		my_showstr.c		\
		my_showmem.c		\
		my_strcat.c		\
		my_strncat.c		\
		my_strsep.c		\
		my_strdup.c		\
		get_next_line.c	\
##		my_printf.c	\
		prints.c	\
		parser.c	\
		pointer.c	\
##		misc.c

OBJ	=	$(SRCS:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

auteur:
	echo $(USER) > auteur

$(NAME):	$(OBJ)
	gcc -c $(SRCS)	\
	&& ar rc $(NAME) $(OBJ)	\
	&& cp $(NAME) ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
