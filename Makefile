NAME = libftprintf.a

SRCS = ft_find.c ft_is.c ft_add.c ft_print_csdiu.c ft_printf.c ft_utils.c ft_utils_2.c\
		ft_atoi.c ft_putchar.c ft_putstr.c ft_strcpy.c ft_strdup.c ft_strlen.c

OBJS = $(SRCS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEADER = printf.h

%.o: %.c		
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)

all:		$(NAME)

clean:
			rm -f $(OBJS) 

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY:		all clean fclean re