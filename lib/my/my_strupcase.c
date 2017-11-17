/*
** my_strupcase.c for emcas in /home/detroy_j/delivery/CPool_Day06
** 
** Made by jean-baptiste detroyes
** Login   <detroy_j@epitech.net>
** 
** Started on  Mon Oct 10 17:41:32 2016 jean-baptiste detroyes
** Last update Mon Oct 10 21:14:37 2016 jean-baptiste detroyes
*/

char	*my_strupcase(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] > 96 && str[i] < 123)
	str[i] -= 32;
      i++;
    }
  return (str);
}
