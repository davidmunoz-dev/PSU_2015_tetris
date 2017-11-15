/*
** check_tetrimino.c for check_tetrimino in /home/durand_4/rendu/systeme_unix/PSU_2015_tetris/src
**
** Made by loic durand
** Login   <durand_4@epitech.net>
**
** Started on  Fri Mar 18 16:36:24 2016 loic durand
** Last update Sun Mar 20 14:48:11 2016 loic durand
*/

#include "my.h"
#include "my_tetris.h"

int	verif_tetrimino(char *name)
{
  t_tetri	*tet;

  if ((tet = malloc(sizeof(t_tetri *))) == 0)
    cerx("[ERROR]: Malloc failed\n", 1);
  tet_malloc(tet);
  tet->file = my_strcpy(tet->file, "./tetriminos/");
  tet->file = my_strcat(tet->file, name);
  if ((tet->fd = open(tet->file, O_RDONLY)) == -1)
    return (1);
  if (read(tet->fd, tet->buffer, 50) <= 0)
    return (1);
  if (verif_first_line(tet) == 1)
    return (1);
  if (verif_size(tet) == 1)
    return (1);
  close(tet->fd);
  return (0);
}

int	verif_first_line(t_tetri *tet)
{
  int	c;

  tet->a = 0;
  c = 0;
  tet->nb = fill_nb_null(tet->nb);
  while (tet->buffer[tet->a] != '\n' && tet->buffer[tet->a] != '\0' && c <= 3)
    {
      tet->b = 0;
      while (tet->buffer[tet->a] != ' ' && tet->buffer[tet->a] != '\0'
	     && tet->buffer[tet->a] != '\n')
	{
	  if ((tet->buffer[tet->a] < '0' || tet->buffer[tet->a] > '9')
	      && tet->buffer[tet->a] != '*')
	    return (1);
	  tet->nb[tet->b] = tet->buffer[tet->a];
	  tet->a++;
	  tet->b++;
	}
      c = get_xy(tet, c);
      tet->a++;
    }
  return (0);
}

int	get_xy(t_tetri *tet, int c)
{
  if (tet->nb[0] != '\0')
    {
      tet->xy[c] = my_getnbr(tet->nb);
      c++;
      tet->nb = fill_nb_null(tet->nb);
    }
  return (c);
}

int	verif_size(t_tetri *tet)
{
  tet->a = 0;
  tet->vc = 0;
  while (tet->buffer[tet->a] != '\n' && tet->buffer[tet->a] != '\0')
    tet->a++;
  tet->r = 0;
  while (tet->buffer[tet->a] != '\0')
    {
      tet->l = 0;
      while (tet->buffer[tet->a] != '\n' && tet->buffer[tet->a] != '\0')
	{
	  if (tet->buffer[tet->a] == '*' || tet->buffer[tet->a] == ' ')
	    tet->l++;
	  if (tet->l > tet->xy[0])
	    return (1);
	  if (tet->l == tet->xy[0])
	    tet->vc = 1;
	  tet->a++;
	}
      if (tet->l > 0)
	tet->r++;
      tet->a++;
    }
  if (tet->r > tet->xy[1] || tet->vc == 0)
    return (1);
  return (0);
}
