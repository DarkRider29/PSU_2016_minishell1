/*
** main.c for minishell1 in /home/detroy_j/Documents/delivery/PSU_2016_minishell1
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Sat Jan  7 15:21:29 2017 detroy_j
** Last update Thu Jan 26 23:16:54 2017 detroy_j
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

void	get_cmd(t_shell *shell, char *str)
{
  char	*result;
  int	i;

  i = count_words(str);
  if ((shell->cmd = malloc(sizeof(char *) * (i + 1))) == NULL)
    exit(84);
  shell->cmd[i] = NULL;
  i = 0;
  while ((result = my_strsep(&str, " \t")) && result != NULL)
    {
      if (*result != '\0')
	{
	  shell->cmd[i] = my_strdup(result);
	  i++;
	}
    }
}

int	my_prompt(t_shell *shell)
{
  char	*cmd;

  if (isatty(0))
    {
      while (42)
	{
	  my_putstr("$> ");
	  if ((cmd = get_next_line(0)) == NULL)
	    break;
	  get_cmd(shell, cmd);
	  shell->value = my_execve_ex(shell);
	}
    }
  else
    {
      while ((cmd = get_next_line(0)) != NULL)
	{
	  get_cmd(shell, cmd);
	  shell->value = my_execve_ex(shell);
	}
    }
  return (shell->value);
}

int	main(int argc, char * argv[], char * envp[])
{
  t_shell	*shell;
  char	*pwd;
  char	buffer[READ_SIZE_CWD + 1];

  if (argc > 1 || argv[0] == NULL)
    exit(84);
  if ((shell = malloc(sizeof(*shell))) == NULL)
    exit(84);
  if (envp != NULL)
    env_arr_to_list(shell, envp);
  else
    {
      if ((pwd = getcwd(buffer, READ_SIZE_CWD)) != NULL)
	{
	  add_to_list(shell, "PWD", pwd);
	  free(pwd);
	}
    }
  shell->value = my_prompt(shell);
  return (shell->value);
}
