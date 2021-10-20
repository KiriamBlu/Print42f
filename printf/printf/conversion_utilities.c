#include "ft_printf.h"

char *itoa(int n, int sgn)
{
	char	*str;
	size_t		i;

	i = len(n, 10);
	str = (char *)malloc(i * sizeof(char)+ 1); 
	if (!str)
		return (NULL);
	str[i--] = '\0';
	if (n < 0 && sgn == 1)
	{
		str[0] = '-';
		n *= -1;
	}
	while (i > 0 && n > 9)
	{
		str[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	str[i] = n + '0';
	return (str);
}

char *itoa_hexa(unsigned long int n, char *base)
{
	size_t i;
	char *str;

	i = len(n, 16);
	str = (char *)malloc (i * sizeof(char) + 1);
	if (!str)
		return (NULL);
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

size_t len(int n, int ifhex)
{
	size_t i;

	i = 0;
	if (n < 0)
		i = 1;
	if (ifhex == 10)
	{
		while (n != 0)
		{
			n = n / 10;
			i++;
		}
	}
	else if (ifhex == 16)
	{
		while (n != 0)
		{
			n = n / 16;
			i++;
		}
	}
	return (i);
}
