/*
** my_str_isprintable.c for emacs in /home/detroy_j/delivery/CPool_Day06
** 
** Made by jean-baptiste detroyes
** Login   <detroy_j@epitech.net>
** 
** Started on  Mon Oct 10 20:11:17 2016 jean-baptiste detroyes
** Last update Wed Jan 11 20:15:40 2017 detroy_j
*/

#include <string.h>

int	my_str_isprintable(char *str)
{
  size_t	i;

  i = 0;
  if (str[0] == '\0')
    return (1);
  while (str[i] != '\0')
    {
      if (str[i] < 32 || str[i] > 127)
	return (0);
      i++;
    }
  return (1);
}
