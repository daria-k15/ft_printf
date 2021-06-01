#include "printf.h"

void output(char *src, t_specif spec)
{
    int len;

    len = ft_strlen(src);
    if (!spec.flag_minus)
    {
        while (len++ < spec.width)
            ft_putchar(' ');
    }
    ft_putstr(src);
    if (spec.flag_minus)
    {
         while (len++ < spec.width)
            ft_putchar(' ');
    }
    
}

void prec_initialization(char **src, t_specif spec)
{
	char *new;
	int i;
	int len;

	i = 0;
	len = (int)ft_strlen(*src);
	if (**src == '-')
		len--;
	if (spec.prec && spec.prec > len)
	{
		new = (char *)malloc(len + 1);
		if (**src == '-')
		{
			new[i++] = '-';
			ft_strcpy(&new[i], *src);
		}
		ft_strcpy(&new[spec.prec - len], *src);
		while (len++ < spec.prec)
			new[i++] = '0';
		*src = new;
	}
}