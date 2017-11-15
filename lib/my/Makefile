##
## Makefile for c in /PSU_2015_tetris/lib/my
## 
## Made by David Munoz
## Login   <munoz_d@epitech.net>
## 
## Started on  Tue Mar  1 18:42:18 2016 David Munoz
## Last update Wed Mar 16 11:33:43 2016 David Munoz
##

NAME=	libmy.a

OBJ=	$(SRC:.c=.o)

SRC=	my_str_isprintable.c \
	my_find_prime_sup.c \
	my_strcapitalize.c \
	my_sort_int_tab.c \
	my_str_islower.c \
	my_str_isalpha.c \
	my_square_root.c \
	my_str_isupper.c \
        fonction_flag2.c \
	get_next_line.c \
	my_strlowcase.c \
        fonction_flag.c \
	my_power_rec.c \
	my_str_isnum.c \
	my_strupcase.c \
	my_is_prime.c \
	my_put_nbr.c \
	my_strlcat.c \
	my_putchar.c \
	my_strncat.c \
	my_strncmp.c \
	my_showmem.c \
	my_strncpy.c \
	my_showstr.c \
        my_printf.c \
	my_strcat.c \
	my_strlen.c \
	my_putstr.c \
	my_strcpy.c \
	my_revstr.c \
	my_getnbr.c \
	my_strstr.c \
	my_strcmp.c \
	my_isneg.c \
	my_swap.c \
        flag3.c \
        flag2.c \
        flag.c

CC	= gcc

RM	= rm -f

CFLAGS  = -W -Wall -Werror -ansi -pedantic

$(NAME): $(OBJ)
	$(CC) -c $(SRC) $(CFLAGS)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)
	cp $(NAME) ../
	cp my.h ../../include
	@echo "\033[1;36m[lib/my] : Library compilated \n\033[0m"

all:	$(NAME)

clean:
	$(RM) $(OBJ)
	@echo "\033[1;31m[lib/my] : Binary files deleted\n\033[0m"

fclean: clean
	$(RM) $(NAME)
	@echo "\033[1;31m[lib/my] : Binary and executable files are deleted\n\033[0m"

re: fclean all

.PHONY: all clean fclean re
