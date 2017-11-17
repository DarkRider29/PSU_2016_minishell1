/*
** my_getenv.c for minishell1 in /home/detroy_j/Documents/delivery/PSU_2016_minishell1
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Sat Jan  7 17:20:27 2017 detroy_j
** Last update Sun Jan 22 20:51:53 2017 detroy_j
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "my.h"
#include "minishell.h"

static char	*my_get_env_result(char **envp, int i, int j)
{
  char  *result;
  int   len;
  int   k;

  k = 0;
  len = my_strlen(envp[i]) - j;
  if ((result = malloc(sizeof(char) * (len + 1))) == NULL)
    exit(84);
  while (envp[i][j] != '\0')
    {
      result[k] = envp[i][j];
      j++;
      k++;
    }
  result[k] = '\0';
  if (k == 0)
    return (NULL);
  return (result);
}

char	*my_getenv(char **envp, const char *elem)
{
  int   i;
  int   j;
  int   found;

  i = j = found = 0;
  while (envp[i++] != NULL)
    {
      while (envp[i][j] != '\0' && found == 0)
	{
	  if (envp[i][j] == elem[j])
	    {
	      j++;
	      continue;
	    }
	  else if (envp[i][j] == '=' && elem[j] == '\0')
	    found = 1;
	  else
	    j = 0;
	  break;
	}
      if (found == 1)
	break;
    }
  return ((found == 1) ? my_get_env_result(envp, i, j + 1) : NULL);
}
