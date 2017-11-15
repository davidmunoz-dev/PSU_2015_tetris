/*
** save_tab.c for  in /PSU_2015_tetris/src/interface
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Tue Mar  8 12:11:30 2016 David Munoz
** Last update Sun Mar 20 16:23:09 2016 David Munoz
*/

#include "my.h"
#include "my_tetris.h"

/*
**	Initialise un tableau 2D pour stocké
**	les tetriminos arrivé a destination
*/
void	my_init_tab(t_pr *arg)
{
  int   y;
  int   x;

  y = -1;
  if ((arg->tab = malloc(200 * sizeof(arg->tab))) == 0)
    error_to_exit("Error : Read failed\n", 1);
  while (++y <= 21)
    {
      if ((arg->tab[y] = malloc(200 * sizeof(arg->tab))) == 0)
	error_to_exit("Error : Read failed\n", 1);
      x = -1;
      while (++x < 11)
	arg->tab[y][x] = '-';
    }
}

/*
**	Affiche le tableau 2D
*/
void	print_tab(t_pr *arg)
{
  int	x;
  int	y;

  y = 0;
  while (++y <= 20)
    {
      x = 0;
      while (++x < 11)
	{
	  if (arg->tab[y][x] != '-' && arg->tab[y][x] != '\n')
	    {
	      init_pair(7, COLOR_WHITE, COLOR_BLACK);
	      wattron(arg->tetris_game, COLOR_PAIR(arg->tab[y][x]) | A_REVERSE);
	      mvwprintw(arg->tetris_game, y, x, " ");
	      wattroff(arg->tetris_game, COLOR_PAIR(arg->tab[y][x]) | A_REVERSE);
	    }
	  else
	    mvwprintw(arg->tetris_game, y, x, " ", arg->tab[y][x]);
	}
    }
}

/*
**	Complete le tableau 2D
*/
void	complete_tab(t_pr *arg)
{
  int	a;
  int	stock;

  a = 6;
  arg->n = 0;
  stock = arg->x;
  while (arg->buffer[a] == '*' || arg->buffer[a] == '\n' || arg->buffer[a]==' ')
    {
      if (arg->buffer[a] == '\n')
	{
	  arg->y++;
	  arg->x = stock;
	}
      else if (arg->buffer[a] == '*')
	{
	  arg->tab[arg->y][arg->x] = arg->color;
	  arg->x++;
	}
      else if (arg->buffer[a] == ' ')
	arg->x++;
      a++;
    }
  print_tab(arg);
}
