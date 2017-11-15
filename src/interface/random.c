/*
** random.c for  in /PSU_2015_tetris/src/interface
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Mon Mar  7 11:31:17 2016 David Munoz
** Last update Mon Mar  7 15:11:05 2016 David Munoz
*/

#include "my.h"
#include "my_tetris.h"

/*
** Random sur les prochaines pièces
*/
int	random_tetrimino(int Min, int Max)
{
  srand((unsigned)time(NULL));
  return (Min + (rand() % (Max - Min+1)));
}

/*
** Random sur la première pièce
*/
int	random_first_tetrimino(int Min, int Max)
{
  return (Min + (rand() % (Max - Min+1)));
}
