/*
** my_tetris.h for a in /PSU_2015_tetris/include
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Mon Feb 22 14:05:05 2016 David Munoz
** Last update Tue Mar 22 13:51:21 2016 David Munoz
*/


#ifndef TETRIS_H_
# define TETRIS_H_

#define _BSD_SOURCE
#define _POSIX_SOURCE
#define _POSIX_C_SOURCE 199309L

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include <ncurses.h>
#include <dirent.h>
#include <fcntl.h>
#include <time.h>
#include <termios.h>
#include <stropts.h>
#include <sys/ioctl.h>
#include "my_struct.h"
#include "my_struct_interface.h"

# define RED                    "\033[1;31m"
# define GREEN                  "\033[1;32m"
# define PURPLE                 "\033[1;35m"
# define CYAN                   "\033[1;36m"
# define BROWN                  "\033[0;33m"
# define BLUE                   "\033[1;34m"
# define YELLOW                 "\033[1;33m"
# define BLANK                  "\033[0m"

/*
**_____________
**  INTERFACE
**_____________
*/

/*
** interface.c
*/
void    my_cadre();
int     check_end_of_game(t_pr *arg);
void    loop_game(t_pr *arg, t_struct *st, t_sco *sco);
void	init_struct_of_game(t_pr *arg, t_sco *sco, t_struct *st);
void    interface(t_struct *st);

/*
** interface_print_info.c
*/
void	print_score(t_sco *sco);
void    update_score(t_sco *sco);
void	print_info_IG(t_sco *sco);
void    start_info_tetris(t_sco *sco);

/*
** interface_print_tetris.c
*/
void    print_TE(t_pr *arg);
void    print_TR(t_pr *arg);
void    print_IS(t_pr *arg);
void	start_print_TETRIS(t_pr *arg);

/*
** interface_print_next.c
*/
int     check_open_read(char *file, t_pr *arg);
void	print_next_tetrimino(t_pr *arg, char *file);
void    next_tetriminos(t_pr *arg, t_struct *st, t_sco *sco);
void	tetrimino_reverse(t_pr *arg);
void    start_next(t_pr *arg);

/*
** interface_print_tetris_game.c
*/
void	stock_first_tetrimino(t_pr *arg, char *file);
void	top_tetrimino_to_bottom(t_pr *arg, t_struct *st, t_sco *sco);
void    print_top_tetrimino(t_pr *arg);
void    print_tetrimino_IG(t_pr *arg, t_struct *st, t_sco *sco);
void    start_interface_tetris(t_pr *arg);

/*
** interface_collision.c
*/
void	init_barre_detectrice(t_pr *arg);
char	*my_strcpy_tetris(char *dest, char *src);
void	barre_detectrice(t_pr *arg);
int	check_collision(t_pr *arg, int x_d, int y_d);

/*
** colors.c
*/
void	apply_color_next(t_pr *arg);
void    apply_color_game(t_pr *arg);

/*
** random.c
*/
int     random_tetrimino(int Min, int Max);
int     random_first_tetrimino(int Min, int Max);

/*
** save_tab.c
*/
void	my_init_tab(t_pr *arg);
void	print_tab(t_pr *arg);
void	complete_tab(t_pr *arg);

/*
** end_of_game.c
*/
void	print_end_info(t_sco *sco);

/*
** interface_keys.c
*/
void    key_in_game(t_struct *st, t_pr *arg, t_sco *sco);
void    key_left_right(t_struct *st, t_pr *arg, char buff[256]);


/*
**___________________
** GESTION ERREUR
**___________________
*/
void	error_to_exit(char *msg, int status);
int	cerr(char *msg, int status);
void	cerx(char *msg, int status);
void    check_has_color(void);
void    check_maxyx();
void    free_all_windows(t_pr *arg, t_sco *sco);
void	error_help(t_struct *st);

/*
**____________________
**  OPTIONS
**____________________
*/

/*
** list_tetriminos.c
*/
int	make_tetrimino_list(t_struct *st);
void	creat_clean_list(t_struct *st);
void	malloc_list(t_struct *st, int a);
int	tetrimino_cmp(char *s1);

/*
** debug_mod.c
*/
void	debug(t_struct *st);
void	print_key_debug(t_struct *st, char **key_tab);
char	**fill_key_tab(char **key_tab);

/*
** debug_tetrimino.c
*/
void	show_tetrimino_list(t_struct *st);
int	open_tetrimino(char *file);

/*
** check_tetrimino.c
*/
int	verif_tetrimino(char *name);
int	verif_first_line(t_tetri *tet);
int	verif_size(t_tetri *tet);
int	get_xy(t_tetri *tet, int c);
void	tet_malloc(t_tetri *tet);
char	*fill_nb_null(char *str);


/*
** help.c
*/
void	help(t_struct *st);

/*
** level_option.c
*/
void	level(char *arg, t_struct *st);
char	*lvl_nbr(char *arg, char *nbr);
char	*level_nbr(char *arg, char *nbr);

/*
** map_size_option.c
*/
void	map_size(char *arg, t_struct *st);
char	*recup_row(char *arg, char *nbr_row);
char	*recup_col(char *arg, char *nbr_col);

/*
** hub_option.c
*/
void	key_quit(char *arg, t_struct *st);
void	key_pause(char *arg, t_struct *st);
void	without_next(t_struct *st);

/*
** mvmt_options.c
*/
void	key_left(char *arg, t_struct *st);
void	key_right(char *arg, t_struct *st);
void	key_turn(char *arg, t_struct *st);
void	key_drop(char *arg, t_struct *st);


/*
** key_recuperation.c
*/

char	*rcp_key(char *arg, char *key);
char	*recup_key(char *arg, char *key);
void	fill_key_null(t_struct *st, int k);

/*
** options_management.c
*/
void	recup_option(char **opt, t_struct *st);
void	check_cp_option(char **opt, t_struct *st);
void	check_option(char **opt, t_struct *st);
int	opt_cmp(char *opt, char *option_name);

/*
** tab_options.c
*/
void	options_list(char *arg, t_struct *st);
void	tab_option_name(t_struct *st);
void	tab_option_dname(t_struct *st);

/*
** MAIN
*/
void	arguments(int nb, char **av);
void	fill_struct(t_struct *st);
void	fill_struct_keys(t_struct *st);
int	mode(int i);

#endif /* TETRIS_H_ ! */
