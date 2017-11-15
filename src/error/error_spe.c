/*
** error_spe.c for error_spe in /home/durand_4/rendu/systeme_unix/PSU_2015_tetris/src/error
** 
** Made by loic durand
** Login   <durand_4@epitech.net>
** 
** Started on  Sat Mar 19 15:50:25 2016 loic durand
** Last update Sat Mar 19 15:54:17 2016 loic durand
*/

#include "my.h"
#include "my_tetris.h"

void	error_help(t_struct *st)
{
  help(st);
  exit(1);
}
