/*
** level_option.c for level_option in /home/durand_4/rendu/systeme_unix/PSU_2015_tetris/src/options
** 
** Made by loic durand
** Login   <durand_4@epitech.net>
** 
** Started on  Wed Mar 16 14:45:38 2016 loic durand
** Last update Thu Mar 17 14:17:41 2016 loic durand
*/

#include "my.h"
#include "my_tetris.h"

void	level(char *arg, t_struct *st)
{
  int   d;
  char  *nbr;

  d = 0;
  if ((nbr = malloc(my_strlen(arg))) == 0)
    cerx("[ERROR]: Malloc failed\n", 1);
  if (opt_cmp(arg, "--level=") == 0)
    nbr = level_nbr(arg, nbr);
  else
    nbr = lvl_nbr(arg, nbr);
  if ((d = my_getnbr(nbr)) > 0)
    st->level = d;
  if (d == 0)
    {
      my_putstr("ERROR: Bad argument for level option\n");
      st->level = 1;
    }
  free(nbr);
}

char	*lvl_nbr(char *arg, char *nbr)
{
  int	a;
  int	c;

  a = 0;
  c = 0;
  while (arg[a] != '\0')
    {
      if (arg[a] >= '0' && arg[a] <= '9')
	{
	  nbr[c] = arg[a];
	  c++;
	}
      a++;
    }
  nbr[c] = '\0';
  return (nbr);
}

char	*level_nbr(char *arg, char *nbr)
{
  int	a;
  int	c;

  a = 0;
  c = 0;
  while (arg[a] != '=')
    a++;
  while (arg[a] != '\0')
    {
      if (arg[a] >= '0' && arg[a] <= '9')
	{
	  nbr[c] = arg[a];
	  c++;
	}
      a++;
    }
  nbr[c] = '\0';
  return (nbr);
}
