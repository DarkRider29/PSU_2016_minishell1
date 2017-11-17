/*
** my_strcpy.c for emcas in /home/detroy_j/delivery/CPool_Day06
** 
** Made by jean-baptiste detroyes
** Login   <detroy_j@epitech.net>
** 
** Started on  Mon Oct 10 07:52:30 2016 jean-baptiste detroyes
** Last update Wed Jan 11 20:33:01 2017 detroy_j
*/

#include <string.h>

size_t  my_strlen(const char *s);

char	*my_strcpy(char *dest, char *src)
{
  size_t	i;
  size_t	k;

  i = my_strlen(src);
  k = 0;
  while (k < i)
    {
      dest[k] = src[k];
      k++;
    }
  dest[k] = '\0';
  return (dest);
}
