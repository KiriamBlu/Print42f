
#include "ft_printf.h"

int print_char(char c, int len)
{
	write(1, &c, 1);
	len = len + 1; 
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
		len = len + 1;
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
	}
	len = len + i;
	free(str);
	return (len);
}

int printvoid(void *str, int len, int type)
{
	unsigned long int aux;
	char 	*aux2;

	aux2 = NULL;
	aux = (unsigned long int)str;
	if(type == 0 || type == 1)
		aux2 = itoa_hexa(aux, "0123456789abcdefg");
	else if(type == 2)
		aux2 = itoa_hexa(aux, "0123456789ABCDEFG");
	if (aux2 && type == 0)
	{
		write(1, "0x", 2);
		len = len + 2;
	}
	len = print_freeze(aux2, len);
	return (len);
}
