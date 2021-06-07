/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 19:42:45 by heveline          #+#    #+#             */
/*   Updated: 2021/06/06 19:50:15 by heveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	find_flags(t_specif *spec, const char *src)
{
	int	i;

	i = 0;
	spec->flag_minus = 0;
	spec->flag_plus = 0;
	spec->flag_zero = 0;
	spec->flag_hash = 0;
	spec->flag_space = 0;
	while (is_flag(src[i]))
	{
		if (src[i] == '-')
			spec->flag_minus = 1;
		if (src[i] == '+')
			spec->flag_plus = 1;
		if (src[i] == '0')
			spec->flag_zero = 1;
		if (src[i] == '#')
			spec->flag_hash = 1;
		if (src[i] == ' ')
			spec->flag_space = 1;
		i++;
	}
}

int	find_prec(const char *src, va_list ap, t_specif *spec)
{
	int	i;
	int	prec;

	i = 0;
	while (src[i] && src[i] != spec->type && src[i] != '.')
		i++;
	if (src[i++] == '.')
	{
		if (src[i] == '*')
		{
			prec = va_arg(ap, int);
			if (prec == 0)
				return (-1);
			else if (prec == -1)
				return (0);
			else
				return (prec);
		}
		if (ft_atoi(&src[i]))
			return (ft_atoi(&src[i]));
		else
			return (-1);
	}
	return (0);
}

int	find_width(const char *src, va_list ap)
{
	int	i;

	i = 0;
	while (is_flag(src[i]))
		i++;
	if (src[i] == '*')
		return (va_arg(ap, int));
	if (ft_atoi(&src[i]))
		return (ft_atoi(&src[i]));
	return (0);
}
