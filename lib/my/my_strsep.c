/*
** my_strsep.c for my_strsep.c in /home/detroy_j/Documents/delivery/PSU_2016_minishell1
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Wed Jan 11 15:38:34 2017 detroy_j
** Last update Wed Jan 11 20:24:57 2017 detroy_j
*/

#include <string.h>

static int	is_delimiter(char c, const char *delim)
{
  int	i;

  i = 0;
  while (delim[i] != '\0')
    {
      if (c == delim[i])
	return (1);
      i++;
    }
  return (0);
}

char	*my_strsep(char **stringp, const char *delim)
{
  char	*token;
  int	i;

  if (*stringp == NULL)
    return (NULL);
  i = 0;
  token = *stringp;
  while ((*stringp)[i] != '\0')
    {
      if (is_delimiter((*stringp)[i], delim))
	{
	  *stringp = *(stringp) + i + 1;
	  (*stringp)[-1] = 0;
	  return (token);
	}
      i++;
    }
  *stringp = NULL;
  return (token);
}
