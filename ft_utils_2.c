/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 19:51:27 by heveline          #+#    #+#             */
/*   Updated: 2021/06/06 19:57:50 by heveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	output(char *src, t_specif *spec)
{
	int	len;

	len = ft_strlen(src);
	if (!spec->flag_minus)
	{
		while (len++ < spec->width)
			spec->write_length += write (1, " ", 1);
	}
	spec->write_length += ft_putstr(src);
	if (spec->flag_minus)
	{
		while (len++ < spec->width)
			spec->write_length += write (1, " ", 1);
	}
}

void	prec_initialization(char **src, t_specif *spec)
{
	char	*new;
	int		i;
	int		len;

	i = 0;
	len = (int)ft_strlen(*src);
	if (spec->prec && spec->prec >= len)
	{
		if (**src == '-')
		{
			len--;
			new = (char *)malloc(sizeof(char) * spec->prec + 1);
			new[i++] = '-';
			ft_strcpy(&new[spec->prec - len], *src);
		}
		else
		{
			new = (char *)malloc(sizeof(char) * spec->prec);
			ft_strcpy(&new[spec->prec - len], *src);
		}
		while (len++ < spec->prec)
			new[i++] = '0';
		free(*src);
		*src = new;
	}
}

int	ft_num_u(unsigned long long n, int base)
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
