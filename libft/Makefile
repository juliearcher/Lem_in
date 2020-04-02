# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/01 14:19:03 by jarcher      #+#   ##    ##    #+#        #
#    Updated: 2019/09/02 10:55:02 by jarcher     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME =	libft.a

SRCS =	ft_isnumber.c	\
		ft_memset.c		\
		ft_bzero.c		\
		ft_fits_in_int.c	\
		ft_memcpy.c		\
		ft_memccpy.c	\
		ft_memmove.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_strlen.c		\
		ft_strlen_int.c	\
		ft_strdup.c		\
		ft_strdup_until.c	\
		ft_strcpy.c		\
		ft_strncpy.c	\
		ft_strcat.c		\
		ft_strncat.c	\
		ft_strlcat.c	\
		ft_strstr.c		\
		ft_strnstr.c	\
		ft_strcmp.c		\
		ft_strncmp.c	\
		ft_atoi.c		\
		ft_strchr.c		\
		ft_strrchr.c	\
		ft_isalpha.c	\
		ft_isdigit.c	\
		ft_isalnum.c	\
		ft_isascii.c	\
		ft_isprint.c	\
		ft_toupper.c	\
		ft_tolower.c	\
		ft_memalloc.c	\
		ft_memdel.c		\
		ft_strnew.c		\
		ft_strdel.c		\
		ft_strclr.c		\
		ft_striter.c	\
		ft_striteri.c	\
		ft_strmap.c		\
		ft_strmapi.c	\
		ft_strequ.c		\
		ft_strnequ.c	\
		ft_strsub.c		\
		ft_strjoin.c	\
		ft_strtrim.c	\
		ft_strsplit.c	\
		ft_itoa.c		\
		ft_putchar.c	\
		ft_putstr.c		\
		ft_putendl.c	\
		ft_putnbr.c		\
		ft_putchar_fd.c	\
		ft_putstr_fd.c	\
		ft_putendl_fd.c	\
		ft_putnbr_fd.c	\
						\
		get_next_line.c	\
						\
		ft_printf/ft_printf_main.c	\
		ft_printf/ft_printf.c	\
		ft_printf/get_number.c		\
		ft_printf/init_struct.c		\
		ft_printf/printf_base.c		\
		ft_printf/printf_float.c		\
		ft_printf/printf_hexa_octal.c	\
		ft_printf/printf_nb.c			\
		ft_printf/printf_precision.c	\
		ft_printf/printf_str.c		\
		ft_printf/printf_unicode.c	\
		ft_printf/set_modifiers.c		\
		ft_printf/libft/ft_putchar_printf.c				\
		ft_printf/libft/ft_putchar_unicode.c		\
		ft_printf/libft/ft_putstr_printf.c		\
		ft_printf/libft/ft_putnbr_unsigned_base.c		\
		ft_printf/libft/ft_strlen_float_unsigned.c	\
		ft_printf/libft/ft_strlen_unicode.c		\
		ft_printf/libft/ft_strlen_unsigned.c



OBJS =	$(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I.

RM =	rm -f

all: $(NAME)

$(NAME): $(OBJS) libft.h
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
.SILENT: clean fclean $(OBJS)
