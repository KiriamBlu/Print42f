#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int					ft_printf(const char *str, ...);
int					ft_translate(va_list args, char c, int len);
int					print_char(char c, int len);
int					print_str(char *str, int len);
int					print_freeze(char *str, int len);
int					printvoid(void *ptr, int len, int type);
size_t				len(unsigned int n, int sign);
char				*itoa(int n, int sign);
char				*itoa_hexa(unsigned long int n, char *base, int type);
unsigned long int	lenlonghexa(unsigned long int n);
unsigned int 		unsignedlenhexa(unsigned int n);


#endif