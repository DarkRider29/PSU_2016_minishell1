/*
** my_str_isnum.c for emacs in /home/detroy_j/delivery/CPool_Day06
** 
** Made by jean-baptiste detroyes
** Login   <detroy_j@epitech.net>
** 
** Started on  Mon Oct 10 19:39:19 2016 jean-baptiste detroyes
** Last update Mon Oct 10 21:19:35 2016 jean-baptiste detroyes
*/

int	my_str_isnum(char *str)
{
  int	i;

  i = 0;
  if (str[0] == '\0')
    return (1);
  while (str[i] != '\0')
    {
      if (str[i] < 48 || str[i] > 57)
	return (0);
      i++;
    }
  return (1);
}
