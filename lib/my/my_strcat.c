/*
** my_strcat.c for emacs in /home/detroy_j/delivery/lib
** 
** Made by jean-baptiste detroyes
** Login   <detroy_j@epitech.net>
** 
** Started on  Tue Oct 11 10:55:34 2016 jean-baptiste detroyes
** Last update Thu Jan 12 18:47:02 2017 detroy_j
*/

#include <stdlib.h>
#include <string.h>

size_t	my_strlen(const char *s);

char	*my_strcat(char *dest, const char *src)
{
  size_t	len;
  size_t	len2;
  size_t	i;
  size_t	j;
  char	*tmp;

  len = my_strlen(dest);
  len2 = my_strlen(src);
  if ((tmp = malloc(sizeof(char) * (len + len2 + 2))) == NULL)
    return (NULL);
  i = j = 0;
  while (dest[i++] != '\0')
    tmp[i] = dest[i];
  while (src[j++] != '\0')
    tmp[i++] = src[j];
  tmp[i] = '\0';
  free(dest);
  return (tmp);
}
