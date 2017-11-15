##
## Makefile for make in /rendu/rendu_Systeme_Unix/PSU_2015_my_ls
##
## Made by munoz david
## Login   <munoz_d@epitech.net>
##
## Started on  Thu Nov 26 22:59:46 2015 munoz david
## Last update Sat Mar 19 17:35:55 2016 loic durand
##

NAME	= tetris

OBJ	= $(addprefix src/, $(SRC:.c=.o))

SRC	= main.c					\
	  list_tetriminos.c				\
	  check_tetrimino.c				\
	  basic_check_function.c			\
	  interface/interface.c				\
	  interface/interface_print_tetris_game.c	\
	  interface/interface_print_tetris.c		\
	  interface/interface_print_next.c		\
	  interface/interface_print_info.c		\
	  interface/interface_collision.c		\
	  interface/interface_keys.c			\
	  interface/end_of_game.c			\
	  interface/save_tab.c				\
	  interface/colors.c				\
	  interface/random.c				\
	  options/options_management.c			\
	  options/mvmt_options.c			\
	  options/tab_options.c				\
	  options/debug_mod.c				\
	  options/debug_tetrimino.c			\
	  options/hub_option.c				\
	  options/key_recuperation.c			\
	  options/help.c				\
	  options/level_option.c			\
	  options/map_size_option.c			\
	  error/errors.c                                \
	  error/error_spe.c				\
	  error/free.c

TMP	= $(SRC:.c=.c~)

CC	= gcc

RM 	= rm -f

CFLAGS	= -W -Wall -ansi -pedantic -lncurses -I./include/ -I/home/${USER}/.froot/include

CFLAGS	+= -L./lib/my/ -lmy

DIR	= lib/my

$(NAME): $(OBJ)
	cd $(DIR) && $(MAKE)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)
	@echo "\033[1;32m[Tetris] : Program compilated\n\033[0m"

all: $(NAME)

clean:
	$(RM) $(OBJ) $(TMP)
	cd $(DIR) && $(MAKE) clean
	@echo "\033[1;31m[Tetris] : Binary files deleted\n\033[0m"

fclean:
	$(RM) $(OBJ) $(TMP) $(NAME)
	cd $(DIR) && $(MAKE) clean
	@echo "\033[1;31m[Tetris] : Binary and executable files are deleted\n\033[0m"

re: lib fclean all

.PHONY: all clean fclean re lib
