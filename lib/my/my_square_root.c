/*
** my_square_root.c for emacs in /home/detroy_j/delivery/CPool_Day05
** 
** Made by jean-baptiste detroyes
** Login   <detroy_j@epitech.net>
** 
** Started on  Fri Oct  7 11:21:33 2016 jean-baptiste detroyes
** Last update Fri Oct  7 16:47:13 2016 jean-baptiste detroyes
*/

int	my_square_root(int nb)
{
  int	i;
  int	res;

  res = nb;
  if (nb < 0)
    return (0);
  i = 1;
  while (i * i <= nb)
    {
      if (i * i == nb)
	return i;
      i++;
      if (i * i > nb)
	return 0;
    }
  return (0);
}
