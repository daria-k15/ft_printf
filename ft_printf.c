#include "printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int get_spec(char *format, va_list ap)
{
    
}

int ft_printf(const char *format, ...)
{
    va_list ap;

    int i;

    i = 0;
    if (!format)
        return (0);
    va_start(ap, format);
    while (format[i] != '\0')
    {
        if (format[i] == '%')
        {
            i = get_spec(&format[i + 1], ap);
        }
        else
            write(1, &format[i], 1);
        i++;
    }
    return (i);
}

int main ()
{
    ft_printf("qwerty %", 2);
}