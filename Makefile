# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssandman <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/02 17:27:36 by ssandman          #+#    #+#              #
#    Updated: 2020/11/06 20:52:35 by ssandman         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: clean fclean all re

NAME			= libftprintf.a

HEADER			= ./includes/ft_printf.h

SRCS			=	ft_printf.c \
					parsing.c \
					print_cs.c \
					print_di.c \
					print_uxp.c \
					utils.c

OBJS			= $(SRCS:.c=.o)

CC				= gcc
RM				= rm -f
CFLAGS			= -Wall -Wextra -Werror -I.

all:			$(NAME)

bonus: all

$(NAME):		$(OBJS)
				ar rcs $(NAME) $(OBJS) $(HEADER)

clean:
				$(RM) $(OBJS) $(BONUS_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean all

