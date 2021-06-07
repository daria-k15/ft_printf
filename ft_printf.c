/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 20:18:48 by heveline          #+#    #+#             */
/*   Updated: 2021/06/06 20:24:29 by heveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
void	get_spec(t_specif *spec, va_list ap)
{
	if (spec->type == 'd' || spec->type == 'i')
		print_spec_di(spec, ap);
	if (spec->type == 's')
		print_spec_s(spec, ap);
	if (spec->type == 'c' || spec->type == '%')
		print_spec_c(spec, ap);
	if (spec->type == 'u')
		print_spec_u(spec, ap);
	if (spec->type == 'x')
		print_spec_x(spec, va_arg(ap, unsigned int));
	if (spec->type == 'X')
		print_spec_X(spec, va_arg(ap, unsigned int));
	if (spec->type == 'p')
		print_spec_p(spec, ap);
}

int	scan_spec(const char *str, va_list ap, t_specif *spec)
{
	int	i;

	i = 0;
	while (str[i] && is_norm(str[i]) && !is_type(str[i]))
		i++;
	if (!is_type(str[i]))
		return (0);
	spec->type = str[i];
	find_flags(spec, str);
	spec->width = find_width(str, ap);
	spec->prec = find_prec(str, ap, spec);
	get_spec(spec, ap);
	return (i + 1);
}

int	ft_printf(const char *src, ...)
{
	int			i;
	t_specif	spec;
	va_list		ap;
	int			len;

	i = 0;
	len = 0;
	va_start(ap, src);
	while (src[i])
	{
		if (src[i] == '%')
			i += scan_spec(&src[i + 1], ap, &spec);
		else
			spec.write_length += write(1, &src[i], 1);
		i++;
	}
	va_end(ap);
	return (spec.write_length);
}
