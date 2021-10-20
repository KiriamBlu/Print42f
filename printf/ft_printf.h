#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_translate(va_list args, char c, int len);
int		print_char(char c, int len);
int		print_str(char *str, int len);
int		print_freeze(char *str, int len);
int		printvoid(void *ptr, int len);
size_t	len(int n, int type);
char	*itoa(int n, int sign);
char	*itoa_hexa(unsigned long int n, char *base);

#endifma