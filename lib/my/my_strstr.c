/*
** my_strstr.c for emcas in /home/detroy_j/delivery/CPool_Day06
** 
** Made by jean-baptiste detroyes
** Login   <detroy_j@epitech.net>
** 
** Started on  Mon Oct 10 14:21:09 2016 jean-baptiste detroyes
** Last update Mon Oct 10 21:12:41 2016 jean-baptiste detroyes
*/

char	*my_strstr(char *str, char *to_find)
{
  int	i;
  int	j;
  int	k;

  i = 0;
  j = 0;
  k = 0;
  while (to_find[j] != '\0')
    j++;
  while (str[i] != '\0')
    {
      if (str[i] == to_find[k])
	{
	  k++;
	  if (to_find[k] == '\0')
	    {
	      str += i + 1 - k;
	      return (str);
	    }
	}
      else
	k = 0;
      i++;
    }
  return (0);
}
