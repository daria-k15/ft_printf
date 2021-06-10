/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_ux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heveline <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/06 20:16:18 by heveline          #+#    #+#             */
/*   Updated: 2021/06/06 20:18:27 by heveline         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_spec_u(t_specif *spec, va_list ap)
{
	unsigned int	nb;
	char			*src;

	nb = va_arg(ap, unsigned int);
	if (nb == 0 && spec->prec == -1)
	{
		src = (char *)malloc(1);
		*src = '\0';
	}
	else
		src = ft_itoa_u(nb);
	if (spec->width < 0)
	{
		spec->flag_minus = 1;
		spec->width *= (-1);
	}
	if (spec->prec < 0 && spec->prec != -1)
		spec->prec = 0;
	prec_initialization(&src, spec);
	if (spec->flag_zero && !spec->flag_minus && !spec->prec)
		if ((int)ft_strlen(src) < spec->width)
			add_zero(&src, spec);
	output(src, spec);
	free(src);
}

void	print_spec_x(t_specif *spec, unsigned int nb)
{
	char			*src;

	if (nb == 0 && spec->prec == -1)
	{
		src = (char *)malloc(1);
		*src = '\0';
	}
	else
		src = ft_itoa_base_ux(nb, 16);
	if (spec->width < 0)
	{
		spec->width *= (-1);
		spec->flag_minus = 1;
	}
	prec_initialization(&src, spec);
	if (spec->flag_hash && nb != 0)
		add_hash(&src, spec, nb);
	if (spec->flag_zero && !spec->flag_minus && !spec->prec)
	{
		if ((int)ft_strlen(src) < spec->width)
			add_zero(&src, spec);
	}
	output(src, spec);
	free(src);
}

void	print_spec_X(t_specif *spec, unsigned int nb)
{
	char			*src;

	if (nb == 0 && spec->prec == -1)
	{
		src = (char *)malloc(1);
		*src = '\0';
	}
	else
		src = ft_itoa_base_uX(nb, 16);
	if (spec->width < 0)
	{
		spec->width *= (-1);
		spec->flag_minus = 1;
	}
	prec_initialization(&src, spec);
	if (spec->flag_hash && nb != 0)
		add_hash(&src, spec, nb);
	if (spec->flag_zero && !spec->flag_minus && !spec->prec)
	{
		if ((int)ft_strlen(src) < spec->width)
			add_zero(&src, spec);
	}
	output(src, spec);
	free(src);
}
