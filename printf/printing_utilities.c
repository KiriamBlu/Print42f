
#include "ft_printf.h"

int print_char(char c, int len)
{
	if (!c)
	{
		write(1, "(null)", 6);
		return (len + 6);
	}
	write(1, &c, 1);
	len++; 
	return (len); 
}

int print_str(char *str, int len)
{
	int i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (len + 6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		len++;
	}
	return (len);
}

int print_freeze(char *str, int len)
{
	int i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (len + 6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
		len++;
	}
	free(str);
	return (len);
}

int print_void(void *str, int len)
{
	unsigned long int aux;
	char 	*aux2;
	int i;

	aux = (unsigned long int)str;
	aux2 = itoa_hexa(aux, "0123456789abcdefg");
	if (aux2)
	{
		write(1, "0x", 2);
		len = len + 2;
	}
	print_str2(aux2, len);
	return (len);
}
