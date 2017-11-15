/*
** end_of_game.c for  in /PSU_2015_tetris/src/interface
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Wed Mar 16 14:59:17 2016 David Munoz
** Last update Tue Mar 22 13:51:42 2016 David Munoz
*/

#include "my.h"
#include "my_tetris.h"

/*
**      Affiche les informations lor de la fin du jeu
*/
void	print_end_info(t_sco *sco)
{
  char	buff[256];

  mvwprintw(sco->print_info, 1, 1, "You lost at level : %d", sco->level);
  mvwprintw(sco->print_info, 3, 1, "The high score is %d", sco->hi_sc);
  mvwprintw(sco->print_info, 5, 1, "Your score is %d", sco->sc);
  mvwprintw(sco->print_info, 7, 1, "You did %d lines", sco->lines);
  mvwprintw(sco->print_info, 9, 3, "Press any key");
  mvwprintw(sco->print_info, 10, 5, "to exit");
  box(sco->print_info, ACS_VLINE, ACS_HLINE);
  wrefresh(sco->print_info);
  sleep(2);
  while (read(0, buff, 255) <= 0);
  error_to_exit(GREEN"Exit succes\n"BLANK, 1);
}
