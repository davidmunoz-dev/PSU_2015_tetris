/*
** key_recuperation.c for key_recuperation in /home/durand_4/rendu/systeme_unix/PSU_2015_tetris/src/options
** 
** Made by loic durand
** Login   <durand_4@epitech.net>
** 
** Started on  Thu Mar 17 23:39:11 2016 loic durand
** Last update Sun Mar 20 14:55:23 2016 loic durand
*/

#include "my.h"
#include "my_tetris.h"

char	*rcp_key(char *arg, char *key)
{
  int	a;

  a = 0;
  while (arg[a] != '\0')
    {
      key[a] = arg[a];
      a++;
    }
  key[a] = '\0';
  return (key);
}

char	*recup_key(char *arg, char *key)
{
  int	a;
  int	c;

  a = 0;
  c = 0;
  while (arg[a] != '=')
    a++;
  a++;
  while (arg[a] != '\0')
    {
      key[c] = arg[a];
      c++;
      a++;
    }
  key[c] = '\0';
  return (key);
}

void	fill_key_null(t_struct *st, int k)
{
  int	a;

  a = 0;
  while (st->keys[k][a] != '\0')
    {
      st->keys[k][a] = '\0';
      a++;
    }
}
