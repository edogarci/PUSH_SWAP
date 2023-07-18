# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edogarci <edogarci@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/13 15:40:29 by adiaz-be          #+#    #+#              #
#    Updated: 2023/07/17 12:10:57 by edogarci         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -rf

SRC	=	main.c \
		utils_01.c \
		utils_02.c \
		utils_03.c \
		utils_04.c \
		utils_05.c \
		utils_06.c \
		utils_07.c

OBJS = $(SRC:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)		

re:	fclean all

.PHONY:	all clean fclean re