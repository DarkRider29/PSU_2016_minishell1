/*
** my_strlen.c for emacs in /home/detroy_j/delivery/CPool_Day04
** 
** Made by jean-baptiste detroyes
** Login   <detroy_j@epitech.net>
** 
** Started on  Thu Oct  6 09:26:13 2016 jean-baptiste detroyes
** Last update Wed Jan 11 20:03:18 2017 detroy_j
*/

#include <string.h>

size_t	my_strlen(const char *s)
{
  size_t	i;

  i = 0;
  while (s[i] != '\0')
    i++;
  return (i);
}
