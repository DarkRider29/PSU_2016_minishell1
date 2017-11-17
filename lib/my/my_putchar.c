/*
** my_putchar.c for emcas in /home/detroy_j/lib/my
** 
** Made by jean-baptiste detroyes
** Login   <detroy_j@epitech.net>
** 
** Started on  Tue Oct 11 08:13:47 2016 jean-baptiste detroyes
** Last update Wed Jan 11 20:11:20 2017 detroy_j
*/

#include <unistd.h>

int	my_putchar(char c)
{
  write(1, &c, 1);
  return ((int) c);
}
