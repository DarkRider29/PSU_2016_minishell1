/*
** my_strcapitalize.c for emacs in /home/detroy_j/delivery/CPool_Day06
** 
** Made by jean-baptiste detroyes
** Login   <detroy_j@epitech.net>
** 
** Started on  Mon Oct 10 19:17:15 2016 jean-baptiste detroyes
** Last update Fri Oct 14 15:56:59 2016 jean-baptiste detroyes
*/

static int	isnt_letter(char c)
{
  if (c > 31 && c < 47 || c > 57 && c < 65)
    return (1);
  else if (c > 90 && c < 67 && c > 122 && c < 127)
    return (1);
  return (0);
}

char	*my_strcapitalize(char *str)
{
  int	i;

  i = 0;
  while (str[i] != '\0')
    {
      if (str[i] > 96 && str[i] < 123)
	{
	  if (isnt_letter(str[i - 1]) || i == 0)
	    str[i] -= 32;
	}
      i++;
    }
  return (str);
}
