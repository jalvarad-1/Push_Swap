# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jalvarad <jalvarad@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/08/15 15:45:28 by jalvarad          #+#    #+#              #
#    Updated: 2021/08/21 11:45:31 by jalvarad         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= push_swap

LIBFT			= libft.a

LIBFT_DIR		= ./libft/

SRCS			= push_swap.c \
					operations.c \
					operations2.c \
					sort_in_b.c \
					go_to_sort.c \
					utils_push_swap.c \
					array_chunks.c \
					sort_nbrs.c \
					another_utils_fts.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc

CFLAGS			= -Wall -Wextra -Werror

all: make-libft $(NAME)

$(NAME): $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT_DIR)$(LIBFT) -o $(NAME)

$(OBJS): $(SRCS)
		$(CC) $(CFLAGS) -c $(SRCS)

make-libft:
		make -C $(LIBFT_DIR)

clean:
		rm -rf $(OBJS)
		$(MAKE) clean -C ./Libft

fclean: clean
		$(MAKE) fclean -C ./Libft
		rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean