/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_dicsp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 20:08:35 by heveline          #+#    #+#             */
/*   Updated: 2021/06/06 20:15:53 by heveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_spec_di(t_specif *spec, va_list ap)
{
	int		n;
	char	*res;

	n = va_arg(ap, int);
	res = ft_itoa(n);
	if (spec->width < 0)
	{
		spec->flag_minus = 1;
		spec->width *= (-1);
	}
	if (spec->prec == -1 && *res == '0')
		*res = '\0';
	prec_initialization(&res, spec);
	if (spec->prec < 0 && spec->prec != -1)
		spec->prec = 0;
	if (spec->flag_zero && !spec->prec && !spec->flag_minus)
		if ((int)ft_strlen(res) < spec->width)
			add_zero(&res, spec);
	if (spec->flag_plus || spec->flag_space)
		add_plus(&res, spec, n);
	output(res, spec);
	free(res);
}

void	print_spec_p(t_specif *spec, va_list ap)
{
	char	*new;
	char	*tmp;
	int		i;

	i = 0;
	tmp = ft_itoa_base_ux(va_arg(ap, unsigned long), 16);
	new = (char *)malloc(ft_strlen(tmp) + 3);
	new[i++] = '0';
	new[i++] = 'x';
	if (spec->prec == -1 && *tmp == '0')
		new[i++] = '\0';
	else
		ft_strcpy(&new[i], tmp);
	free(tmp);
	tmp = new;
	prec_initialization(&tmp, spec);
	if (spec->width < 0 && spec->width != -1)
	{
		spec->width *= (-1);
		spec->flag_minus = 1;
	}
	if (spec->flag_zero && !spec->flag_minus && !spec->prec)
		add_zero(&tmp, spec);
	output(tmp, spec);
	free(tmp);
}

void	print_spec_c(t_specif *spec, va_list ap)
{
	int		c;
	int		len;

	if (spec->type == '%')
		c = '%';
	else
		c = va_arg(ap, int);
	len = 1;
	if (spec->width < 0 && spec->width != -1)
	{
		spec->width *= (-1);
		spec->flag_minus = 1;
	}
	if (!spec->flag_minus && spec->width && !spec->flag_zero)
		while (len++ < spec->width)
			spec->write_length += write(1, " ", 1);
	if (spec->flag_zero && spec->type != 'c' && !spec->flag_minus)
		while (len++ < spec->width)
			spec->write_length += write(1, "0", 1);
	spec->write_length += write(1, &c, 1);
	if (spec->flag_minus && spec->width)
		while (len++ < spec->width)
			spec->write_length += write(1, " ", 1);
}

void	print_spec_s(t_specif *spec, va_list ap)
{
	char	*src;

	src = va_arg(ap, char *);
	if (!src)
		src = ft_strdup("(null)");
	else
		src = ft_strdup(src);
	if (spec->width < 0)
	{
		spec->flag_minus = 1;
		spec->width *= (-1);
	}
	if (spec->prec > 0 && spec->prec <= (int)ft_strlen(src))
		src[spec->prec] = '\0';
	if (spec->prec == -1)
		src[0] = '\0';
	if (spec->prec < 0)
		spec->prec = 0;
	output(src, spec);
	free(src);
}
