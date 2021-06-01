#include "printf.h"

void print_spec_c(t_specif spec, va_list ap)
{
	int c;
	int len;

	c = va_arg(ap, int);
	len = 1;
	if (!spec.flag_minus && spec.width)
		while (len++ < spec.width)
			ft_putchar(' ');
	ft_putchar(c);
	if (spec.flag_minus && spec.width)
		while (len++ < spec.width)
			ft_putchar(' ');
}

void print_spec_s(t_specif spec, va_list ap)
{
    char *src;

    src = va_arg(ap, char *);
    if (!src)
        src = ft_strdup("(null)");
    src = ft_strdup(src);
    if (spec.prec > 0 && spec.prec <= (int)ft_strlen(src))
        src[spec.prec] = '\0';
	if (spec.prec == -1)
		*src = '\0';
    output(src, spec);
}

void print_spec_u(t_specif spec, va_list ap)
{
	unsigned int nb;
	char *src;

	nb = va_arg(ap, unsigned int);
	if (nb == 0 && spec.prec == -1)
	{
		src = (char *)malloc(1);
		*src = '\0';
	}
	else
		src = ft_itoa_u(nb);
	prec_initialization(&src, spec);
	if (spec.flag_zero && !spec.flag_minus && !spec.prec)
		add_zero(&src, spec);
	if (spec.prec == -1)
		*src = '\0';
	output(src, spec);
}

void print_spec_di(t_specif spec, va_list ap)
{
	int n;
    char *res;

	n = va_arg(ap, int);
	if (n == 0 && spec.prec == -1)
	{
		res = (char *)malloc(1);
		*res = '\0';
	}
	else
    	res = ft_itoa(n);
	prec_initialization(&res, spec);
	if (spec.flag_zero && !spec.prec)
		add_zero(&res, spec);
	if (spec.flag_plus || spec.flag_space)
		add_plus(&res, spec, n);
    output(res, spec);
}