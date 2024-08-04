# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: analdo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/02 18:10:25 by analdo            #+#    #+#              #
#    Updated: 2024/08/03 19:05:50 by analdo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = server
NAME2 = client
NAME1_B = server_bonus
NAME2_B = client
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_1 = server.c
SRC_2 = client.c
B_SRC_1 = server_bonus.c
B_SRC_2 = client_bonus.c
OBJ1 = ${SRC_1:.c=.o}
OBJ2 = ${SRC_2:.c=.o}
B_OBJ1 = ${B_SRC_1:.c=.o}
B_OBJ2 = ${B_SRC_2:.c=.o}

all: $(NAME1) $(NAME2)

$(NAME1): $(OBJ1)
	$(CC) $(CFLAGS) $(OBJ1) -o $(NAME1)

$(NAME2): $(OBJ2)
	$(CC) $(CFLAGS) $(OBJ2) -o $(NAME2)

bonus: $(NAME1_B) $(NAME2_B)

$(NAME1_B): $(B_OBJ1)
	$(CC) $(CFLAGS) $(B_OBJ1) -o $(NAME1_B)

$(NAME2_B): $(B_OBJ2)
	$(CC) $(CFLAGS) $(B_OBJ2) -o $(NAME2_B)

clean:
	rm -rf $(OBJ1)
	rm -rf $(OBJ2)
	rm -rf $(B_OBJ1)
	rm -rf $(B_OBJ2)

fclean: clean
	rm -rf $(NAME1)
	rm -rf $(NAME2)
	rm -rf $(NAME1_B)
	rm -rf $(NAME2_B)

re: fclean all
