/*
** interface_print_info.c for c in /rendu_Tetris/test/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Wed Mar  2 00:25:57 2016 David Munoz
** Last update Thu Mar 17 18:19:30 2016 David Munoz
*/

#include "my.h"
#include "my_tetris.h"

/*
**	Affiche le score
*/
void	print_score(t_sco *sco)
{
  mvwprintw(sco->print_info, 1, 13, "%d", sco->hi_sc);
  mvwprintw(sco->print_info, 3, 8, "%d", sco->sc);
  mvwprintw(sco->print_info, 5, 8, "%d", sco->lines);
  mvwprintw(sco->print_info, 7, 8, "%d", sco->level);
}

/*
**	Met le score à jour
*/
void	update_score(t_sco *sco)
{
  sco->sc = sco->sc + 10;
  if (sco->sc >= sco->hi_sc)
    sco->hi_sc = sco->sc;
}

/*
**	Fonction principale du score
*/
void	print_info_IG(t_sco *sco)
{
  print_score(sco);
  start_info_tetris(sco);
  wrefresh(sco->print_info);
  wclear(sco->print_info);
}

/*
** Initalise l'affichage du score
*/
void	start_info_tetris(t_sco *sco)
{
  sco->print_info = subwin(stdscr, 13, 25, 10, 2);
  mvwprintw(sco->print_info, 1, 1, "High score:");
  mvwprintw(sco->print_info, 3, 1, "Score:");
  mvwprintw(sco->print_info, 5, 1, "Lines:");
  mvwprintw(sco->print_info, 7, 1, "Level:");
  mvwprintw(sco->print_info, 11, 1, "EpiTetris (c) - 2016");
  box(sco->print_info, ACS_VLINE, ACS_HLINE);
}
