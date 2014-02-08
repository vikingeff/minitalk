#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svermeer <svermeer@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/02/08 10:59:07 by svermeer          #+#    #+#              #
#    Updated: 2014/02/08 13:01:44 by svermeer         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME1		=	server

NAME2		=	client

SRCS1		=	ft_strlen.c \
				ft_putchar.c \
				ft_putnbr.c \
				error.c \
				server.c

SRCS2		=	ft_strlen.c \
				error.c \
				client.c

OBJS1		=	$(SRCS1:.c=.o)

OBJS2		=	$(SRCS2:.c=.o)

RM			=	rm -f

CC			=	gcc

CFLAGS		+=	-Wall -Werror -Wextra

all			:	$(NAME1) $(NAME2)

$(NAME1)	:	$(OBJS1)
				$(CC) -o $(NAME1) $(OBJS1) $(CFLAGS)

$(NAME2)	:	$(OBJS2)
				$(CC) -o $(NAME2) $(OBJS2) $(CFLAGS)

clean		:
				$(RM) $(OBJS1) $(OBJS2)

fclean		:	clean
				$(RM) $(NAME1) $(NAME2)

re			:	fclean all
