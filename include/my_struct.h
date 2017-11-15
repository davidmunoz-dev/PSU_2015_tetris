/*
** my_struct.h for my_struct in /home/durand_4/rendu/systeme_unix/PSU_2015_tetris/include
**
** Made by loic durand
** Login   <durand_4@epitech.net>
**
** Started on  Wed Mar  2 16:08:34 2016 loic durand
** Last update Sun Mar 20 14:46:30 2016 loic durand
*/

#ifndef MY_STRUCT_H_
# define MY_STRUCT_H_

typedef struct	s_struct
{
  char	**option_name;
  char	**tet_list;
  char	**list;
  char	*path;
  char	*binarie_name;
  int	nb_tet;
  int	nb_while;
  int	a;
  int	b;
  char	**keys;
  int	level;
  int	row;
  int	col;
  int	wn;
}		t_struct;

typedef struct	s_tetri
{
  char	*buffer;
  char	*nb;
  int	*xy;
  int	a;
  int	b;
  int	c;
  char	*file;
  int	fd;
  int	vc;
  int	r;
  int	l;
}		t_tetri;

#endif /* !MY_STRUCT_H_ */
