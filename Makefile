NAME = libftprintf.a

SRCS = ft_find.c ft_is.c ft_add.c print_dicsp.c ft_printf.c ft_utils.c ft_utils_2.c\
		print_ux.c libfun.c

OBJS = $(SRCS:.c=.o)

BONUS = ft_find.c ft_is.c ft_add.c print_dicsp.c ft_printf.c ft_utils.c ft_utils_2.c\
		print_ux.c libfun.c

BONOBJS = $(BONUS:.c=.o)

CC = gcc

FLAGS = -Wall -Wextra -Werror

HEADER = ft_printf.h

%.o: %.c		
			@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			@ar rcs $(NAME) $(OBJS)

bonus:		$(NAME) $(BONOBJS)
			@ar rcs $(NAME) $(BONOBJS)

all:		$(NAME)

clean:
			@rm -f $(OBJS) 

fclean:		clean
			@rm -f $(NAME)

re:			fclean all

rebonus:	fclean bonus

.PHONY:		all clean fclean re bonus rebonus