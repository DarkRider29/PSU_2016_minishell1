/*
** my.h for emacs in /home/detroy_j/delivery/CPool_Day09/include
** 
** Made by jean-baptiste detroyes
** Login   <detroy_j@epitech.net>
** 
** Started on  Thu Oct 13 08:22:12 2016 jean-baptiste detroyes
** Last update Sun Jan 22 21:09:03 2017 detroy_j
*/

#ifndef MY_H
#define MY_H

int	my_putchar(char c);
int	my_isneg(int nb);
int	my_put_nbr(int nb);
int	my_swap(int *a, int *b);
int	my_putstr(const char *str);
size_t	my_strlen(const char *s);
int	my_getnbr(char *str);
void	my_sort_int_tab(int *tab, int size);
int	my_power_rec(int nb, int power);
int	my_square_root(int nb);
int	my_is_prime(int nb);
int	my_find_prime_sup(int nb);
char	*my_strcpy(char *dest, char *src);
char	*my_strncpy(char *dest, const char *src, size_t n);
char	*my_revstr(char *str);
char	*my_strstr(char *str, char *to_find);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strupcase(char *str);
char	*my_strlowcase(char *str);
char	*my_strcapitalize(char *str);
int	my_str_isalpha(char *str);
int	my_str_isnum(char *str);
int	my_str_islower(char *str);
int	my_str_isupper(char *str);
int	my_str_isprintable(char *str);
char    *my_strsep(char **stringp, const char *delim);
char    *my_strdup(const char *s);
int	my_showstr(char *str);
int	my_showmem(char *str, int size);
char	*my_strcat(char *dest, const char *src);
char	*my_strncat(char *dest, const char *src, size_t n);
char	*get_next_line(const int fd);
int     *my_malloc(int *p);
int     my_putchar_r(char c);
int     my_putstr_r(char *str);
int     my_put_nbr_r(int nb, int len);
int     my_putnbrbase_r(unsigned int nbr, char *base, int len);
int     my_putnbrbase_nb(unsigned int nbr, char *base, int len);
int     my_putstr_s(char *str);
int     my_putp(void *p);
int     prints(char *str, int flag, int width);
int     printi(int nb, int flag, int width);
int     printb(unsigned int nb, char *b, int flag, int width);
int     is_flag(char c);
int     is_indicator(char c);
int	my_printf(const char *format, ...);

#endif
