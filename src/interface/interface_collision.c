/*
** interface_collision.c for  in /PSU_2015_tetris/src/interface
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Mar 10 23:02:04 2016 David Munoz
** Last update Sun Mar 20 15:08:31 2016 David Munoz
*/

#include "my.h"
#include "my_tetris.h"


/*	Collisions : On va STRCPY le tetrimino qui est
**	en train de descendre d'une case en dessous
**	EX :     |   ****   | <-tetrimino barre
**	         |   ####   | <-le meme tetrimino STCPY
**	Ce tetrimino est stocké dans un tableau 2D
**	et lorsqu'il rencontre un autre tetrimino
**	il s'arrete, l'affiche, et passe au suivant tetrim
*/

/*
**	Initialise le tablea 2D de la barre detectrice
*/
void	init_barre_detectrice(t_pr *arg)
{
  int   y;
  int   x;

  y = -1;
  if ((arg->tab_d = malloc(200 * sizeof(arg->tab_d))) == 0)
    error_to_exit("Error : Malloc failed", 1);
  while (++y <= 21)
    {
      if ((arg->tab_d[y] = malloc(200 * sizeof(arg->tab_d))) == 0)
	error_to_exit("Error : Malloc failed", 1);
      x = -1;
      while (++x < 10)
	{
	  arg->tab_d[y][x] = '_';
	}
    }
}

/*
**	STRCPY le tetrimino d'une case en dessous
*/
char	*my_strcpy_tetris(char *dest, char *src)
{
  int   i;
  int   n;

  i = 5;
  n = 0;
  while (src[i] != '\0')
    {
      if (src[i] == '*')
        dest[n] = '#';
      else
        dest[n] = src[i];
      i++;
      n++;
    }
  return (dest);
}

/*
**	Detection d'un tetrimino
*/
void	barre_detectrice(t_pr *arg)
{
  char  *buff_d;

  arg->a = arg->x_d = arg->y_d = 0;
  if ((buff_d = malloc(800)) == 0)
    error_to_exit("[ERROR]: Malloc failed\n", 1);
  my_strcpy_tetris(buff_d, arg->buffer);
  while (buff_d[arg->a] == '#' || buff_d[arg->a] == '\n' || buff_d[arg->a]==' ')
    {
      if (buff_d[arg->a] == '\n')
        {
          arg->y_d++;
          arg->x_d = 0;
        }
      else if (buff_d[arg->a] == ' ')
	arg->x_d++;
      else if (buff_d[arg->a] == '#')
        {
          arg->tab_d[arg->y + arg->y_d][arg->x + arg->x_d] = buff_d[arg->a];
	  if (arg->tab[arg->y + arg->y_d][arg->x + arg->x_d] != '\n'
	      && arg->tab[arg->y + arg->y_d][arg->x + arg->x_d] != '-')
	    arg->c = 1;
	  arg->x_d++;
        }
      arg->a++;
    }
}
