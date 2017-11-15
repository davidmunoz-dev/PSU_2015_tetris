/*
** map_size_option.c for map_size_option in /home/durand_4/rendu/systeme_unix/PSU_2015_tetris/src/options
** 
** Made by loic durand
** Login   <durand_4@epitech.net>
** 
** Started on  Wed Mar 16 15:27:46 2016 loic durand
** Last update Thu Mar 17 17:38:03 2016 loic durand
*/

#include "my.h"
#include "my_tetris.h"

void	map_size(char *arg, t_struct *st)
{
  char	*nbr_row;
  char	*nbr_col;
  int	nbr;

  nbr = 0;
  if ((nbr_row = malloc(my_strlen(arg))) == 0)
    cerx("[ERROR]: Malloc failed\n", 1);
  if ((nbr_col = malloc(my_strlen(arg))) == 0)
    cerx("[ERROR]: Malloc failed\n", 2);
  nbr_row = recup_row(arg, nbr_row);
  nbr_col = recup_col(arg, nbr_col);
  if ((nbr = my_getnbr(nbr_row)) > 0)
    st->row = nbr;
  if ((nbr = my_getnbr(nbr_col)) > 0)
    st->col = nbr;
  if (nbr == 0)
    {
      my_putstr("[ERROR]: Bad argument for map-size option\n");
      st->row = 20;
      st->col = 10;
    }
  free(nbr_row);
  free(nbr_col);
}

char	*recup_row(char *arg, char *nbr_row)
{
  int	a;
  int	b;

  a = 0;
  b = 0;
  while (arg[a] != '=' && arg[a] != '\0')
    a++;
  a++;
  while (arg[a] != ',' && arg[a] != '\0')
    {
      nbr_row[b] = arg[a];
      a++;
      b++;
    }
  nbr_row[b] = '\0';
  return (nbr_row);
}

char	*recup_col(char *arg, char *nbr_col)
{
  int	a;
  int	b;

  a = 0;
  b = 0;
  while (arg[a] != ',' && arg[a] != '\0')
    a++;
  a++;
  while (arg[a] != '\0')
    {
      nbr_col[b] = arg[a];
      a++;
      b++;
    }
  nbr_col[b] = '\0';
  return (nbr_col);
}
