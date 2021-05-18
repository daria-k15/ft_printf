#include "printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	get_spec(const char *format, va_list ap)
{
	int i;
	i = 1;
	if (format[i + 2] == 's')
	{
		while (va_arg(ap, char *) != '\0')
			write(1, &format[i], 1);
	}
	else 
		return (0);
	return (1);
}
void	ft_putnbr_fd(int n)
{
	int	i;
	int	nb[11];

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


int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i, j;
	t_specif	*list;
	list = NULL;
	i = 0;
	j = 0;
	if (!format)
		return (0);
	va_start (ap, format);
	char *s;
	int d;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '%')
		{
			i++;
			if (format[i] == 's')
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
			else if (format[i] == 'd')
			{
				d = va_arg (ap, int);
				ft_putnbr_fd(d);
			}
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
	ft_printf("%%%  %s %c %%%%  %s %s %d", "qwerty",'g', "hey", "there", 1458796);
	printf("\n");
	ft_printf("%c", 'p');
	printf("\n");
	ft_printf("%d", 45789685);
	
	//printf("%c", 'cfd');
}
