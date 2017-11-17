/*
** my_strlowcase.c for emacs in /home/detroy_j/delivery/CPool_Day06
** 
** Made by jean-baptiste detroyes
** Login   <detroy_j@epitech.net>
** 
** Started on  Mon Oct 10 17:49:31 2016 jean-baptiste detroyes
** Last update Wed Jan 11 20:16:34 2017 detroy_j
*/

#include <string.h>

char	*my_strlowcase(char *str)
{
  size_t	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] > 64 && str[i] < 91)
	str[i] += 32;
      i++;
    }
  return (str);
}
