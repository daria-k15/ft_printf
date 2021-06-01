#include "printf.h"

void print_spec_xX(t_specif spec, va_list ap)
{
	unsigned int nb;
	char *src;

	nb = va_arg(ap, unsigned long);
	src = ft_itoa_base_u(nb, 16, spec);
	prec_initialization(&src, spec);
	if (spec.flag_zero && !spec.flag_minus && !spec.prec)
	{
		if(spec.flag_hash)
			spec.width -= 2;
		add_zero(&src, spec);
	}
	if (spec.flag_hash)
		add_hash(&src, spec, nb);
	output(src, spec);
}

void get_spec(t_specif spec, va_list ap)
{
    if (spec.type == 'd' || spec.type == 'i')
        print_spec_di(spec, ap);
    if (spec.type == 's')
        print_spec_s(spec, ap);
	if (spec.type == 'c')
		print_spec_c(spec,ap);
	if (spec.type == 'u')
		print_spec_u(spec, ap);
	if (spec.type == 'x' || spec.type == 'X')
		print_spec_xX(spec, ap);
}

int scan_spec(char *src, va_list ap)
{
    int         i;
    t_specif    spec;

    i = 0;
    find_flags(&spec, src);
    spec.width = find_width(src, ap);
    spec.prec = find_prec(src, ap);
    while (src[i] && is_norm(src[i]) && !is_type(src[i]))
        i++;
    if (!is_type(src[i]))
        return (0);
    spec.type = src[i];
    get_spec(spec, ap);

    return (i + 1);
}

int ft_printf(char *src, ...)
{
    int i;
    va_list ap;

    i = 0;
    va_start(ap, src);
    while (src[i])
    {
        if (src[i] == '%' && src[i + 1] != '%')
            i += scan_spec(&src[i + 1], ap);
        else 
            ft_putchar(src[i]);
        i++;
    }
    return (0);
}

int main()
{
    /*//printf("|");
	printf("%d", 0);
	printf("|\n");
	//printf("%020i",      -1024);
    //printf("%03u",897);
    printf("|\n");
	//printf("|");
    ft_printf("%d", 0);
    printf("|\n");
	//ft_printf("%020i",      -1024);
	printf("|\n");*/
	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";
	printf("|");
	printf("%-.0i, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d", i, j, k, l, m, c, e, d);
	printf("|\n");
	//printf("|");
	ft_printf("%-.0i, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d, %-.0d", i, j, k, l, m, c, e, d);
	printf("|\n");
}