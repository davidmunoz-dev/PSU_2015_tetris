/*
** my_str_isalpha.c for isalpha in /home/munoz_d/rendu/Piscine_C_J07/lib/my
**
** Made by munoz david
** Login   <munoz_d@epitech.net>
**
** Started on  Tue Oct  6 11:43:05 2015 munoz david
** Last update Tue Feb 23 14:28:52 2016 David Munoz
*/

int	my_str_isalpha(char *str)
{
  int	i;

  i = 0;
  if (str[i] == '\0')
    return (1);
  while (str[i] != '\0')
    {
      if ((str[i] < 65 || str[i] > 90) && (str[i] < 97 || str[i] > 122))
	return (0);
      i = i + 1;
    }
  return (1);
}
