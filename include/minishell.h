/*
** minishell.h for minishell1 in /home/detroy_j/Documents/delivery/PSU_2016_minishell1/include
** 
** Made by detroy_j
** Login   <jean-baptiste.detroyes@epitech.net>
** 
** Started on  Sat Jan  7 17:01:58 2017 detroy_j
** Last update Sun Jan 22 22:05:34 2017 detroy_j
*/

#include <signal.h>

# ifndef READ_SIZE_CWD
#  define READ_SIZE_CWD (256)
# endif

# ifndef _MINISHELL_
#  define _MINISHELL_

# define NO_FILE "No such file or directory.\n"
# define NO_DIR "Not a directory.\n"
# define CMD_NOT_FOUND "Command not found.\n"
# define PERM_DENIED "Permission denied.\n"
# define EXEC_ERROR "Exec format error. Binary file not executable.\n"
# define BIN_ERROR "Exec format error. Binary file not executable.\n"
# define UNSETENV "unsetenv"
# define ERROR_UNSETENV "Too few arguments.\n"
# define SETENV "setenv"
# define ERROR_ENV_1 "Variable name must begin with a letter.\n"
# define ERROR_ENV_2 "Variable name must contain alphanumeric characters.\n"
# define ERROR_ENV_3 "Too many arguments.\n"

typedef struct	s_var t_var;
struct s_var
{
  char	*name;
  char	*content;
  t_var	*next;
  t_var	*prev;
};

typedef struct s_shell t_shell;
struct s_shell
{
  pid_t	pid;
  char	**cmd;
  char	*path;
  int	value;
  t_var	*first;
  t_var	*last;
};

int     my_exceve_error(t_shell *shell, int error);
int     my_execve(t_shell *shell, char **envp);
int     my_execve_ex(t_shell *shell);
int     my_fork(t_shell *shell);
int     is_env_exist(t_shell *shell, char *name);
void    edit_env(t_shell *shell, char *name, char *content);
void    add_to_list(t_shell *shell, char *name, char *content);
char    *concatenate_var(t_var *var);
char    **env_list_arr(t_shell *shell);
int     my_putstr_error(t_shell *shell, char *s1, char *s2, int value);
int     has_slah(char *str);
int     my_cmd_unsetenv(t_shell *shell);
int     my_cmd_setenv(t_shell *shell);
int      my_cmd_cd(t_shell *shell, char **envp);
char    **env_list_arr(t_shell *shell);
int     is_env_exist(t_shell *shell, char *name);
void    edit_env(t_shell *shell, char *name, char *content);
void    add_to_list(t_shell *shell, char *name, char *content);
void    env_arr_to_list(t_shell *shell, char **envp);
void    show_list_env(t_shell *shell);
void    remove_env_to_list(t_shell *shell, t_var *var);
int     count_words(char *str);
void    show_sh(char **envp);
char    *concatenate_path(char *path, char *cmd);
char	*my_getenv(char **envp, const char *elem);

# endif
