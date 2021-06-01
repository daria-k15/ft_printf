#include "printf.h"

int	ft_num_u(unsigned int n, int base)
{
	int	i;

	i = 0;
	while (n > 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}
int	ft_num_int(int n, int base)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = n * (-1);
        i++;
	}
	while (n > 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}
char *ft_itoa(int n)
{
	int i;
	char *nbr;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 0)
		return (ft_strdup("0"));
	i = ft_num_int(n, 10);
	nbr = (char *)malloc(i + 1);
	if (!nbr)
		return (0);
	nbr[i] = '\0';
	i--;
    if (n < 0)
    {
        nbr[0] = '-';
        n = n * (-1);
    }
	while (n > 0)
    {
        nbr[i] = (n % 10) + '0';
        n /= 10;
        i--;
    }
	return (nbr);
}
char	*ft_itoa_u(unsigned int n)
{
	int		i;
	char	*res;
	
	if (n == 0)
		return (ft_strdup("0"));
	i = ft_num_u(n, 10);
	res = (char *)malloc(i + 1);
	if (!res)
		return (NULL);
	res[i] = '\0';
	i--;
	if (n < 0)
	{
		res[0] = '-';
		n = n * (-1);
	}
	while (n > 0)
	{
		res[i] = (n % 10) + '0';
		n = n / 10;
		i--;
	}
	return (res);
}
char	*ft_itoa_base_u(unsigned int n, int base, t_specif spec)
{
	int i;
	char *nbr;

	if (n == 0)
		return (ft_strdup("0"));
	i = ft_num_u(n, base);
	nbr = (char *)malloc(i + 1);
	if (!nbr)
		return (0);
	nbr[i] = '\0';
	i--;
	if (n < 0)
	{
		nbr[0] = '-';
		n = n * (-1);
	}
	while (n > 0)
	{
		if (spec.type == 'x')
		{
			if (n % base > 9)
				nbr[i] = (n % base) + 'a' - 10;
			else
				nbr[i] = (n % base) + '0';
		}
		else
		{
			if (n % base > 9)
				nbr[i] = (n % base) + 'A' - 10;
			else
				nbr[i] = (n % base) + '0';
		}
		n /= base;
		i--;
	}
	return (nbr);
}
