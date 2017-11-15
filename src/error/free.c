/*
** free.c for  in /PSU_2015_tetris/src/error
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Fri Mar  4 19:52:05 2016 David Munoz
** Last update Thu Mar 17 12:08:47 2016 David Munoz
*/

#include "my.h"
#include "my_tetris.h"

void	free_all_windows(t_pr *arg, t_sco *sco)
{
  free(arg->print_next);
  free(sco->print_info);
  free(arg->t_e_t_r_i_s);
  free(arg->tetris_game);
}
