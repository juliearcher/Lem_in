# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: jarcher <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2019/09/13 10:53:04 by jarcher      #+#   ##    ##    #+#        #
#    Updated: 2020/03/09 11:53:27 by jarcher          ###   ########lyon.fr    #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

NAME=lem-in
LIB=libft/libft.a

SRC=ants.c			\
	input.c			\
	lemin.c			\
	link.c			\
	main.c			\
	node.c			\
	parser.c		\
	path.c			\
	scan.c			\
	simulation.c	\
	update_path.c	\
	valid_link.c

SRCS=${addprefix src/, ${SRC}}

OBJS=$(SRCS:.c=.o)

CFLAGS=-Wall -Werror -Wextra -Iinclude -O3 -march=native

RM=rm -f

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	gcc -o $(NAME) $(OBJS) -lft -Llibft $(CFLAGS)

clean:
	$(RM) $(OBJS)
	make clean -C libft

fclean: clean
	$(RM) $(NAME) $(LIB)

re: fclean all

.PHONY: all clean fclean re
