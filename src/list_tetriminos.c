/*
** list_tetriminos.c for list_tetriminos in /home/durand_4/rendu/systeme_unix/PSU_2015_tetris/src
**
** Made by loic durand
** Login   <durand_4@epitech.net>
**
** Started on  Thu Mar  3 13:46:48 2016 loic durand
** Last update Sat Mar 19 21:55:48 2016 loic durand
*/

#include "my.h"
#include "my_tetris.h"

void	malloc_list(t_struct *st, int a)
{
  if ((st->tet_list = malloc(sizeof(char *) * (a - 1))) == 0)
    cerx("[ERROR]: Malloc failed\n", 1);
  if ((st->list = malloc(sizeof(char *) * (a - 1))) == 0)
    cerx("[ERROR]: Malloc failed\n", 1);
  st->nb_while = a - 1;
}

int	make_tetrimino_list(t_struct *st)
{
  DIR		*tet;
  struct dirent	*file;
  int		a;

  a = 0;
  if ((tet = opendir("./tetriminos")) == NULL)
    return (cerr("[ERROR]: opendir problem\n", -1));
  while (readdir(tet))
    a++;
  malloc_list(st, a);
  a = 0;
  if ((tet = opendir("./tetriminos")) == NULL)
    return (cerr("[ERROR]: opendir problem\n", -1));
  while ((file = readdir(tet)))
    {
      if ((st->tet_list[a] = malloc(1)) == 0)
	cerx("[ERROR]: Malloc failed\n", 1);
      my_strcpy(st->tet_list[a], file->d_name);
      a++;
    }
  creat_clean_list(st);
  closedir(tet);
  return (0);
}

void	creat_clean_list(t_struct *st)
{
  int	a;
  int	c;
  char	*path;

  st->nb_tet = 0;
  c = 0;
  while (++c <= 122)
    {
      a = -1;
      while (++a <= st->nb_while)
        {
          if (tetrimino_cmp(st->tet_list[a]) >= 0 && st->tet_list[a][0] == c
	      && verif_tetrimino(st->tet_list[a]) == 0)
            {
              if ((path = malloc(60)) == 0)
                cerx("[ERROR]: Malloc failed\n", 1);
	      path = my_strcpy(path, "./tetriminos/");
              if ((st->list[st->nb_tet] = malloc(1)) == 0)
                cerx("[ERROR]: Malloc failed\n", 1);
	      st->list[st->nb_tet] = my_strcat(path, st->tet_list[a]);
              st->nb_tet++;
            }
        }
    }
}

int	tetrimino_cmp(char *s1)
{
  int	a;
  int	b;
  char	*s2;

  if ((s2 = malloc(10)) == 0)
    cerx("[ERROR]: Malloc failed\n", 1);
  s2 = ".tetrimino";
  a = my_strlen(s1);
  b = 10;
  while (s1[a] == s2[b] && s1[a] != '.' &&
         s1[a] != '\0' && s2[b] != '\0')
    {
      a--;
      b--;
    }
  return (a - b);
}
