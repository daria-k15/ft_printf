#include "printf.h"

int is_norm(char c)
{
     if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
    c == 'u' || c == 'x' || c == 'X' || (c >= '0' && c <= '9') ||
    c == '-' || c== '+' || c == '0' || c == '#' || c == ' ' || c == '.' || c == '*')
        return (1);
    return (0);
}

int is_flag(char c)
{
    if (c == '-' || c== '+' || c == '0' || c == '#' || c == ' ')
        return (1);
    return (0);
}

int is_type(char c)
{
    if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
    c == 'u' || c == 'x' || c == 'X')
        return (1);
    return (0);
}
void find_flags(t_specif *spec, char *src)
{
    int i;

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
int find_prec(char *src, va_list ap)
{
    int i;

    i = 0;
    while (src[i] && src[i] != '.')
        i++;
    if (src[i++] == '.')
    {
        if (src[i] == '*')
            return (va_arg(ap, int));
        if (ft_atoi(&src[i]))
            return (ft_atoi(&src[i]));
        else
            return (-1);
    }
    return (0);
}
int find_width(char *src, va_list ap)
{
    int i;

    i = 0;
    while (is_flag(src[i]))
        i++;
    if (src[i] == '*')
        return (va_arg(ap, int));
    if (ft_atoi(&src[i]))
        return (ft_atoi(&src[i]));
    return (0);        
}
char	*ft_strdup(const char *s1)
{
	size_t	i;
	char	*dst;

	i = 0;
	dst = (char *)malloc(ft_strlen(s1) + 1);
	if (!dst)
		return ((void *)0);
	while (s1[i] != '\0')
	{
		dst[i] = s1[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void 	ft_putchar(char c)
{
	write(1, &c, 1);
}
void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (s != NULL)
	{
		while (s[i] != '\0')
		{
			write(1, &s[i], 1);
			i++;
		}
	}
}
int	ft_atoi(const char *str)
{
	size_t	i;
	int		sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	while (str[i] == 32 || (str[i] > 8 && str[i] < 14))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = (nb * 10) + (str[i] - '0');
		if (nb < -2147483647 && sign == -1)
			return (0);
		if (nb > 2147483647 && sign == 1)
			return (-1);
		i++;
	}
	return (nb * sign);
}

int	ft_num_u(unsigned int n, int base)
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
char *ft_itoa(int n)
{
	int i;
	char *nbr;

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
char	*ft_itoa_base_u(unsigned int n, int base, t_specif spec)
{
	int i;
	char *nbr;

	i = ft_num_u(n, base);
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
		if (spec.type == 'x')
		{
			if (n % base > 9)
				nbr[i] = (n % base) + 'a' - 10;
			else
				nbr[i] = (n % base) + '0';
		}
		else
		{
			if (n % base > 9)
				nbr[i] = (n % base) + 'A' - 10;
			else
				nbr[i] = (n % base) + '0';
		}
		n /= base;
		i--;
	}
	return (nbr);
}
char	*ft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
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
        src = ft_strdup("null");
    src = ft_strdup(src);
    if (spec.prec > 0 && spec.prec <= (int)ft_strlen(src))
        src[spec.prec] = '\0';
	if (spec.prec == -1)
		*src = '\0';
    output(src, spec);
}

void prec_initialization(char **src, t_specif spec)
{
	char *str;
	int i;
	int len;

	i = 0;
	len = ft_strlen(*src);
	if (spec.prec && spec.prec > len)
	{
		str = (char *)malloc(spec.prec + 1);
		while (i < (spec.prec - (int)ft_strlen(*src)))
			str[i++] = '0';
		ft_strcpy(&str[i], *src);
		//free(src);
		*src = str;
	}
}
void add_zero(char **src, t_specif spec)
{
	char *str;
	int i;
	int len;

	i = 0;
	len = (int)ft_strlen(*src);
	str = (char *)malloc(len + 1);
	if (*src[0] == '-')
		str[i++] = '-';
	while (i < (spec.width - len))
		str[i++] = '0';
	if (spec.flag_minus)
		ft_strcpy(str, *src);
	
	ft_strcpy(&str[i], *src);
	*src = str;
}
void print_spec_u(t_specif spec, va_list ap)
{
	unsigned int nb;
	char *src;

	nb = va_arg(ap, unsigned int);
	src = ft_itoa_u(nb);
	prec_initialization(&src, spec);
	if (spec.flag_zero && !spec.flag_minus && !spec.prec)
		add_zero(&src, spec);
	if (spec.prec == -1)
		*src = '\0';
	output(src, spec);
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

void print_spec_di(t_specif spec, va_list ap)
{
	int n;
    char *res;

	n = va_arg(ap, int);
    res = ft_itoa(n);
	prec_initialization(&res, spec);
	if (spec.flag_zero && !spec.prec)
		add_zero(&res, spec);
	if (spec.flag_plus || spec.flag_space)
		add_plus(&res, spec, n);
    output(res, spec);
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
    //printf("|");
	printf("%020d",      -1024);
	printf("|\n");
	printf("%020i",      -1024);
    //printf("%03u",897);
    printf("|\n");
	//printf("|");
    ft_printf("%020d",      -1024);
    printf("|\n");
	ft_printf("%020i",      -1024);
	printf("|\n");
}