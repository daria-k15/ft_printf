#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_specif
{
	int		flag_minus;
	int		flag_zero;
	int		flag_plus;
	int		flag_hash;
	int		flag_space;
	int		prec;
	int		width;
	int		write_length;
	char	type;
}				t_specif;

int		ft_printf(const char *src, ...);
int		is_norm(char c);
int		is_flag(char c);
int		is_type(char c);
size_t	ft_strlen(const char *str);
int		ft_atoi(const char *str);
void	find_flags(t_specif *spec, const char *src);
int		find_prec(const char *src, va_list ap, t_specif *spec);
int		find_width(const char *src, va_list ap);
int		ft_putstr(char *s);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(const char *s1);
int		ft_num_u(unsigned long long n, int base);
int		ft_num_int(int n, int base);
char	*ft_itoa(int n);
char	*ft_itoa_u(unsigned int n);
char	*ft_itoa_base_ux(unsigned long long n, int base);
char	*ft_itoa_base_uX(unsigned long long n, int base);
void	prec_initialization(char **src, t_specif *spec);
void	add_zero(char **src, t_specif *spec);
void	add_hash(char **src, t_specif *spec, unsigned int nb);
void	add_plus(char **src, t_specif *spec, int n);
void	output(char *src, t_specif *spec);
void	print_spec_s(t_specif *spec, va_list ap);
void	print_spec_c(t_specif *spec, va_list ap);
void	print_spec_u(t_specif *spec, va_list ap);
void	print_spec_p(t_specif *spec, va_list ap);
void	print_spec_x(t_specif *spec, unsigned int nb);
void	print_spec_X(t_specif *spec, unsigned int nb);
void	print_spec_di(t_specif *spec, va_list ap);
void	get_spec(t_specif *spec, va_list ap);
int		scan_spec(const char *str, va_list ap, t_specif *spec);

#endif
