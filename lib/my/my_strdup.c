/*
** my_strdup.c for my_strdup in /home/detroy_j/Documents/delivery/PSU_2016_minishell1
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Wed Jan 11 17:44:30 2017 detroy_j
** Last update Thu Jan 12 19:04:50 2017 detroy_j
*/

#include <stdlib.h>
#include <string.h>

size_t	my_strlen(const char *s);

char	*my_strdup(const char *s)
{
  char	*dest;
  size_t	len;
  size_t	i;

  i = 0;
  len = my_strlen(s);
  if ((dest = malloc(sizeof(char) * (len + 2))) == NULL)
    return (NULL);
  while (s[i] != '\0')
    {
      dest[i] = s[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
