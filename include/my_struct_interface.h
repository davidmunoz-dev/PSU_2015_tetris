/*
** my_struct_interface.h for  in /PSU_2015_tetris/include
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Mar  3 14:51:30 2016 David Munoz
** Last update Sat Mar 19 16:49:16 2016 David Munoz
*/

#ifndef MY_STRUCT_INTERFACE_H_
# define MY_STRUCT_INTERFACE_H_

typedef struct  s_pr
{
  WINDOW	*t_e_t_r_i_s;
  WINDOW	*print_next;
  WINDOW	*tetris_game;
  char		**tab;
  char		**tab_d;
  char		*buffer;
  char		*bfnext;
  int		color;
  int		color_next;
  int		x;
  int		y;
  int		n;
  int		m;
  int		x_n;
  int		y_n;
  int		a_n;
  int		c;
  int		x_d;
  int		y_d;
  int		a;
}               t_pr;

typedef struct	t_scr
{
  WINDOW        *print_info;
  int   tour;
  int   a_rand;
  int   hi_sc;
  int   sc;
  int   lines;
  int	level;
  int	row;
  int	col;
}		t_sco;

#endif /* !MY_STRUCT_INTERFACE_H_ */
