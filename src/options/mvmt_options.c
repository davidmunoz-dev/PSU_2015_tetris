/*
** mvmt_options.c for mvmt_options.c in /home/durand_4/rendu/systeme_unix/PSU_2015_tetris/src/options
** 
** Made by loic durand
** Login   <durand_4@epitech.net>
** 
** Started on  Thu Mar  3 17:53:17 2016 loic durand
** Last update Sun Mar 20 15:01:03 2016 loic durand
*/

#include "my.h"
#include "my_tetris.h"

void	key_left(char *arg, t_struct *st)
{
  char  *key;

  if ((key = malloc(256)) == 0)
    cerx("[ERROR]: Malloc failed\n", 1);
  if (opt_cmp(arg, "--key-left=") == 0)
    key = recup_key(arg, key);
  else
    key = rcp_key(arg, key);
  fill_key_null(st, 0);
  st->keys[0] = my_strcpy(st->keys[0], key);
  free(key);
}

void	key_right(char *arg, t_struct *st)
{
  char  *key;

  if ((key = malloc(256)) == 0)
    cerx("[ERROR]: Malloc failed\n", 1);
  if (opt_cmp(arg, "--key-left=") == 0)
    key = recup_key(arg, key);
  else
    key = rcp_key(arg, key);
  fill_key_null(st, 0);
  st->keys[1] = my_strcpy(st->keys[1], key);
  free(key);
}

void	key_turn(char *arg, t_struct *st)
{
  char  *key;

  if ((key = malloc(256)) == 0)
    cerx("[ERROR]: Malloc failed\n", 1);
  if (opt_cmp(arg, "--key-left=") == 0)
    key = recup_key(arg, key);
  else
    key = rcp_key(arg, key);
  fill_key_null(st, 0);
  st->keys[2] = my_strcpy(st->keys[2], key);
  free(key);
}

void	key_drop(char *arg, t_struct *st)
{
  char  *key;

  if ((key = malloc(256)) == 0)
    cerx("[ERROR]: Malloc failed\n", 1);
  if (opt_cmp(arg, "--key-left=") == 0)
    key = recup_key(arg, key);
  else
    key = rcp_key(arg, key);
  fill_key_null(st, 0);
  st->keys[3] = my_strcpy(st->keys[3], key);
  free(key);
}
