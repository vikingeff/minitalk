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

SRCS1		=	ft_stuff.c \
          		server.c

SRCS2		=	ft_stuff.c \
          		ft_more.c \
          		client.c

OBJS1		=	$(SRCS1:.c=.o)

OBJS2		=	$(SRCS2:.c=.o)

RM			=	rm -f

CC			=	gcc

CFLAGS		+=	-Wall -Werror -Wextra -O3 -I./includes

all			:	$(NAME1) $(NAME2)

$(NAME1)	:	$(OBJS1)
				$(CC) $(CFLAGS) -o $@ $^

$(NAME2)	:	$(OBJS2)
				$(CC) $(CFLAGS) -o $@ $^

%.o     	:	%.c includes/minitalk.h
				$(CC) $(CFLAGS) -c $<

clean		:
				$(RM) $(OBJS1) $(OBJS2)

fclean		:	clean
				$(RM) $(NAME1) $(NAME2)

re			:	fclean all

.PHONY		:	all clean fclean re
