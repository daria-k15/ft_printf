#include "printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putnbr(long long int n)
{
	int	i;
	long long int	nb[20];

	i = 0;
	if (n == 0)
		write(1, "0", 1);
	else if (n == -2147483648)
		write(1, "-2147483648", 11);
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			n = n * (-1);
		}
		while (n > 0)
		{
			nb[i++] = n % 10 + 48;
			n = n / 10;
		}
		while (i-- > 0)
			write(1, &nb[i], 1);
	}
}
static int	ft_num(unsigned int n, int base)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = n * (-1);
	}
	while (n > 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}
char *ft_putX (unsigned int n, int base, char x)
{
	int i;
	char *nbr;

	i = ft_num(n, base);
	nbr = (char *)malloc(i + 1);
	if (!nbr)
		return (0);
	nbr[i] = '\0';
	i--;
	while (n > 0)
	{
		if (x == 'x')
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
	return (0);
}

void print_spec_s(t_specif type, va_list ap)
{

}
int	get_spec(const char *format, va_list ap)
{
	int i;
	i = 0;

	char *s;
	if (*format == 's')
	{

		s = va_arg (ap, char *);
		while (s[i])
		{
			write(1, &s[i++], 1);
		}
	}
	else 
		return (0);
	return (1);
}
int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i, j;
	//t_specif	*list;
	//list = NULL;
	i = 0;
	j = 0;
	if (!format)
		return (0);
	va_start (ap, format);
	//char *s;
	//int d;
	//unsigned int u;
	//void *p;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			i++;
			i = get_spec(&format[i], ap);
			/*if (format[i] == 's')
			{
				s = va_arg (ap, char *);
				while (s[j] != '\0')
				{
					write(1, &s[j], 1);
					j++;
				}
				j = 0;
			}
			else if (format[i] == 'c')
			{
				s = va_arg (ap, char *);
				write (1, &s, 1);
				
			}
			else if (format[i] == 'd' || format[i] == 'i')
			{
				d = va_arg (ap, int);
				ft_putnbr(d);
			}
			else if (format[i] == 'u')
			{
				u = va_arg (ap, int);
				ft_putnbr(u);
			}
			else if (format[i] == 'X' || format[i] == 'x')
			{
				u = va_arg(ap, int);
				ft_putX(u, 16, format[i]);
			}
			else if (format[i] == 'p')
			{
				p = va_arg(ap, void *);
			}*/
		}
		else
			write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (i);
}

int	main(void)
{
	ft_printf("      %s", "qwerty");
	//printf("\n");
	//ft_printf("%i\n", -567896);
	//printf("%u\n", -42949672);
	//ft_printf("%u\n", -42949672);
	//ft_printf("%c\n", 'p');
	//ft_printf("%d\n", 45789685);
	
	//printf("%x\n", 10);
	//ft_printf("%x", 564868788);
	//int a = 10;
	//int *b = &a;
	//printf("%p\n", b);
}