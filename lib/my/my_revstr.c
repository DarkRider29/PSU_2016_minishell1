/*
** my_revstr.c for emcas in /home/detroy_j/delivery/CPool_Day06
** 
** Made by jean-baptiste detroyes
** Login   <detroy_j@epitech.net>
** 
** Started on  Mon Oct 10 12:47:28 2016 jean-baptiste detroyes
** Last update Mon Oct 10 13:36:14 2016 jean-baptiste detroyes
*/

char	*my_revstr(char *str)
{
  int	i;
  int	j;
  int	k;
  char	a;

  i = 0;
  while (str[i] != '\0')
    i++;
  j = 0;
  k = (i / 2);
  while (k > 0)
    {
      a = str[j];
      str[j] = str[i - 1];
      str[i - 1] = a;
      j++;
      i--;
      k--;
    }
  return (str);
}
