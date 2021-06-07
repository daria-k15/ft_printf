/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 20:03:00 by heveline          #+#    #+#             */
/*   Updated: 2021/06/06 20:07:44 by heveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa(int n)
{
	int		i;
	char	*nbr;

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

char	*ft_itoa_base_uX(unsigned long long n, int base)
{
	int		i;
	char	*nbr;

	if (n == 0)
		return (ft_strdup("0"));
	i = ft_num_u(n, base);
	nbr = (char *)malloc(sizeof(char *) * i + 1);
	if (!nbr)
		return (0);
	nbr[i--] = '\0';
	if (n < 0)
	{
		nbr[0] = '-';
		n = n * (-1);
	}
	while (n > 0)
	{
		if (n % base > 9)
			nbr[i] = (n % base) + 'A' - 10;
		else
			nbr[i] = (n % base) + '0';
		n /= base;
		i--;
	}
	return (nbr);
}

char	*ft_itoa_base_ux(unsigned long long n, int base)
{
	int		i;
	char	*nbr;

	if (n == 0)
		return (ft_strdup("0"));
	i = ft_num_u(n, base);
	nbr = (char *)malloc(sizeof(char *) * i + 1);
	if (!nbr)
		return (0);
	nbr[i--] = '\0';
	if (n < 0)
	{
		nbr[0] = '-';
		n = n * (-1);
	}
	while (n > 0)
	{
		if (n % base > 9)
			nbr[i] = (n % base) + 'a' - 10;
		else
			nbr[i] = (n % base) + '0';
		n /= base;
		i--;
	}
	return (nbr);
}
