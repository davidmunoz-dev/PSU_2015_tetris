/*
** hub_option.c for hub_options in /home/durand_4/rendu/systeme_unix/PSU_2015_tetris/src/options
** 
** Made by loic durand
** Login   <durand_4@epitech.net>
** 
** Started on  Thu Mar 17 23:43:35 2016 loic durand
** Last update Sun Mar 20 15:00:37 2016 loic durand
*/

#include "my.h"
#include "my_tetris.h"

void	key_quit(char *arg, t_struct *st)
{
  char	*key;

  if ((key = malloc(256)) == 0)
    cerx("[ERROR]: Malloc failed\n", 1);
  if (opt_cmp(arg, "--key-left=") == 0)
    key = recup_key(arg, key);
  else
    key = rcp_key(arg, key);
  st->keys[4] = my_strcpy(st->keys[4], key);
  free(key);
}

void	key_pause(char *arg, t_struct *st)
{
  char	*key;

  if ((key = malloc(256)) == 0)
    cerx("[ERROR]: Malloc failed\n", 1);
  if (opt_cmp(arg, "--key-left=") == 0)
    key = recup_key(arg, key);
  else
    key = rcp_key(arg, key);
  st->keys[5] = my_strcpy(st->keys[5], key);
  free(key);
}

void	without_next(t_struct *st)
{
  st->wn = 1;
}
