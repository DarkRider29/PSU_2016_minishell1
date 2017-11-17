/*
** my_printf.c for my_printf in /home/detroy_j/delivery/my_printf
** 
** Made by jean-baptiste detroyes
** Login   <detroy_j@epitech.net>
** 
** Started on  Mon Nov  7 10:02:05 2016 jean-baptiste detroyes
** Last update Tue Nov 29 15:48:52 2016 detroy_j
*/

#include <stdarg.h>

int	write_print(va_list args, int type, int flag, int width)
{
  int	len;

  len = 0;
  (type == 1) ? len += printi(va_arg(args, int), flag, width) : 0;
  (type == 2) ? len += prints(va_arg(args, char *), flag, width) : 0;
  (type == 3) ? len += my_putchar_r(va_arg(args, unsigned int)) : 0;
  (type == 4) ? len += my_putp(va_arg(args, void *)) : 0;
  (type == 5) ? len += my_putstr_s(va_arg(args, char *)) : 0;
  if (type == 6)
    len += printb(va_arg(args, unsigned int), "01234567", flag, width);
  if (type == 7)
    len += printb(va_arg(args, unsigned int), "0123456789abcdef", flag, width);
  if (type == 8)
    len += printb(va_arg(args, unsigned int), "0123456789", flag, width);
  if (type == 9)
    len += printb(va_arg(args, unsigned int), "01", flag, width);
  if (type == 10)
    len += printb(va_arg(args, unsigned int), "0123456789ABCDEF", flag, width);
  return (len);
}

int	check_first(const char *str, int i, int *len)
{
  if (str[i] == '%')
    {
      *len += my_putchar_r('%');
      i++;
    }
  else if (str[i] == 'n')
    {
      *len += my_put_nbr_r(*len, 0);
      i++;
    }
  else
    return (0);
  return (i);
}

int	check_arg(const char *str, int i, va_list args, int *len)
{
  int	flag;
  int	width;
  int	tmp;

  flag = width  = 0;
  tmp = i;
  (is_flag(str[i]) > 0) ? (flag = is_flag(str[i])) && (i++) : 0;
  while (str[i] >= '0' && str[i] <= '9')
    {
      width *= 10;
      width += str[i] - 48;
      i++;
    }
  if (is_indicator(str[i]) > 0)
    *len += write_print(args, is_indicator(str[i]), flag, width);
  else
    {
      i = tmp - 1;
      *len += my_putchar_r('%');
    }
  return (i);
}

int	my_printf(const char *format, ...)
{
  va_list args;
  int	i;
  int	*len;

  len = my_malloc(len);
  i = *len = 0;
  va_start(args, format);
  while (format[i] != '\0')
    {
      if (format[i] == '%')
	{
	  i++;
	  if (check_first(format, i, len))
	    {
	      i = check_first(format, i, len);
	      continue;
	    }
	  i = check_arg(format, i, args, len);
	}
      else
	*len += my_putchar_r(format[i]);
      i++;
    }
  va_end(args);
  return (*len);
}
