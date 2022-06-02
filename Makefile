# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 21:38:50 by jlebre            #+#    #+#              #
#    Updated: 2022/06/02 19:13:48 by jlebre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = @rm -fr
NAME = 
SERVER = server
CLIENT = client
SSRCS = server.c
CSRCS = client.c
SRC = colors.c ft_strlen.c ft_atoi.c ft_printf.c func_extra.c func_extra1.c
LIB = .

all: $(SERVER) $(CLIENT)

$(NAME): all

$(SERVER):
	@$(CC) $(FLAGS) $(SSRCS) $(SRC) -I$(LIB) -o $(SERVER)
	@echo "\033[0;32mServer Compiled!\033[0m"

$(CLIENT):
	@$(CC) $(FLAGS) $(CSRCS) $(SRC) -I$(LIB) -o $(CLIENT)
	@echo "\033[0;32mClient Compiled!\033[0m"

clean:
	$(RM) *.o
	@echo "\033[0;31m.o Files Removed!\033[0m"

fclean: clean
	$(RM) $(SERVER) $(CLIENT)
	@echo "\033[0;31mServer and Client Removed!\033[0m"

re: fclean all

.PHONY: all clean fclean re
