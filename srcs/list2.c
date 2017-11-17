/*
** list2.c for minishell1 in /home/detroy_j/Documents/delivery/PSU_2016_minishell1
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.eu@epitech.net>
** 
** Started on  Sat Jan 21 19:59:52 2017 detroy_j
** Last update Sat Jan 21 20:02:40 2017 detroy_j
*/

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include "my.h"
#include "minishell.h"

int	is_env_exist(t_shell *shell, char *name)
{
  t_var *now;

  now = shell->first;
  while (now != NULL)
    {
      if (my_strcmp(now->name, name) == 0)
	return (1);
      now = now->next;
    }
  return (0);
}

void	edit_env(t_shell *shell, char *name, char *content)
{
  t_var *now;

  now = shell->first;
  while (now != NULL)
    {
      if (my_strcmp(now->name, name) == 0 && now->name != NULL)
	{
	  if (now->content != NULL)
	    free(now->content);
	  now->content = my_strdup(content);
	  break;
	}
      now = now->next;
    }
}

void	add_to_list(t_shell *shell, char *name, char *content)
{
  t_var *new;

  if ((new = malloc(sizeof(*new))) == NULL)
    exit(84);
  new->name = my_strdup(name);
  if (content != NULL)
    new->content = my_strdup(content);
  else
    new->content = NULL;
  new->next = NULL;
  new->prev = shell->last;
  if (shell->last)
    shell->last->next = new;
  else
    shell->first = new;
  shell->last = new;
}

char	*concatenate_var(t_var *var)
{
  char  *result;
  size_t        len;
  size_t        i;
  size_t        j;

  i = j = 0;
  len = my_strlen(var->name) + my_strlen(var->content) + 1;
  if ((result = malloc(sizeof(char) * (len + 1))) == NULL)
    exit(84);
  while (var->name[j] != '\0')
    result[i++] = var->name[j++];
  result[i++] = '=';
  j = 0;
  while (var->content[j] != '\0')
    result[i++] = var->content[j++];
  result[i] = '\0';
  return (result);
}

char	**env_list_arr(t_shell *shell)
{
  t_var *now;
  int   i;
  int   j;
  char  **arr;

  i = j = 0;
  now = shell->first;
  while (now != NULL)
    {
      now = now->next;
      i++;
    }
  if ((arr = malloc(sizeof(char *) * (i + 2))) == NULL)
    exit(84);
  now = shell->first;
  while (j < i)
    {
      arr[j] = concatenate_var(now);
      now = now->next;
      j++;
    }
  arr[j] = NULL;
  return (arr);
}
