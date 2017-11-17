/*
** my_power_rec.c for emacs in /home/detroy_j/delivery/CPool_Day05
** 
** Made by jean-baptiste detroyes
** Login   <detroy_j@epitech.net>
** 
** Started on  Fri Oct  7 09:55:24 2016 jean-baptiste detroyes
** Last update Fri Oct  7 16:46:25 2016 jean-baptiste detroyes
*/

int	my_power_rec(int nb, int p)
{
  int	res;

  res = 0;
  if (p < 0)
    return (0);
  if (p == 0)
    return (1);
  res += nb * my_power_rec(nb, p - 1);
  return (res);
}
