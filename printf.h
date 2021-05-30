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
	int		flag_plus;
	int		flag_hash;
	int		flag_space;
	int		prec;
	int		width;
	char	type;
}				t_specif;

int	ft_atoi(const char *str);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);
int is_norm(char c);
int is_flag(char c);
int is_type(char c);
void find_flags(t_specif *spec, char *src);
int find_prec(char *src, va_list ap);
int find_width(char *src, va_list ap);

#endif