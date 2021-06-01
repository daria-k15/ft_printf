#include "printf.h"

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
int find_prec(char *src, va_list ap, t_specif spec)
{
    int i;

    i = 0;
    while (src[i] && src[i] != spec.type && src[i] != '.')
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
