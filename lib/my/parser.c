/*
** parser.c for my_printf in /home/detroy_j/delivery/printf
** 
** Made by jean-baptiste detroyes
** Login   <detroy_j@epitech.net>
** 
** Started on  Sun Nov 20 17:19:38 2016 jean-baptiste detroyes
** Last update Sun Nov 20 17:20:18 2016 jean-baptiste detroyes
*/

int     is_flag(char c)
{
  int   a;

  a = 0;
  (c == '-') ? a = 1 : 0;
  (c == '+') ? a = 2 : 0;
  (c == ' ') ? a = 3 : 0;
  (c == '#') ? a = 4 : 0;
  (c == '0') ? a = 5 : 0;
  return (a);
}

int     is_indicator(char c)
{
  int   a;

  (c == 'd' || c == 'i') ? a = 1 : 0;
  (c == 's') ? a = 2 : 0;
  (c == 'c') ? a = 3 : 0;
  (c == 'p') ? a = 4 : 0;
  (c == 'S') ? a = 5 : 0;
  (c == 'o') ? a = 6 : 0;
  (c == 'x') ? a = 7 : 0;
  (c == 'u') ? a = 8 : 0;
  (c == 'b') ? a = 9 : 0;
  (c == 'X') ? a = 10 : 0;
  return (a);
}
