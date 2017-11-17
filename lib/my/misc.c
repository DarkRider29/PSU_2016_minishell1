/*
** misc.c for my_printf in /home/detroy_j/delivery/printf
** 
** Made by jean-baptiste detroyes
** Login   <detroy_j@epitech.net>
** 
** Started on  Sat Nov 19 18:11:43 2016 jean-baptiste detroyes
** Last update Tue Nov 29 15:49:05 2016 detroy_j
*/

#include <unistd.h>

int	my_putchar_r(char c)
{
  write(1, &c, 1);
  return (1);
}

int	my_putstr_r(char *str)
{
  int	len;

  len = 0;
  while (*str != '\0')
    {
      len += my_putchar_r(*str);
      *str++;
    }
  return (len);
}

int	my_put_nbr_r(int nb, int len)
{
  int	a;

  if (nb < 0)
    {
      len += my_putchar_r(45);
      nb = nb * (-1);
    }
  if (nb >= 0)
    {
      if (nb >= 10)
	{
	  a = (nb % 10);
	  nb = (nb - a) / 10;
	  len += my_put_nbr_r(nb, len);
	  len += my_putchar_r(48 + a);
	}
      else
	len += my_putchar_r(48 + nb);
    }
  return (len);
}

int	my_putnbrbase_r(unsigned int nbr, char *base, int len)
{
  int	mod;
  int	start;
  int	size;

  size = my_strlen(base);
  if (nbr < 0)
    {
      len += my_putchar_r('-');
      len += my_putnbrbase_r(-nbr, base, len);
    }
  else
    {
      mod = nbr % size;
      start = (nbr - mod) / size;
      if (start != 0)
	len += my_putnbrbase_r(start, base, len);
      len += my_putchar_r(base[mod]);
    }
  return (len);
}

int	my_putnbrbase_nb(unsigned int nbr, char *base, int len)
{
  int	mod;
  int	start;
  int	size;

  size = my_strlen(base);
  if (nbr < 0)
    {
      len++;
      len += my_putnbrbase_nb(-nbr, base, len);
    }
  else
    {
      mod = nbr % size;
      start = (nbr - mod) / size;
      if (start != 0)
	len += my_putnbrbase_nb(start, base, len);
      len++;
    }
  return (len);
}
