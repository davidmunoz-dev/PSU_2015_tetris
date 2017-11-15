/*
** basic_check_function.c for basic_check_function in /home/durand_4/rendu/systeme_unix/PSU_2015_tetris/src
** 
** Made by loic durand
** Login   <durand_4@epitech.net>
** 
** Started on  Sat Mar 19 17:32:17 2016 loic durand
** Last update Sun Mar 20 11:26:34 2016 loic durand
*/

#include "my.h"
#include "my_tetris.h"

void	tet_malloc(t_tetri *tet)
{
  if ((tet->buffer = malloc(50)) == 0)
    cerx("[ERROR]: Malloc failed\n", 1);
  if ((tet->file = malloc(100)) == 0)
    cerx("[ERROR]: Malloc failed\n", 1);
  tet->file = fill_nb_null(tet->file);
  if ((tet->xy = malloc(sizeof(int *) * 3)) == 0)
    cerx("[ERROR]: Malloc failed\n", 1);
  if ((tet->nb = malloc(sizeof(int))) == 0)
    cerx("[ERROR]: Malloc failed\n", 1);
}

char	*fill_nb_null(char *str)
{
  int   a;

  a = 0;
  while (str[a] != '\0')
    {
      str[a] = '\0';
      a++;
    }
  return (str);
}
