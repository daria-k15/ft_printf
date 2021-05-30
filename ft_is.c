#include "printf.h"
int is_norm(char c)
{
     if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
    c == 'u' || c == 'x' || c == 'X' || (c >= '0' && c <= '9') ||
    c == '-' || c== '+' || c == '0' || c == '#' || c == ' ')
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