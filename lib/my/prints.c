/*
** prints.c for my_printf in /home/detroy_j/delivery/printf
** 
** Made by jean-baptiste detroyes
** Login   <detroy_j@epitech.net>
** 
** Started on  Sun Nov 20 15:09:22 2016 jean-baptiste detroyes
** Last update Tue Nov 29 15:49:24 2016 detroy_j
*/

int	my_putstr_s(char *str)
{
  int	i;
  int	len;

  i = len = 0;
  while (str[i] != 0)
    {
      if (str[i] < 32 || str[i] > 126)
	{
	  len += my_putchar_r(92);
	  if (str[i] < 8)
	    len += my_putchar_r('0');
	  if (str[i] < 64)
	    len += my_putchar_r('0');
	  len += my_putnbrbase_r(str[i], "01234567", 0);
	}
      else
	len += my_putchar_r(str[i]);
      i++;
    }
  return (len);
}

int	prints(char *str, int flag, int width)
{
  char	padchar;
  int	tmp;
  int	i;

  i = tmp = 0;
  padchar = ' ';
  if (width > 0)
    {
      while (str[i++] != '\0')
	tmp++;
      if (tmp >= width)
	width = 0;
      else
	width -= tmp;
    }
  tmp = 0;
  while (width-- > 0 && flag != 1)
    tmp += my_putchar_r(padchar);
  while (*str != '\0')
    tmp += my_putchar_r(*str++);
  while (width-- >= 0 && flag == 1)
    tmp += my_putchar_r(padchar);
  return (tmp);
}

int	printi(int nb, int flag, int width)
{
  char	padchar;
  int	tmp;
  int	i;

  i = tmp = 0;
  padchar = ' ';
  if (width > 0)
    {
      tmp = sizeof(nb);
      if (tmp >= width)
	width = 0;
      else
	width -= tmp - 1;
      if (flag == 5)
	padchar = '0';
    }
  tmp = 0;
  while (width-- > 0 && flag != 1)
    tmp += my_putchar_r(padchar);
  tmp += my_put_nbr_r(nb, 0);
  while (width-- >= 0 && flag == 1)
    tmp += my_putchar_r(padchar);
  return (tmp);
}

int	print_prefix_base(char *b)
{
  int	len;

  len = 0;
  if (my_strcmp(b, "01234567") == 0)
    len += my_putchar_r('0');
  else if (my_strcmp(b, "0123456789abcdef") == 0)
    len += my_putstr_r("0x");
  else if (my_strcmp(b, "0123456789ABCDEF") == 0)
    len += my_putstr_r("0X");
  return (len);
}

int	printb(unsigned int nb, char *b, int flag, int width)
{
  char	padchar;
  int	tmp;
  int	i;

  i = tmp = 0;
  padchar = ' ';
  (flag == 4 && my_strlen(b) == 8) ? width-- : 0;
  (flag == 4 && my_strlen(b) == 16) ? width -= 2 : 0;
  if (width > 0)
    {
      tmp = my_putnbrbase_nb(nb, b, 0);
      if (tmp >= width)
	width = 0;
      else
	width -= tmp;
      (flag == 5) ? padchar = '0' : 0;
    }
  tmp = 0;
  while (width-- > 0 && flag != 1)
    tmp += my_putchar_r(padchar);
  (flag == 4) ? print_prefix_base(b) : 0;
  tmp += my_putnbrbase_r(nb, b, 0);
  while (width-- >= 0 && flag == 1)
    tmp += my_putchar_r(padchar);
  return (tmp);
}
