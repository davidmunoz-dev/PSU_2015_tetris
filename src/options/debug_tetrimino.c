/*
** debug_tetrimino.c for debug_tetrimino in /home/durand_4/rendu/systeme_unix/PSU_2015_tetris/src/options
** 
** Made by loic durand
** Login   <durand_4@epitech.net>
** 
** Started on  Fri Mar 18 11:30:43 2016 loic durand
** Last update Sat Mar 19 21:58:37 2016 loic durand
*/

#include "my.h"
#include "my_tetris.h"

void	show_tetrimino_list(t_struct *st)
{
  int	a;
  int	b;

  a = 0;
  while (st->list[a] != '\0')
    {
      my_printf("Tetrominos : Name ");
      b = 13;
      while (st->list[a][b] != '.')
        {
          my_putchar(st->list[a][b]);
          b++;
        }
      my_printf(" : ");
      open_tetrimino(st->list[a]);
      a++;
    }
}

int	open_tetrimino(char *file)
{
  int	fd;
  char	*buffer;
  int	a;

  if ((buffer = malloc(50)) == 0)
    return (cerr("Error\n", 1));
  if ((fd = open(file, O_RDONLY)) == -1)
    return (cerr("Error\n", 1));
  if (read(fd, buffer, 50) <= 0)
    return (cerr("Error\n", 1));
  my_printf("Size %d*%d : ", (buffer[0] - 48), (buffer[2] - 48));
  my_printf("Color %d :\n", (buffer[4] - 48));
  a = 6;
  while (buffer[a] == '*' || buffer[a] == '\n' || buffer[a] == ' ')
    {
      my_putchar(buffer[a]);
      a++;
    }
  close(fd);
  return (0);
}
