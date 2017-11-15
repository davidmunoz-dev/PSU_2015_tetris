/*
** interface_print_tetris_game.c for  in /PSU_2015_tetris/src/interface
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Sat Mar  5 00:07:36 2016 David Munoz
** Last update Sat Mar 19 15:54:32 2016 David Munoz
*/


#include "my.h"
#include "my_tetris.h"

/*
**	Stock le premier tetrimino (différent du next)
*/
void	stock_first_tetrimino(t_pr *arg, char *file)
{
  int   fd;

  if ((arg->buffer = malloc(50)) == 0)
    error_to_exit("Error : Malloc failed", 1);
  if ((fd = open(file, O_RDONLY)) <= 0)
    error_to_exit("Error : Open failed\n", 1);
  if (read(fd, arg->buffer, 50) <= 0)
    error_to_exit("Error : Read failed\n", 1);
  close(fd);
}

/*
**	Fait descendre le tetrimino de haut en bas
*/
void	top_tetrimino_to_bottom(t_pr *arg, t_struct *st, t_sco *sco)
{
  arg->x = 5;
  arg->y = 0;
  arg->c = 0;

  print_tab(arg);
  init_barre_detectrice(arg);
  while (arg->y + arg->n != 21 && arg->c == 0)
    {
      key_in_game(st, arg, sco);
      arg->y++;
      print_tab(arg);
      print_top_tetrimino(arg);
      barre_detectrice(arg);
      wrefresh(arg->tetris_game);
      wclear(arg->tetris_game);
      start_interface_tetris(arg);
    }
  complete_tab(arg);
}

/*
**	Affiche le tetrimino
*/
void	print_top_tetrimino(t_pr *arg)
{
  int	a;

  a = 6;
  arg->n = 0;
  arg->m = 0;
  while (arg->buffer[a] == '*' || arg->buffer[a] == '\n' || arg->buffer[a]==' ')
    {
      if (arg->buffer[a] == '\n')
        {
          arg->n++;
	  arg->m = 0;
        }
      else if (arg->buffer[a] == '*')
	{
	  apply_color_game(arg);
	  mvwprintw(arg->tetris_game, arg->y + arg->n, arg->x + arg->m++, " ");
	  wattroff(arg->tetris_game, COLOR_PAIR(arg->color) | A_REVERSE);
	}
      else if (arg->buffer[a] == ' ')
	arg->m++;
      a++;
    }
}

/*
**	Fonction principale de l'interface de jeu du tetris
**	(l'interface où les tetriminos s'empilent)
*/
void	print_tetrimino_IG(t_pr *arg, t_struct *st, t_sco *sco)
{
  start_interface_tetris(arg);
  top_tetrimino_to_bottom(arg, st, sco);
  wrefresh(arg->tetris_game);
  wclear(arg->tetris_game);
}

/*
**	Initialise la window de l'interface
*/
void	start_interface_tetris(t_pr *arg)
{
  arg->tetris_game = subwin(stdscr, 22, 12, 1, 28);
  box(arg->tetris_game, ACS_VLINE, ACS_HLINE);
}
