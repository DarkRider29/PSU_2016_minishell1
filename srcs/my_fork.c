/*
** my_fork.c for minishell1 in /home/detroy_j/Documents/delivery/PSU_2016_minishell1
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Sat Jan 21 20:41:28 2017 detroy_j
** Last update Sun Jan 22 20:49:48 2017 detroy_j
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

static int	get_return_value(t_shell *shell, int wt)
{
  (WIFEXITED(wt)) ? shell->value = WEXITSTATUS(wt) : 0;
  if (WIFSIGNALED(wt))
    {
      (WTERMSIG(wt) == SIGHUP) ? my_putstr("Hangup") : 0;
      (WTERMSIG(wt) == SIGTRAP) ? my_putstr("Trace/BPT trap") : 0;
      (WTERMSIG(wt) == SIGSEGV) ? my_putstr("Segmentation fault") : 0;
      (WTERMSIG(wt) == SIGFPE) ? my_putstr("Floating exception") : 0;
      (WTERMSIG(wt) == SIGBUS) ? my_putstr("Error bus") : 0;
      (WTERMSIG(wt) == SIGQUIT) ? my_putstr("Quit") : 0;
      (WTERMSIG(wt) == SIGILL) ? my_putstr("Illegal instruction") : 0;
      (WTERMSIG(wt) == SIGABRT || WTERMSIG(wt) == SIGIOT) ? my_putstr("Abort")
	: 0;
      (WTERMSIG(wt) == SIGKILL) ? my_putstr("Killed") : 0;
      (WTERMSIG(wt) == SIGUSR1) ? my_putstr("User signal 1") : 0;
      (WTERMSIG(wt) == SIGUSR2) ? my_putstr("User signal 2") : 0;
      (WTERMSIG(wt) == SIGPIPE) ? my_putstr("Broken pipe") : 0;
      (WTERMSIG(wt) == SIGALRM) ? my_putstr("Alarm clock") : 0;
      (WTERMSIG(wt) == SIGTERM) ? my_putstr("Terminated") : 0;
      (WTERMSIG(wt) == SIGSTKFLT) ? my_putstr("Stack limit exceeded") : 0;
      (WTERMSIG(wt) == SIGSTOP) ? my_putstr("Suspended (signal)") : 0;
      (WTERMSIG(wt) == SIGXFSZ) ? my_putstr("Filesize limit exceeded") : 0;
      (WCOREDUMP(wt)) ? my_putstr(" (core dumped)\n") : my_putstr("\n");
      shell->value = wt;
    }
  return (shell->value);
}

int	my_execve_ex(t_shell *shell)
{
  if (shell->cmd[0] == NULL)
    return (shell->value = 0);
  if (my_strcmp(shell->cmd[0], "exit") == 0)
    {
      if (shell->cmd[1] != NULL)
	exit(my_getnbr(shell->cmd[1]));
      exit(shell->value);
    }
  else if (my_strcmp(shell->cmd[0], "unsetenv") == 0)
    return (my_cmd_unsetenv(shell));
  else if (my_strcmp(shell->cmd[0], "setenv") == 0)
    return (my_cmd_setenv(shell));
  else if (my_strcmp(shell->cmd[0], "cd") == 0
	  || my_strcmp(shell->cmd[0], "chdir") == 0)
    return (my_cmd_cd(shell, env_list_arr(shell)));
  my_fork(shell);
  return (shell->value);
}

int	my_fork(t_shell *shell)
{
  int   wt;

  shell->pid = fork();
  if (shell->pid == -1)
    return (shell->value = 1);
  if (shell->pid == 0)
    {
      if (!(shell->value = my_execve(shell, env_list_arr(shell))))
	exit(shell->value);
      else
	exit(shell->value);
      if (my_strcmp(shell->cmd[0], "exit") == 0)
	return (shell->value);
    }
  if (shell->pid > 0)
    {
      waitpid(shell->pid, &wt, 0);
      get_return_value(shell, wt);
    }
  return (shell->value);
}
