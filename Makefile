# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: almanuel <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/29 05:42:02 by almanuel          #+#    #+#              #
#    Updated: 2024/07/29 07:15:25 by almanuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

name1 = server

name2 = client

server = server.c

client = client.c

all:
	gcc $(server) -o $(name1)
	gcc $(client) -o $(name2)

clean:
	rm -r $(name1) $(name2)
