/*
** list.c for minishell1 in /home/detroy_j/Documents/delivery/PSU_2016_minishell1
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Wed Jan 11 22:27:05 2017 detroy_j
** Last update Sat Jan 21 20:58:28 2017 detroy_j
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include "my.h"
#include "minishell.h"

void	add_to_list_end(t_shell *shell, char *env)
{
  t_var	*new;
  char	*tmp;

  if ((new = malloc(sizeof(*new))) == NULL)
    exit(84);
  if (!env)
    return ;
  tmp = my_strdup(env);
  new->name = my_strdup(my_strsep(&tmp, "="));
  new->content = my_strdup(my_strsep(&tmp, "\t"));
  new->next = NULL;
  new->prev = shell->last;
  if (shell->last)
    shell->last->next = new;
  else
    shell->first = new;
  shell->last = new;
}

void	show_list_env(t_shell *shell)
{
  t_var	*now;

  now = shell->first;
  while (now != NULL)
    {
      if (now->name != NULL)
	my_putstr(now->name);
      my_putchar('=');
      if (now->content != NULL)
	my_putstr(now->content);
      my_putchar('\n');
      now = now->next;
    }
}

void	remove_env_to_list(t_shell *shell, t_var *var)
{
  if (shell->first == var)
    {
      if (var->next)
	shell->first = var->next;
      else
	shell->first = NULL;
    }
  if (shell->last == var)
    {
      if (var->prev)
	shell->last = var->prev;
      else
	shell->last = NULL;
    }
  if (var->prev != NULL)
    var->prev->next = var->next;
  if (var->next != NULL)
    var->next->prev = var->prev;
  free(var->name);
  free(var->content);
  free(var);
}

void	env_arr_to_list(t_shell *shell, char **envp)
{
  int	i;

  shell->first = NULL;
  shell->last = NULL;
  i = 0;
  while (envp[i] != '\0' && envp[i] != NULL)
    {
      add_to_list_end(shell, envp[i]);
      i++;
    }
}
