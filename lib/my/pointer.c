/*
** pointer.c for my_printf in /home/detroy_j/delivery/printf
** 
** Made by jean-baptiste detroyes
** Login   <detroy_j@epitech.net>
** 
** Started on  Sun Nov 20 17:13:22 2016 jean-baptiste detroyes
** Last update Tue Nov 29 15:50:39 2016 detroy_j
*/

#include <stdlib.h>

int	*my_malloc(int *p)
{
  p = malloc(sizeof(int));
  if (p == NULL)
    return (NULL);
  return (p);
}

int	my_putnbr_pointer(unsigned long int nbr, char *base, int len)
{
  unsigned long int	mod;
  unsigned long int	start;
  int	size;

  size = my_strlen(base);
  if (nbr < 0)
    {
      len += my_putchar_r('-');
      len += my_putnbr_pointer(-nbr, base, len);
    }
  else
    {
      mod = nbr % size;
      start = (nbr - mod) / size;
      if (start != 0)
	len += my_putnbr_pointer(start, base, len);
      len += my_putchar_r(base[mod]);
    }
  return (len);
}

int	my_putp(void *p)
{
  int	len;

  len = 0;
  len += my_putchar_r('0');
  len += my_putchar_r('x');
  len += my_putnbr_pointer((unsigned long int) p, "0123456789abcdef", 0);
  return (len);
}
