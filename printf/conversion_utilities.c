#include "ft_printf.h"

char *itoa(int n, int sgn)
{
	char	*str;
	size_t		i;
	unsigned int l;

	i = len(n, sgn);
	str = (char *)malloc(i * sizeof(char)+ 1); 
	if (!str)
		return (0);
	str[i--] = '\0';
	if (n < 0 && sgn == 1)
	{
		str[0] = '-';
		l = n * -1;
	}
	else
		l = n;
	while (i > 0 && l >= 10)
	{
		str[i] = (l % 10) + '0';
		l = l / 10;
		i--;
	}
	str[i] = l + '0';
	return (str);
}

char *itoa_hexa(unsigned long int n, char *base)
{
	unsigned long int i;
	char *str;

	i = lenhexa(n);
	str = (char *)malloc (i * sizeof(char) + 1);
	if (!str)
		return (0);
	str[i--] = '\0';
	while (i > 0 && n > 15)
	{
		str[i] = base[n % 16];
		n = n / 16;
		i--;
	}
	str[i--] = base[n % 16];
	return (str);
}

size_t len(int n, int sign)
{
	size_t i;

	i = 0;
	if (n == 0)
		return(1);
	if (n < 0 && sign == 1)
		i = 1;
	{
		while (n != 0)
		{
			n = n / 10;
			i++;
		}
	}
	return (i);
}

unsigned long int lenhexa(unsigned long int n)
{
	unsigned long int i;

	i = 0;
	if (n == 0)
		return(1);
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return(i);
}
