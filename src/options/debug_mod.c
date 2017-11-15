/*
** debug_mod.c for debug_mod in /home/durand_4/rendu/systeme_unix/PSU_2015_tetris/src
**
** Made by loic durand
** Login   <durand_4@epitech.net>
**
** Started on  Tue Mar  1 13:08:16 2016 loic durand
** Last update Fri Mar 18 16:28:28 2016 loic durand
*/

#include "my.h"
#include "my_tetris.h"

void	debug(t_struct *st)
{
  char	**key_tab;
  char	*buffer;

  if ((key_tab = malloc(sizeof(char *) * 6)) == 0)
    cerx("[ERROR]: Malloc failed\n", 1);
  key_tab = fill_key_tab(key_tab);
  my_putstr("*** DEBUG MOD ***\n");
  print_key_debug(st, key_tab);
  free(key_tab);
  my_putstr("Next : ");
  if (st->wn == 0)
    my_putstr("Yes\n");
  else
    my_putstr("No\n");
  my_printf("Level : %d\n", st->level);
  my_printf("Size : %d*%d\n", st->row, st->col);
  my_printf("Tetriminos : %d\n", st->nb_tet);
  show_tetrimino_list(st);
  my_putstr("Press a key to start Tetris\n");
  if ((buffer = malloc(256)) == 0)
    cerx("[ERROR]: Malloc failed\n", 1);
  mode(0);
  while (read(0, buffer, 256) <= 0);
  mode(1);
  free(buffer);
}

void	print_key_debug(t_struct *st, char **key_tab)
{
  int	n;
  int	k;

  n = -1;
  while (++n <= 5)
    {
      my_printf("Key %s : ", key_tab[n]);
      k = 0;
      while (st->keys[n][k] != '\0')
	{
	  if (st->keys[n][k] == 27)
	    my_putstr("^E");
	  else if (st->keys[n][k] == ' ')
	    my_putstr("(space)");
	  else
	    my_putchar(st->keys[n][k]);
	  k++;
	}
      my_putchar('\n');
    }
}

char	**fill_key_tab(char **key_tab)
{
  key_tab[0] = malloc(4);
  key_tab[0] = "Left";
  key_tab[1] = malloc(5);
  key_tab[1] = "Right";
  key_tab[2] = malloc(4);
  key_tab[2] = "Turn";
  key_tab[3] = malloc(4);
  key_tab[3] = "Drop";
  key_tab[4] = malloc(4);
  key_tab[4] = "Quit";
  key_tab[5] = malloc(5);
  key_tab[5] = "Pause";
  return (key_tab);
}
