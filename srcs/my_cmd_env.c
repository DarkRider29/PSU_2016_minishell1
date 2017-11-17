/*
** my_cmd_env.c for minishell1 in /home/detroy_j/Documents/delivery/PSU_2016_minishell1
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Mon Jan 16 11:47:36 2017 detroy_j
** Last update Sun Jan 22 21:53:36 2017 detroy_j
*/

#include <string.h>
#include "my.h"
#include "minishell.h"

static int	unsetenv_all(t_shell *shell)
{
  t_var	*now;

  now = shell->first;
  while (now != NULL)
    {
      remove_env_to_list(shell, now);
      now = now->next;
    }
  return (shell->value = 0);
}

int	my_cmd_unsetenv(t_shell *shell)
{
  t_var *now;
  int	i;

  if (shell->cmd[1] == NULL)
    return (my_putstr_error(shell, UNSETENV, ERROR_UNSETENV, 1));
  i = 1;
  now = shell->first;
  while (shell->cmd[i] != NULL)
    {
      if (my_strcmp(shell->cmd[i], "*") == 0)
	return (unsetenv_all(shell));
      while (now != NULL)
	{
	  if (my_strcmp(now->name, shell->cmd[i]) == 0)
	    {
	      remove_env_to_list(shell, now);
	      break;
	    }
	  now = now->next;
	}
      i++;
      now = shell->first;
    }
  return (shell->value = 0);
}

static int	is_alphanumeric(const char *str)
{
  int	i;

  i = 0;
  while (str[i] != 0)
    {
      if (str[i] >= 48 && str[i] <= 57)
	i++;
      else if (str[i] >= 65 && str[i] <= 90)
	i++;
      else if (str[i] >= 97 && str[i] <= 122)
	i++;
      else if (str[i] == '_')
	i++;
      else
	return (0);
    }
  return (1);
}

static int	is_char_alphanumeric(const char c)
{
  if (c >= 65 && c <= 90)
    return (1);
  else if (c >= 97 && c <= 122)
    return (1);
  return (0);
}

int	my_cmd_setenv(t_shell *shell)
{
  if (shell->cmd[1] == NULL)
    {
      show_list_env(shell);
      return (shell->value = 0);
    }
  if (!is_char_alphanumeric(shell->cmd[1][0]))
    return (my_putstr_error(shell, SETENV, ERROR_ENV_1, 0));
  if (!is_alphanumeric(shell->cmd[1]))
    return (my_putstr_error(shell, SETENV, ERROR_ENV_2, 0));
  if (shell->cmd[3] != NULL && shell->cmd[2] != NULL)
    return (my_putstr_error(shell, SETENV, ERROR_ENV_3, 1));
  if (shell->cmd[2] == NULL)
    {
      (is_env_exist(shell, shell->cmd[1])) ?
	edit_env(shell, shell->cmd[1], "\0") :
	add_to_list(shell, shell->cmd[1], "\0");
    }
  else
    {
      (is_env_exist(shell, shell->cmd[1])) ?
	edit_env(shell, shell->cmd[1], shell->cmd[2]) :
	add_to_list(shell, shell->cmd[1], shell->cmd[2]);
    }
  return (shell->value = 0);
}
