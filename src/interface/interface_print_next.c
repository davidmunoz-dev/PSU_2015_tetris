/*
** interface_print_next.c for  in /rendu_Tetris/test/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Wed Mar  2 00:11:15 2016 David Munoz
** Last update Sat Mar 19 16:53:45 2016 David Munoz
*/

#include "my.h"
#include "my_tetris.h"

/*
** Verifie les open et read de NEXT
*/
int	check_open_read(char *file, t_pr *arg)
{
  int	fd;

  if ((arg->bfnext = malloc(50)) == 0)
    error_to_exit("Error : Malloc failed", 1);
  if ((fd = open(file, O_RDONLY)) <= 0)
    error_to_exit("Error : Open failed\n", 1);
  if (read(fd, arg->bfnext, 500) <= 0)
    error_to_exit("Error : Read failed\n", 1);
  return (fd);
}

/*
**  Principale fonction de l'affichage du prochain tetris
*/
void	print_next_tetrimino(t_pr *arg, char *file)
{
  int	fd;

  arg->a_n = 6;
  arg->x_n = arg->y_n = 4;
  fd = check_open_read(file, arg);
  while (arg->bfnext[arg->a_n] == '*' ||
	 arg->bfnext[arg->a_n] == '\n' || arg->bfnext[arg->a_n]==' ')
    {
      if (arg->bfnext[arg->a_n] == '\n')
	{
	  arg->y_n++;
	  arg->x_n = 4;
	}
      else if (arg->bfnext[arg->a_n] == '*')
	tetrimino_reverse(arg);
      else if (arg->bfnext[arg->a_n] == ' ')
	mvwprintw(arg->print_next, arg->y_n, arg->x_n++, " ");
      arg->a_n++;
    }
  close(fd);
}

/*
** Affiche un tetrimino en reverse
*/
void	tetrimino_reverse(t_pr *arg)
{
  apply_color_next(arg);
  mvwprintw(arg->print_next, arg->y_n, arg->x_n++, " ");
  wattroff(arg->print_next, COLOR_PAIR(arg->color_next) | A_REVERSE);
}

/*
**  Affiche le prochain tetrimino
*/
void	next_tetriminos(t_pr *arg, t_struct *st, t_sco *sco)
{
  int	a;

  start_next(arg);
  if (sco->tour == 0)
    {
      a = random_first_tetrimino(0, st->nb_tet - 1);
      stock_first_tetrimino(arg, st->list[a]);
    }
  else if (sco->tour > 0)
    stock_first_tetrimino(arg, st->list[sco->a_rand]);
  sco->a_rand = random_tetrimino(0, st->nb_tet - 1);
  print_next_tetrimino(arg, st->list[sco->a_rand]);
  wrefresh(arg->print_next);
  wclear(arg->print_next);
  sco->tour = sco->tour + 1;
}

/*
**  Creer la fenêtre "NEXT"
*/
void	start_next(t_pr *arg)
{
  arg->print_next = subwin(stdscr, 10, 12, 2, 41);
  mvwprintw(arg->print_next, 1, 4, "NEXT");
  box(arg->print_next, ACS_VLINE, ACS_HLINE);
}
