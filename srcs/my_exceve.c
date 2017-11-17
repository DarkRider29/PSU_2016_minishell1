/*
** my_exceve.c for minishell1 in /home/detroy_j/Documents/delivery/PSU_2016_minishell1
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Sat Jan 21 20:46:29 2017 detroy_j
** Last update Sun Jan 22 22:00:54 2017 detroy_j
*/

#include <sys/stat.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include "my.h"
#include "minishell.h"

static int	my_exceve_path(t_shell *shell, char **envp, int e)
{
  char  *path;
  char  *result;

  e = 0;
  if ((path = my_getenv(envp, "PATH")) == NULL)
    return (shell->value = 1);
  while ((result = my_strsep(&path, ":")) != NULL)
    {
      if (shell->cmd[0][0] == '/' || shell->cmd[0][0] == '.')
	continue;
      result = concatenate_path(result, shell->cmd[0]);
      if (access(result, F_OK) == -1 || access(result, X_OK) == -1)
	{
	  e = 1;
	  continue;
	}
      if (execve(result, shell->cmd, envp) == -1)
	{
	  e = 2;
	  break;
	}
      e = 0;
      break;
    }
  return (my_exceve_error(shell, e));
}

static int	check_cmd1(t_shell *shell, char **envp)
{
  if (shell->cmd[0][0] == '/')
    {
      if (access(shell->cmd[0], F_OK) == -1)
	return (my_putstr_error(shell, shell->cmd[0], CMD_NOT_FOUND, 1));
      if (access(shell->cmd[0], X_OK) == -1)
	return (my_putstr_error(shell, shell->cmd[0], PERM_DENIED, 1));
      if (execve(shell->cmd[0], shell->cmd, envp) == -1)
	return (my_putstr_error(shell, shell->cmd[0], EXEC_ERROR, 1));
      return (shell->value = 0);
    }
  return (-1);
}

static int	check_cmd2(t_shell *shell, char **envp)
{
  char	*result;

  if (shell->cmd[0][0] == '.' &&
      shell->cmd[0][1] == '/' && shell->cmd[0][1] != '\0')
    {
      if (access(shell->cmd[0], F_OK) == -1)
	return (my_putstr_error(shell, shell->cmd[0], CMD_NOT_FOUND, 1));
      if (access(shell->cmd[0], X_OK) == -1)
	return (my_putstr_error(shell, shell->cmd[0], PERM_DENIED, 1));
      result = concatenate_path(my_getenv(envp, "PWD"), shell->cmd[0] + 2);
      if (execve(result, shell->cmd, envp) == -1)
	return (my_putstr_error(shell, shell->cmd[0], EXEC_ERROR, 1));
      return (shell->value = 0);
    }
  return (-1);
}

static int	check_cmd3(t_shell *shell, char **envp)
{
  if (access(shell->cmd[0], F_OK) != -1 && access(shell->cmd[0], X_OK) != -1)
    {
      if (has_slah(shell->cmd[0]))
	{
	  if (execve(shell->cmd[0], shell->cmd, envp) == -1)
	    return (my_putstr_error(shell, shell->cmd[0], EXEC_ERROR, 1));
	  return (shell->value = 0);
	}
    }
  return (-1);
}

int	my_execve(t_shell *shell, char **envp)
{
  struct stat   sb;

  if (stat(shell->cmd[0], &sb) > -1)
    {
      if (S_ISDIR(sb.st_mode) &&
	  (shell->cmd[0][0] == '.' || shell->cmd[0][0] == '/'))
	return (my_putstr_error(shell, shell->cmd[0], PERM_DENIED, 1));
    }
  if (check_cmd1(shell, envp) != -1)
    return (shell->value);
  else
    {
      if (check_cmd2(shell, envp) != -1)
	return (shell->value);
      else
	{
	  if (check_cmd3(shell, envp) != -1)
	    return (shell->value);
	}
    }
  return (my_exceve_path(shell, envp, 0));
}
