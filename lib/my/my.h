/*
** my.h for EXERCICE 2 in /home/munoz_d/rendu/Piscine_C_J09
**
** Made by munoz david
** Login   <munoz_d@epitech.net>
**
** Started on  Fri Oct  9 13:51:01 2015 munoz david
** Last update Thu Mar 17 10:19:05 2016 David Munoz
*/

#ifndef _VA_LIST_DEFINED
#ifdef _M_CEE_PURE
typedef System::ArgIterator va_list;
#else
typedef char *  va_list;
#endif
#define _VA_LIST_DEFINED
#endif

# ifndef READ_SIZE
# define READ_SIZE (300)
# endif /* !READ_SIZE */

#ifndef MY_H_
# define MY_H_

/*
**	Librairie de base
*/
void	my_sort_int_tab(int *tab, int size);
void	my_putchar(char c);
int	my_strlcat(char *dest, char *src, int size);
int	my_strncmp(char *s1, char *s2, int nb);
int	*my_showmem(char *str, int size);
int	my_power_rec(int nb, int power);
int	my_strcmp(char *s1, char *s2);
int	my_str_isprintable(char *str);
int	my_str_isalpha(char *str);
int	my_str_islower(char *str);
int	my_find_prime_sup(int nb);
int	my_str_isupper(char *str);
int	my_is_prime(int nombre);
int	my_str_isnum(char *str);
int	my_square_root(int nb);
int	my_showstr(char *str);
int	my_strlen (char *str);
int	my_getnbr(char *str);
int	my_putstr(char *str);
int	my_put_nbr(int nbr);
int	my_isneg(int nb);
int	my_swap(int *a, int *b);
char	*my_strncat(char *dest, char *src, int nb);
char	*my_strncpy(char *dest, char *src, int nb);
char	*my_strstr(char *str, char *to_find);
char	*my_strcat(char *dest, char *src);
char	*my_strcpy(char *dest, char *src);
char	*my_strcapitalize(char *str);
char	*my_strlowcase(char *str);
char	*my_strupcase(char *str);
char	*my_revstr(char *str);

/*
**	Printf
*/
void	flags(void (*flag[12])(va_list ap));
void	my_put_base(int nb, char *base);
void	my_printf_octal(int nb);
void	min_hexa(va_list ap);
void	maj_hexa(va_list ap);
void	charact(va_list ap);
void	unsign(va_list ap);
void	hexa_p(va_list ap);
void	maj_s(va_list ap);
void	octal(va_list ap);
void	my_S(char *str);
void	str(va_list ap);
void	bin(va_list ap);
void	nbr(va_list ap);
void	percent();
int	my_adresse(int nb, char *base);
int	end_line (char *str, int a);
int	my_printf(char *str, ...);
int	my_put_unsign(int nb);
int	zero(unsigned int nb);


/*
**	Getnextline
*/
int     my_gnl_read(char *buffer, const int fd, int *i);
char    *my_gnl_strcpy(char *source, char c, int lenght_line);
char    *my_gnl_error(char *line, int i, int lenght_read, int lenght_line);
char    *get_next_line(const int fd);


#endif /* !MY_H_ */
