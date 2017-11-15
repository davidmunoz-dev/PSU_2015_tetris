/*
** errors.c for  in /PSU_2015_tetris/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Fri Mar  4 14:47:34 2016 David Munoz
** Last update Fri Mar 18 11:13:37 2016 loic durand
*/

#include "my.h"
#include "my_tetris.h"

void	error_to_exit(char *msg, int status)
{
  refresh();
  clear();
  endwin();
  my_putstr(msg);
  exit(status);
}

int	cerr(char *msg, int status)
{
  write(2, msg, my_strlen(msg));
  return (status);
}

void	cerx(char *msg, int status)
{
  write(2, msg, my_strlen(msg));
  exit (status);
}

void	check_has_color(void)
{
  if (has_colors() == FALSE)
    error_to_exit(RED"Your terminal doesn't support color\n"BLANK, 1);
}

void	check_maxyx()
{
  int	row;
  int	col;

  getmaxyx(stdscr, row, col);
  if (row < 24 || col < 54)
    {
      refresh();
      clear();
      endwin();
      my_putstr(RED"Error: Enlarge your terminal\nMinimum size : 54*24\n"BLANK);
      exit(1);
    }
}
