# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jlebre <jlebre@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/23 21:38:50 by jlebre            #+#    #+#              #
#    Updated: 2022/06/01 18:09:41 by jlebre           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = @rm -fr
NAME = minitalk
SERVER = server
CLIENT = client
SSRCS = server.c
CSRCS = client.c
SOBJS = $(SSRCS:.c=.o)
COBJS = $(CSRCS:.c=.o)
LIB = .
LIBFT_LIB = ./libft/
PRINTF_LIB = ./ft_printf/

all: $(NAME)

$(NAME): $(CLIENT)

$(CLIENT): $(SERVER) $(CSRCS) $(COBJS)
	$(CC) $(COBJS) -I$(LIB) -I$(LIBFT_LIB) -I$(PRINTF_LIB) -o $(CLIENT)
	@echo "\033[0;32mClient Compiled!\033[0m"
	
$(SERVER): $(SSRCS) $(SOBJS)
	$(CC) $(SOBJS) -I$(LIB) -I$(LIBFT_LIB) -I$(PRINTF_LIB) -o $(SERVER)
	@echo "\033[0;32mServer Compiled!\033[0m"

.c.o:
	$(CC) $(FLAGS) -I$(LIB) -I$(LIBFT_LIB) -I$(PRINTF_LIB) -c $< -o $(<:.c=.o)

clean:
	$(RM) $(SERVER) $(CLIENT)
	@echo "\033[0;31mOBJ Delected!\033[0m"

fclean: clean
	$(RM) $(NAME)
	@echo "\033[0;31mNEME Delected!\033[0m"

re: fclean all

.PHONY: all clean fclean re
