/*
** my_getnbr.c for emacs in /home/detroy_j/delivery/lib
** 
** Made by jean-baptiste detroyes
** Login   <detroy_j@epitech.net>
** 
** Started on  Tue Oct 11 08:40:06 2016 jean-baptiste detroyes
** Last update Wed Jan 11 20:09:31 2017 detroy_j
*/

int	my_getnbr(char *str)
{
  int   neg;
  int   nb;

  neg = 1;
  nb = 0;
  while (*str == '-' || *str == '+')
    {
      if (*str == '-')
	neg = - neg;
      str++;
    }
  while (*str != '\0' && *str >= '0' && *str <= '9')
    {
      if (nb > 214748364 || (nb == 214748364 && *str > 7 && neg == 1))
	return (0);
      if (nb == 214748364 && *str > 8 && neg == -1)
	return (0);
      nb = nb * 10 + *str - 48;
      str++;
    }
  if (neg == -1)
    nb = nb * (-1);
  return (nb);
}
