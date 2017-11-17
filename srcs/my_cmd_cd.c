/*
** my_cmd_cd.c for minishell1 in /home/detroy_j/Documents/delivery/PSU_2016_minishell1
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.net>
** 
** Started on  Mon Jan 16 11:45:07 2017 detroy_j
** Last update Sat Jan 28 18:28:14 2017 detroy_j
*/

#include <dirent.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include "my.h"
#include "minishell.h"

static int	my_cmd_cd_undo(t_shell *shell, char *str, char **envp)
{
  char	*pwd;
  char	*oldpwd;

  oldpwd = my_getenv(envp, "OLDPWD");
  pwd = my_getenv(envp, "PWD");
  (is_env_exist(shell, "PWD")) ? edit_env(shell, "PWD", str) :
    add_to_list(shell, "PWD", str);
  (is_env_exist(shell, "OLDPWD")) ? edit_env(shell, "OLDPWD", pwd) :
    add_to_list(shell, "OLDPWD", pwd);
  if (oldpwd == NULL)
    return (shell->value =0);
  if (access(oldpwd, F_OK) == -1 || access(str, R_OK) == -1
      || chdir(str) == -1)
    {
      (oldpwd != NULL) ? free(oldpwd) : 0;
      (pwd != NULL) ? free(pwd) : 0;
      return (shell->value = 1);
    }
  else
    {
      (oldpwd != NULL) ? free(oldpwd) : 0;
      (pwd != NULL) ? free(pwd) : 0;
    }
  return (shell->value = 0);
}

static int	my_cmd_cd_only(t_shell *shell, char **envp)
{
  char	*pwd;
  char	*e_pwd;

  pwd = my_getenv(envp, "HOME");
  if (pwd == NULL)
    return (shell->value = 0);
  if (access(pwd, F_OK) == -1 || access(pwd, R_OK) == -1
      || chdir(pwd) == -1)
    {
      free(pwd);
      return (my_putstr_error(shell, shell->cmd[0], NO_FILE, 1));
    }
  if (is_env_exist(shell, "OLDPWD"))
    {
      (is_env_exist(shell, "PWD")) ? e_pwd = my_getenv(envp, "PWD") : 0;
      edit_env(shell, "OLDPWD", e_pwd);
      free(e_pwd);
    }
  else
    add_to_list(shell, "OLDPWD", pwd);
  (is_env_exist(shell, "PWD")) ? edit_env(shell, "PWD", pwd)
    : add_to_list(shell, "PWD", pwd);
  free(pwd);
  return (shell->value = 1);
}

static int	my_cmd_cd_dir(t_shell *shell, char **envp, char *pwd)
{
  char	*e_pwd;

  if (is_env_exist(shell, "OLDPWD"))
    {
      if (is_env_exist(shell, "PWD"))
	{
	  e_pwd = my_getenv(envp, "PWD");
	  edit_env(shell, "OLDPWD", e_pwd);
	}
      else
	edit_env(shell, "OLDPWD", pwd);
    }
  else
    {
      if (is_env_exist(shell, "PWD"))
	{
	  e_pwd = my_getenv(envp, "PWD");
	  add_to_list(shell, "OLDPWD", e_pwd);
	}
      else
	add_to_list(shell, "OLDPWD", pwd);
    }
  (e_pwd != NULL) ? free(e_pwd) : 0;
  return (0);
}

static int	my_cmd_cd_dir_ex(t_shell *shell, char **envp)
{
  char	buffer[READ_SIZE_CWD + 1];
  char	*pwd;

  if ((pwd = getcwd(buffer, READ_SIZE_CWD)) == NULL)
    return (shell->value = 1);
  my_cmd_cd_dir(shell, envp, pwd);
  (is_env_exist(shell, "PWD")) ? edit_env(shell, "PWD", pwd)
    : add_to_list(shell, "PWD", pwd);
  return (shell->value = 0);
}

int	 my_cmd_cd(t_shell *shell, char **envp)
{
  DIR	*rep;

  if (shell->cmd[1] == NULL)
    return (my_cmd_cd_only(shell, envp));
  else if (shell->cmd[2] != NULL)
    return (my_putstr_error(shell, "cd", ERROR_ENV_3, 1));
  else
    {
      if (my_strcmp(shell->cmd[1], "-") == 0)
	return (my_cmd_cd_undo(shell, my_getenv(envp, "OLDPWD"), envp));
      if (access(shell->cmd[1], F_OK) == -1
	  || access(shell->cmd[1], R_OK) == -1)
	return (my_putstr_error(shell, shell->cmd[1], NO_FILE, 1));
      if ((rep = opendir(shell->cmd[1])) == NULL || chdir(shell->cmd[1]) == -1)
	return (my_putstr_error(shell, shell->cmd[1], NO_DIR, 1));
      else
	return (my_cmd_cd_dir_ex(shell, envp));
    }
  return (shell->value = 0);
}
