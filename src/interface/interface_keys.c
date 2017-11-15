/*
** interface_keys.c for  in /PSU_2015_tetris/src/interface
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Fri Mar 18 16:00:00 2016 David Munoz
** Last update Sat Mar 19 16:52:55 2016 David Munoz
*/

#include "my.h"
#include "my_tetris.h"

void	key_in_game(t_struct *st, t_pr *arg, t_sco *sco)
{
  char	buff[256];

  mode(0);
  read(0, buff, 255);
  key_left_right(st, arg, buff);
  if (my_strcmp(st->keys[4], buff) == 0)
    error_to_exit(GREEN"Exit success\n"BLANK, 1);
  if (my_strcmp(st->keys[5], buff) == 0)
    {
      while (read(0, buff, 255) <= 0)
	{
	  mvwprintw(sco->print_info, 9, 1, "/!\\PAUSE/!\\");
	  start_info_tetris(sco);
	  wrefresh(sco->print_info);
	}
      wclear(sco->print_info);
      print_info_IG(sco);
    }
  mode(1);
}

void	key_left_right(t_struct *st, t_pr *arg, char *buff)
{
  if (my_strcmp(st->keys[0], buff) == 0)
    {
      if (arg->x != 1)
        arg->x--;
    }
  if (my_strcmp(st->keys[1], buff) == 0)
    {
      if (arg->x != 9)
	arg->x++;
    }
}
