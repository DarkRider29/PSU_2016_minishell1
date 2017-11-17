/*
** misc.c for minishell1 in /home/detroy_j/Documents/delivery/PSU_2016_minishell1
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Wed Jan 11 21:41:34 2017 detroy_j
** Last update Sun Jan 22 21:55:43 2017 detroy_j
*/

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include "my.h"
#include "minishell.h"

char	 *concatenate_path(char *path, char *cmd)
{
  size_t        i;
  size_t        j;
  char  *result;

  i = my_strlen(path) + my_strlen(cmd);
  if ((result = malloc(sizeof(char) * (i + 2))) == NULL)
    exit(84);
  i = j = 0;
  while (path[i] != 0)
    result[j++] = path[i++];
  result[j++] = '/';
  i = 0;
  while (cmd[i] != 0)
    result[j++] = cmd[i++];
  result[j] = '\0';
  return (result);
}

int	count_words(char *str)
{
  int   words;
  int   i;
  int   l;

  words = l = i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '\t' || str[i] == ' ')
	{
	  if (l == 1)
	    words++;
	  l = 0;
	}
      else
	l = 1;
      i++;
    }
  if (l == 1)
    words++;
  return (words);
}

int	has_slah(char *str)
{
  int   i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] == '/')
	return (1);
      i++;
    }
  return (0);
}

int	my_putstr_error(t_shell *shell, char *s1, char *s2, int value)
{
  shell->value = value;
  if (s1 != NULL)
    {
      my_putstr(s1);
      my_putstr(": ");
    }
  my_putstr(s2);
  return (shell->value);
}

int	my_exceve_error(t_shell *shell, int error)
{
  if (error == 0)
    return (shell->value = 0);
  else if (error == 1)
    return (my_putstr_error(shell, shell->cmd[0], CMD_NOT_FOUND, 1));
  else if (error == 2)
    return (my_putstr_error(shell, shell->cmd[0], BIN_ERROR, 1));
  return (0);
}
