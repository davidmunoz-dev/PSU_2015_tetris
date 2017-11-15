/*
** help.c for help in /home/durand_4/rendu/systeme_unix/PSU_2015_tetris/src
** 
** Made by loic durand
** Login   <durand_4@epitech.net>
** 
** Started on  Mon Feb 22 13:33:46 2016 loic durand
** Last update Sun Mar 20 11:31:55 2016 loic durand
*/

#include "my.h"
#include "my_tetris.h"

void	help(t_struct *st)
{
  my_printf("Usage: %s [options]\nOptions:\n", st->binarie_name);
  my_putstr("--help\t\t\tDisplay this help\n");
  my_putstr("-l --level={num}\tStart Tetris at level num\n");
  my_putstr("-kl --key-left={K}\tMove tetrimino on LEFT with key K\n");
  my_putstr("-kr --key-right={K}\tMove tetrimino on RIGHT with key K\n");
  my_putstr("-kt --key-turn={K}\tTurn tetrimino with key K\n");
  my_putstr("-kd --key-drop={K}\tSet default DROP on key K\n");
  my_putstr("-kq --key-quit={K}\tQuit program when press key K\n");
  my_putstr("-kp --key-pause={K}\tPause and restart game when presse key K\n");
  my_putstr("--map-size={row,col}\tSet game size at row, col\n");
  my_putstr("-w --without-next\tHide next tetrimino\n");
  my_putstr("-d --debug\t\tDebug mode\n");
  free(st->binarie_name);
  exit (0);
}
