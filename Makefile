# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: analdo <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/02 18:10:25 by analdo            #+#    #+#              #
#    Updated: 2024/08/04 21:19:34 by almanuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = server
NAME2 = client
NAME_B1 = server_bonus
NAME_B2 = client_bonus
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
	$(CC) $(CFLAGS) -o $(NAME1) $(OBJ1)

$(NAME2): $(OBJ2)
	$(CC) $(CFLAGS) -o $(NAME2) $(OBJ2)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(NAME_B1) $(NAME_B2)

$(NAME_B1): $(B_OBJ1)
	$(CC) $(CFLAGS) -o $(NAME_B1) $(B_OBJ1)

$(NAME_B2): $(B_OBJ2)
	$(CC) $(CFLAGS) -o $(NAME_B2) $(B_OBJ2)

clean:
	rm -rf $(OBJ1)
	rm -rf $(OBJ2)
	rm -rf $(B_OBJ1)
	rm -rf $(B_OBJ2)

fclean: clean
	rm -rf $(NAME1)
	rm -rf $(NAME2)
	rm -rf $(NAME_B1)
	rm -rf $(NAME_B2)

re: fclean all
