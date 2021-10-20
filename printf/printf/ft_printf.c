
#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int	len;
	size_t i;
	va_list args;

	va_start(args, str);
	len = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '%')
		{
			len = ft_translate(args, str[i + 1], len);
			i = i + 2;
		}
		else 
		{
			write(1, &str[i], 1);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

int ft_translate(va_list args, char c, int len)
{
	if (c == 'c')
		len = print_char(va_arg(args, int), len);
	else if (c == 's')
		len = print_str(va_arg(args, char *), len);
	else if (c == 'p')
		len = printvoid(va_arg(args, void *), len);
	else if (c == 'd' || c == 'i')
		len = print_freeze(itoa(va_arg(args, int), 1), len);
	else if (c == 'u')
		len = print_freeze(itoa(va_arg(args, unsigned int), 0), len);
	else if (c == 'x')
		len = print_freeze(itoa_hexa(va_arg(args, int),
			"0123456789abcdefg"), len);
	else if (c == 'X')
		len = print_freeze(itoa_hexa(va_arg(args, int), 
			"0123456789ABCDEFG"), len);
	else if (c == '%')
	{
		write(1, "%",1);
		len++;
	}
	return (len);
}
