# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gtournay <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/05/17 12:37:38 by gtournay          #+#    #+#              #
#    Updated: 2021/05/17 12:37:40 by gtournay         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS = srcs/main.c srcs/init.c srcs/ft_split.c srcs/parse.c srcs/utils.c srcs/utilsbis.c

OBJS = ${SRCS:.c=.o}

NAME = pipex

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

$(NAME) : $(OBJS)
			$(CC) $(CFLAGS) $(OBJS) -o $(NAME)


all: $(NAME)

clean: 
		$(RM) $(OBJS)

fclean:
		$(RM) $(OBJS) $(NAME)

re : fclean all