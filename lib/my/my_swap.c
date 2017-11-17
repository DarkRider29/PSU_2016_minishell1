/*
** my_swap.c for emacs in /home/detroy_j/delivery/CPool_Day04
** 
** Made by jean-baptiste detroyes
** Login   <detroy_j@epitech.net>
** 
** Started on  Thu Oct  6 08:41:55 2016 jean-baptiste detroyes
** Last update Fri Oct  7 23:09:04 2016 jean-baptiste detroyes
*/

int	my_swap(int *a, int *b)
{
  int	c;

  c = *a;
  *a = *b;
  *b = c;
}
