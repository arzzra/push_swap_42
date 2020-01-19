# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdemetra <cdemetra@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/19 04:52:05 by cdemetra          #+#    #+#              #
#    Updated: 2020/01/19 18:40:13 by cdemetra         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1	= push_swap
NAME2	= checker

CFLAGS 	= -Wall -Wextra -Werror

SRC1	= main.c additionals.c algos.c malloc.c operations.c save.c sorting.c \
		validation.c sorting2.c sorting3.c sorting4.c commands.c commands2.c for_5_digits.c

SRC2	= main_checker.c save.c validation.c push_swap_checker.c operations.c \
		malloc.c additionals.c

SRCDIR	= sources

OBJSFD	= objects

OBJS1 	= $(addprefix $(OBJSFD)/,$(SRC1:.c=.o))
OBJS2 	= $(addprefix $(OBJSFD)/,$(SRC2:.c=.o))

HDR 		= -I ./includes

LIBFT_HDR 	= -I ./includes/libft/includes

LIB_BINARY	= -L ./libft -lft

LIBFT		= ./libft/libft.a

all: $(LIBFT) $(NAME1) $(NAME2)

$(OBJSFD):
	mkdir $@

$(OBJSFD)/%.o: $(SRCDIR)/%.c | $(OBJSFD)
	gcc $(CFLAGS) $(HDR) $(LIBFT_HDR) -c $< -o $@

$(LIBFT):
	make -C ./libft

$(NAME1): $(OBJS1)
	gcc $(OBJS1) $(LIB_BINARY) -o $@

$(NAME2): $(OBJS2)
	gcc $(OBJS2) $(LIB_BINARY) -o $@

clean:
	/bin/rm -f $(OBJS1)
	/bin/rm -f $(OBJS2)
	rm -rf $(OBJSFD)
	make -C ./libft clean

fclean: clean
	/bin/rm -f $(NAME1)
	/bin/rm -f $(NAME2)
	make -C ./libft fclean

re: fclean all

.PHONY: all clean fclean re
