/*
** interface_print_tetris.c for  in /rendu_Tetris/test/src
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Tue Mar  1 23:54:43 2016 David Munoz
** Last update Sat Mar 19 16:53:57 2016 David Munoz
*/

#include "my.h"
#include "my_tetris.h"

/*
**	Affiche le 'T' en rouge(1) et le 'E'(4) en bleu
*/
void	print_TE(t_pr *arg)
{
  init_pair(1, COLOR_RED, COLOR_BLACK);
  wattron(arg->t_e_t_r_i_s, COLOR_PAIR(1) | A_REVERSE);
  mvwprintw(arg->t_e_t_r_i_s, 1, 1, "   ");
  mvwprintw(arg->t_e_t_r_i_s, 2, 2, " ");
  mvwprintw(arg->t_e_t_r_i_s, 3, 2, " ");
  mvwprintw(arg->t_e_t_r_i_s, 4, 2, " ");
  mvwprintw(arg->t_e_t_r_i_s, 5, 2, " ");
  wattroff(arg->t_e_t_r_i_s, COLOR_PAIR(1) | A_REVERSE);
  init_pair(4, COLOR_BLUE, COLOR_BLACK);
  wattron(arg->t_e_t_r_i_s, COLOR_PAIR(4) | A_REVERSE);
  mvwprintw(arg->t_e_t_r_i_s, 1, 5, "   ");
  mvwprintw(arg->t_e_t_r_i_s, 2, 5, " ");
  mvwprintw(arg->t_e_t_r_i_s, 3, 5, "   ");
  mvwprintw(arg->t_e_t_r_i_s, 4, 5, " ");
  mvwprintw(arg->t_e_t_r_i_s, 5, 5, "   ");
  wattroff(arg->t_e_t_r_i_s, COLOR_PAIR(4) | A_REVERSE);
}

/*
**	Affiche le 'T'(3) en jaune et le 'R'(6) en cyan
*/
void	print_TR(t_pr *arg)
{
  init_pair(3, COLOR_YELLOW, COLOR_BLACK);
  wattron(arg->t_e_t_r_i_s, COLOR_PAIR(3) | A_REVERSE);
  mvwprintw(arg->t_e_t_r_i_s, 1, 9, "   ");
  mvwprintw(arg->t_e_t_r_i_s, 2, 10, " ");
  mvwprintw(arg->t_e_t_r_i_s, 3, 10, " ");
  mvwprintw(arg->t_e_t_r_i_s, 4, 10, " ");
  mvwprintw(arg->t_e_t_r_i_s, 5, 10, " ");
  wattroff(arg->t_e_t_r_i_s, COLOR_PAIR(3) | A_REVERSE);
  init_pair(6, COLOR_CYAN, COLOR_BLACK);
  wattron(arg->t_e_t_r_i_s, COLOR_PAIR(6) | A_REVERSE);
  mvwprintw(arg->t_e_t_r_i_s, 1, 13, "    ");
  mvwprintw(arg->t_e_t_r_i_s, 2, 13, " ");
  mvwprintw(arg->t_e_t_r_i_s, 2, 16, " ");
  mvwprintw(arg->t_e_t_r_i_s, 3, 13, "    ");
  mvwprintw(arg->t_e_t_r_i_s, 4, 13, " ");
  mvwprintw(arg->t_e_t_r_i_s, 4, 15, " ");
  mvwprintw(arg->t_e_t_r_i_s, 5, 16, " ");
  mvwprintw(arg->t_e_t_r_i_s, 5, 13, " ");
  wattroff(arg->t_e_t_r_i_s, COLOR_PAIR(6) | A_REVERSE);
}

/*
**	Affiche le 'I' en vert(2) et le 'S' en magenta(5)
*/
void	print_IS(t_pr *arg)
{
  init_pair(2, COLOR_GREEN, COLOR_BLACK);
  wattron(arg->t_e_t_r_i_s, COLOR_PAIR(2) | A_REVERSE);
  mvwprintw(arg->t_e_t_r_i_s, 1, 18, " ");
  mvwprintw(arg->t_e_t_r_i_s, 2, 18, " ");
  mvwprintw(arg->t_e_t_r_i_s, 3, 18, " ");
  mvwprintw(arg->t_e_t_r_i_s, 4, 18, " ");
  mvwprintw(arg->t_e_t_r_i_s, 5, 18, " ");
  wattroff(arg->t_e_t_r_i_s, COLOR_PAIR(2) | A_REVERSE);
  init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
  wattron(arg->t_e_t_r_i_s, COLOR_PAIR(5) | A_REVERSE);
  mvwprintw(arg->t_e_t_r_i_s, 1, 20, "    ");
  mvwprintw(arg->t_e_t_r_i_s, 2, 20, " ");
  mvwprintw(arg->t_e_t_r_i_s, 3, 20, "    ");
  mvwprintw(arg->t_e_t_r_i_s, 4, 23, " ");
  mvwprintw(arg->t_e_t_r_i_s, 5, 20, "    ");
  wattroff(arg->t_e_t_r_i_s, COLOR_PAIR(5) | A_REVERSE);
}

/*
**	Creer une fenêtre comme titre "TETRIS" en couleur
*/
void	start_print_TETRIS(t_pr *arg)
{
  arg->t_e_t_r_i_s = subwin(stdscr, 7, 25, 2, 2);
  print_TE(arg);
  print_TR(arg);
  print_IS(arg);
  wrefresh(arg->t_e_t_r_i_s);
  box(arg->t_e_t_r_i_s, ACS_VLINE, ACS_HLINE);
}
