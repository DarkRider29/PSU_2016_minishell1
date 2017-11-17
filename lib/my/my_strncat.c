/*
** my_strncat.c for emcas in /home/detroy_j/delivery/lib
** 
** Made by jean-baptiste detroyes
** Login   <detroy_j@epitech.net>
** 
** Started on  Tue Oct 11 10:57:24 2016 jean-baptiste detroyes
** Last update Wed Jan 11 20:23:29 2017 detroy_j
*/

#include <string.h>

size_t  my_strlen(const char *s);

char	*my_strncat(char *dest, const char *src, size_t n)
{
  size_t        len;
  size_t        i;

  len = my_strlen(dest);
  i = 0;
  while (src[i] && i < n)
    {
      dest[len + i] = src[i];
      i = i + 1;
    }
  dest[len + n + 1] = '\0';
  return (dest);
}
