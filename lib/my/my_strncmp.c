/*
** my_strncmp.c for emcas in /home/detroy_j/delivery/CPool_Day06
** 
** Made by jean-baptiste detroyes
** Login   <detroy_j@epitech.net>
** 
** Started on  Mon Oct 10 17:24:31 2016 jean-baptiste detroyes
** Last update Mon Oct 10 21:14:03 2016 jean-baptiste detroyes
*/

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && i < n)
    {
      if (s1[i] > s2[i])
	return (s1[i] - s2[i]);
      else if (s2[i] > s1[i])
	return (s1[i] - s2[i]);
      else
	i++;
    }
  return (0);
}
