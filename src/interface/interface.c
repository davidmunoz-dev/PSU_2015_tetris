/*
** interface.c for c in /PSU_2015_tetris/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Mon Feb 22 14:02:44 2016 David Munoz
** Last update Tue Mar 22 13:52:07 2016 David Munoz
*/

#include "my.h"
#include "my_tetris.h"

/*
**  Affiche un cadre autour du jeu TETRIS
*/
void	my_cadre()
{
  int   i;

  i = 1;
  clear();
  while (i < LINES - 1)
    {
      mvprintw(i, 1, "|");
      mvprintw(i, COLS - 1, "|");
      ++i;
    }
  i = 3;
  while (i < COLS - 2)
    {
      mvprintw(LINES - 1, i, "_");
      mvprintw(0, i, "_");
      ++i;
    }
  mvprintw(0, 1, ".");
  mvprintw(LINES - 1, 1, ".");
  mvprintw(LINES - 1, COLS - 1, ".");
  mvprintw(0, COLS - 1, ".");
  mvprintw(0, ((COLS / 2) - 6), "[TETRIS]");
}

/*
**	Check quand est ce que le tetris doit s'arreter
*/
int	check_end_of_game(t_pr *arg)
{
  int	i;

  i = 1;
  while (arg->tab[1][i] != '\0')
    {
      if (arg->tab[1][i] != '-' && arg->tab[1][i] != '\n')
	return (1);
      i++;
    }
  return (0);
}

/*
**  Boucle principale du jeu complet
*/
void	loop_game(t_pr *arg, t_struct *st, t_sco *sco)
{
  int	check_eog;

  keypad(stdscr, TRUE);
  getch();
  while (check_eog == 0)
    {
      check_eog = check_end_of_game(arg);
      print_info_IG(sco);
      next_tetriminos(arg, st, sco);
      print_tetrimino_IG(arg, st, sco);
      update_score(sco);
      check_maxyx();
    }
}

/*
** Initialisation de la structure du jeu
*/
void	init_struct_of_game(t_pr *arg, t_sco *sco, t_struct *st)
{
  sco->sc = 0;
  sco->hi_sc = 0;
  sco->lines = 0;
  sco->tour = 0;
  sco->a_rand = 0;
  sco->row = st->row;
  sco->col = st->col;
  arg->c = 0;
  sco->level = st->level;
  curs_set(0);
  noecho();
}

/*
**  Regroupe l'interface du jeu en une fonction
*/
void	interface(t_struct *st)
{
  t_pr	*arg;
  t_sco	*sco;

  if ((arg = malloc(sizeof(t_pr))) == 0)
    error_to_exit(GREEN"Exit succes\n"BLANK, 1);
  if ((sco = malloc(sizeof(t_sco))) == 0)
    error_to_exit(GREEN"Exit succes\n"BLANK, 1);
  init_struct_of_game(arg, sco, st);
  check_maxyx();
  check_has_color();
  start_color();
  my_cadre();
  start_print_TETRIS(arg);
  start_next(arg);
  start_interface_tetris(arg);
  start_info_tetris(sco);
  my_init_tab(arg);
  loop_game(arg, st, sco);
  print_end_info(sco);
}
