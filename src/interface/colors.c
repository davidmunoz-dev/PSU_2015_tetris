/*
** colors.c for  in /PSU_2015_tetris/src/interface
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Fri Mar  4 22:10:10 2016 David Munoz
** Last update Thu Mar 17 00:29:09 2016 David Munoz
*/

#include "my.h"
#include "my_tetris.h"

/*
**	Applique les couleurs au tetrimino du NEXT
*/
void	apply_color_next(t_pr *arg)
{
  arg->color_next = arg->bfnext[4] - 48;
  if (arg->color_next == 1)
    init_pair(1, COLOR_RED, COLOR_BLACK);
  else if (arg->color_next == 2)
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
  else if (arg->color_next == 3)
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  else if (arg->color_next == 4)
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
  else if (arg->color_next == 5)
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
  else if (arg->color_next == 6)
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
  else
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
  wattron(arg->print_next, COLOR_PAIR(arg->color_next) | A_REVERSE);
}

/*
**	Applique les couleurs aux tetriminos de
**	l'interface de jeu principale
*/
void	apply_color_game(t_pr *arg)
{
  arg->color = arg->buffer[4] - 48;
  if (arg->color == 1)
    init_pair(1, COLOR_RED, COLOR_BLACK);
  else if (arg->color == 2)
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
  else if (arg->color == 3)
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  else if (arg->color == 4)
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
  else if (arg->color == 5)
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
  else if (arg->color == 6)
    init_pair(6, COLOR_CYAN, COLOR_BLACK);
  else
    init_pair(7, COLOR_WHITE, COLOR_BLACK);
  wattron(arg->tetris_game, COLOR_PAIR(arg->color) | A_REVERSE);
}
