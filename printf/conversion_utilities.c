#include "ft_printf.h"

char *itoa(int n, int sgn)
{
	char	*str;
	size_t		i;
	unsigned int l;
	int	sign;

	sign = 0;
	l = n;
	if (sgn == 1 && n < 0)
	{
		sign = 1;
		l = n * -1;
	}
	i = len(l, sign);
	str = (char *)malloc(i * sizeof(char)+ 1); 
	str[i--] = '\0';
	if (sign == 1)
		str[0] = '-';
	while (i > 0 && l >= 10)
	{
		str[i--] = (l % 10) + '0';
		l = l / 10;
	}
	str[i] = l + '0';
	return (str);
}

char *itoa_hexa(unsigned long int n, char *base, int type)
{
	unsigned long int i;
	char *str;

	if (type == 0)
		i = lenlonghexa(n);
	else
		i = unsignedlenhexa((unsigned int)n);
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

size_t len(unsigned int n, int sign)
{
	size_t i;

	i = 0;
	if (n == 0)
		return(1);
	if (sign == 1)
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

unsigned long int lenlonghexa(unsigned long int n)
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
unsigned int unsignedlenhexa(unsigned int n)
{
	unsigned int i;

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
