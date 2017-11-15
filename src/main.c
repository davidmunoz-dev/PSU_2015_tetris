/*
** main.c for a in rendu_Tetris/PSU_2015_tetris/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Mon Feb 22 09:53:59 2016 David Munoz
** Last update Sat Mar 19 16:02:04 2016 David Munoz
*/

#include "my.h"
#include "my_tetris.h"
#include <term.h>

void	arguments(int nb, char **av)
{
  t_struct      *st;

  if ((st = malloc(sizeof(t_struct *))) == 0)
    cerx("[ERROR]: Malloc failed\n", 1);
  make_tetrimino_list(st);
  setupterm(NULL, 1, 0);
  fill_struct(st);
  if (nb > 1)
    recup_option(av, st);
  my_putstr(tigetstr("smkx"));
  initscr();
  interface(st);
  refresh();
  endwin();
  my_putstr(tigetstr("rmkx"));
}

void	fill_struct(t_struct *st)
{
  st->level = 1;
  st->row = 20;
  st->col = 10;
  st->wn = 0;
  if ((st->keys = malloc(sizeof(char *) * 6)) == 0)
    cerx("[ERROR]: Malloc failed\n", 1);
  fill_struct_keys(st);
}

void	fill_struct_keys(t_struct *st)
{
  if ((st->keys[0] = malloc(256)) == 0)
    cerx("[ERROR]: Malloc failed\n", 1);
  st->keys[0] = my_strcpy(st->keys[0], tigetstr("kcub1"));
  st->keys[0][3] = '\0';
  if ((st->keys[1] = malloc(256)) == 0)
    cerx("[ERROR]: Malloc failed\n", 1);
  st->keys[1] = my_strcpy(st->keys[1], tigetstr("kcuf1"));
  st->keys[1][3] = '\0';
  if ((st->keys[2] = malloc(256)) == 0)
    cerx("[ERROR]: Malloc failed\n", 1);
  st->keys[2] = my_strcpy(st->keys[2], tigetstr("kcuu1"));
  st->keys[2][3] = '\0';
  if ((st->keys[3] = malloc(256)) == 0)
    cerx("[ERROR]: Malloc failed\n", 1);
  st->keys[3] = my_strcpy(st->keys[3], tigetstr("kcud1"));
  st->keys[3][3] = '\0';
  if ((st->keys[4] = malloc(256)) == 0)
    cerx("[ERROR]: Malloc failed\n", 1);
  st->keys[4][0] = 'q';
  st->keys[4][1] = '\0';
  if ((st->keys[5] = malloc(256)) == 0)
    cerx("[ERROR]: Malloc failed\n", 1);
  st->keys[5][0] = ' ';
  st->keys[5][1] = '\0';
}

int	mode(int i)
{
  static struct	termios oldT;
  static struct	termios newT;

  if (i == 0)
    {
      ioctl(0, TCGETS, &oldT);
      ioctl(0, TCGETS, &newT);
      newT.c_lflag &= ~ECHO;
      newT.c_lflag &= ~ICANON;
      newT.c_cc[VMIN] = 0;
      newT.c_cc[VTIME] = 10;
      ioctl(0, TCSETS, &newT);
    }
  else if (i == 1)
    ioctl(0, TCSETS, &oldT);
  return (0);
}

int	main(int ac, char **av)
{
  arguments(ac, av);
  return (0);
}
