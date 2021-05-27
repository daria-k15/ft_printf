#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_specif
{
	int		flag_minus;
	int		flag_zero;
	int		flag_dot;
	int		prec;
	int		length;
	char	type;
}				t_specif;

#endif