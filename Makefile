# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 21:38:50 by jlebre            #+#    #+#              #
#    Updated: 2022/05/24 15:20:52 by jlebre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -fr
NAME = minitalk
SERVER = server
CLIENT = client
SSRCS = server.c
CSRCS = client.c
SOBJS = $(SSRCS:.c=.o)
COBJS = $(CSRCS:.c=.o)
LIB = .

all: $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER): $(SOBJS)
	$(CC) $(SOBJS) -o $(SERVER)

$(CLIENT): $(COBJS)
	$(CC) $(COBJS) -o $(CLIENT)

%.o: %.c
	$(CC) $(FLAGS) -I$(LIB) -c $< -o $@

clean:
	$(RM) $(SERVER) $(CLIENT)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
