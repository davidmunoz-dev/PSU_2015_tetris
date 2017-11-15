/*
** tab_options.c for tab_options in /home/durand_4/rendu/systeme_unix/PSU_2015_tetris/src/options
** 
** Made by loic durand
** Login   <durand_4@epitech.net>
** 
** Started on  Thu Mar  3 15:57:49 2016 loic durand
** Last update Thu Mar 17 17:36:37 2016 loic durand
*/

#include "my.h"
#include "my_tetris.h"

void	options_list(char *arg, t_struct *st)
{
  void (*option_list[3])(t_struct *);
  void (*k_option_list[8])(char *, t_struct *);

  option_list[0] = help;
  option_list[1] = without_next;
  option_list[2] = debug;
  k_option_list[0] = level;
  k_option_list[1] = key_left;
  k_option_list[2] = key_right;
  k_option_list[3] = key_turn;
  k_option_list[4] = key_drop;
  k_option_list[5] = key_quit;
  k_option_list[6] = key_pause;
  k_option_list[7] = map_size;
  if (st->a >= 3 && st->a <= 10)
    k_option_list[st->a - 3](arg, st);
  else
    option_list[st->a](st);
}

void	tab_option_name(t_struct *st)
{
  st->option_name[0] = malloc(sizeof(char) * 6);
  st->option_name[0] = "--help";
  st->option_name[1] = malloc(sizeof(char) * 2);
  st->option_name[1] = "-w";
  st->option_name[2] = malloc(sizeof(char) * 2);
  st->option_name[2] = "-d";
  st->option_name[3] = malloc(sizeof(char) * 2);
  st->option_name[3] = "-l";
  st->option_name[4] = malloc(sizeof(char) * 3);
  st->option_name[4] = "-kl";
  st->option_name[5] = malloc(sizeof(char) * 3);
  st->option_name[5] = "-kr";
  st->option_name[6] = malloc(sizeof(char) * 3);
  st->option_name[6] = "-kt";
  st->option_name[7] = malloc(sizeof(char) * 3);
  st->option_name[7] = "-kd";
  st->option_name[8] = malloc(sizeof(char) * 3);
  st->option_name[8] = "-kq";
  st->option_name[9] = malloc(sizeof(char) * 3);
  st->option_name[9] = "-kp";
  tab_option_dname(st);
}

void	tab_option_dname(t_struct *st)
{
  st->option_name[10] = malloc(sizeof(char) * 14);
  st->option_name[10] = "--without-next";
  st->option_name[11] = malloc(sizeof(char) * 7);
  st->option_name[11] = "--debug";
  st->option_name[12] = malloc(sizeof(char) * 7);
  st->option_name[12] = "--level=";
  st->option_name[13] = malloc(sizeof(char) * 10);
  st->option_name[13] = "--key-left=";
  st->option_name[14] = malloc(sizeof(char) * 11);
  st->option_name[14] = "--key-right=";
  st->option_name[15] = malloc(sizeof(char) * 10);
  st->option_name[15] = "--key-turn=";
  st->option_name[16] = malloc(sizeof(char) * 10);
  st->option_name[16] = "--key-drop=";
  st->option_name[17] = malloc(sizeof(char) * 10);
  st->option_name[17] = "--key-quit=";
  st->option_name[18] = malloc(sizeof(char) * 11);
  st->option_name[18] = "--key-pause=";
  st->option_name[19] = malloc(sizeof(char) * 11);
  st->option_name[19] = "--map-size=";
}
