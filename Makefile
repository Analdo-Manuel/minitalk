# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almanuel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 05:42:02 by almanuel          #+#    #+#              #
#    Updated: 2024/08/02 13:59:32 by analdo           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = server
NAME2 = client
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRC_1 = server.c
SRC_2 = client.c
B_SRC_1 = server_bonus.c
B_SRC_2 = client_bonus.c
OBJ1 = ${SRC_1: .C=.O}
OBJ2 = ${SRC_2: .C=.O}
B_OBJ1 = ${B_SRC_1: .C=.O}
B_OBJ2 = ${B_SRC_2: .C=.O}

all:	$(NAME1) $(NAME2)

$(NAME1) : $(OBJ1)
	$(CC) $(CFLAGS) $(OBJ1) -o $@ $^
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME2) : $(OBJ2)
	$(CC) $(CFLAGS) $(OBJ2) -o $(NAME2)

bonus:	$(NAME1) $(NAME2)

$(NAME1) : $(B_SRC_1)
	$(CC) $(CFLAGS) $(B_SRC_1) -o $(NAME1)

$(NAME2) : $(B_SRC_2)
	$(CC) $(CFLAGS) $(B_SRC_2) -o $(NAME2)

clean:
	rm -rf $(name1) 
	rr -rf $(
fclean:


re:
