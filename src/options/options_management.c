/*
** options_management.c for options_management in /home/durand_4/rendu/systeme_unix/PSU_2015_tetris/src
** 
** Made by loic durand
** Login   <durand_4@epitech.net>
** 
** Started on  Mon Feb 22 14:00:38 2016 loic durand
** Last update Sun Mar 20 14:53:39 2016 loic durand
*/

#include "my.h"
#include "my_tetris.h"

void	recup_option(char **opt, t_struct *st)
{
  if ((st->binarie_name = malloc(my_strlen(opt[0]))) == 0)
    cerx("[ERROR]: Malloc failed\n", 1);
  st->binarie_name[my_strlen(opt[0])] = '\0';
  st->binarie_name = my_strcpy(st->binarie_name, opt[0]);
  st->b = 1;
  if ((st->option_name = malloc(sizeof(char *) * 19)) == 0)
    cerx("[ERROR]: Malloc failed\n", 1);
  tab_option_name(st);
  while (opt[st->b] != '\0')
    {
      if (opt[st->b][0] == '-')
	{
	  st->a = 0;
	  while ((my_strcmp(opt[st->b], st->option_name[st->a])) != 0
		 && st->a <= 9)
	    st->a++;
	  if (st->a == 10)
	    check_cp_option(opt, st);
	  else
	    check_option(opt, st);
	}
      else if (opt[st->b][0] != '-')
      	error_help(st);
      st->b++;
    }
}

void	check_cp_option(char **opt, t_struct *st)
{
  while (st->a <= 11 && my_strcmp(opt[st->b], st->option_name[st->a]) != 0)
    st->a++;
  if (st->a == 10 || st->a == 11)
    {
      st->a = st->a - 9;
      options_list("void", st);
    }
  else
    {
      while (st->a <= 19 && opt_cmp(opt[st->b], st->option_name[st->a]) != 0)
	st->a++;
      if (st->a >= 12 && st->a <= 19)
	{
	  st->a = st->a - 9;
	  options_list(opt[st->b], st);
	}
      else if (st->a == 20)
	help(st);
    }
}

void	check_option(char **opt, t_struct *st)
{
  if (st->a >= 3 && st->a <= 9)
    {
      options_list(opt[st->b + 1], st);
      st->b++;
    }
  else
    options_list("void", st);
}

int	opt_cmp(char *opt, char *option_name)
{
  int	a;

  a = 0;
  while (option_name[a] != '\0')
    {
      if (option_name[a] != opt[a])
	return (1);
      a++;
    }
  return (0);
}
