/*
** my_strncpy.c for emcas in /home/detroy_j/delivery/CPool_Day06
** 
** Made by jean-baptiste detroyes
** Login   <detroy_j@epitech.net>
** 
** Started on  Mon Oct 10 11:27:30 2016 jean-baptiste detroyes
** Last update Wed Jan 11 20:17:54 2017 detroy_j
*/

#include <string.h>

char	*my_strncpy(char *dest, const char *src, size_t n)
{
  size_t	i;
  size_t	j;

  i = 0;
  while (src[i] != '\0')
    i++;
  if (n > i)
    n = i;
  j = 0;
  while (j < n)
    {
      if (j < i)
	dest[j] = src[j];
      j++;
    }
  return (dest);
}
