#include "printf.h"

void add_zero(char **src, t_specif spec)
{
	char *str;
	int i;
	int len;
	int tmp;

	i = 0;
	tmp = 0;
	len = (int)ft_strlen(*src);
	str = (char *)malloc(len + 1);
	if (**src == '-')
	{
		str[i++] = **src;
		//len--;
	}
	while (str[tmp])
		tmp++;
	while (len++ < spec.width)
		str[i++] = '0';
		
	ft_strcpy(&str[i], *src + tmp);
	*src = str;
}

void add_hash(char **src, t_specif spec, unsigned int nb)
{
	char *new;
	int i;
	int len;

	i = 0;
	len = ft_strlen(*src);
	new = (char *)malloc(len + 1);
	new[i++] = '0';
	if ((spec.type == 'x' || spec.type == 'X') && nb > 0)
		new[i++] = spec.type;
	ft_strcpy(&new[i++], *src);
	*src = new;
}

void add_plus(char **src, t_specif spec, int n)
{
	char *new;
	int len;
	int i;

	i = 0;
	len = ft_strlen(*src);
	new = (char *)malloc(len + 1);
	if (spec.flag_plus && n > 0)
		new[i++] = '+';
	else if (spec.flag_space && n > 0)
		new[i++] = ' ';
	ft_strcpy(&new[i], *src);
	*src = new; 
	
}
