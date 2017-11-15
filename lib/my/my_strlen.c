/*
** my_strlen.c for Exercice 4 in /home/munoz_d/rendu/Piscine_C_J04
** 
** Made by munoz david
** Login   <munoz_d@epitech.net>
** 
** Started on  Thu Oct  1 16:25:25 2015 munoz david
** Last update Thu Oct 22 14:07:48 2015 munoz david
*/

int	my_strlen (char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      i = i + 1;
    }
  return (i);
}
