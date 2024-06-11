# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vpeinado <victor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/10 21:29:39 by vpeinado          #+#    #+#              #
#    Updated: 2024/06/11 22:58:56 by vpeinado         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Style
GREEN	=	\033[92;5;118m
YELLOW	=	\033[93;5;226m
GRAY	=	\033[33;2;37m
RESET	=	\e[0m
CURSIVE	=	\033[33;3m
RED		= 	\033[31m

#Program name
NAME	= IPcalculator
#Compiler
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
#CFLAGS	+= -g3 -fsanitize=address
RM		= rm -f

#Includes
INC			= -I ./inc/

#Source files
SRC_DIR	= src/
SRC 	= $(shell find $(SRC_DIR) -type f -iname "*.c" | sed 's|^src/||')

#Object files
OBJ_DIR	= obj/
OBJ		= $(SRC:.c=.o)
OBJS 	= $(addprefix $(OBJ_DIR), $(OBJ))

all: obj $(NAME)

obj:
	@rsync -av --include '*/' --exclude '*' --quiet $(SRC_DIR) $(OBJ_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@ 

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(INC) -o $(NAME) $(OBJS)
	@printf "$(GREEN)$(NAME): OK!$(RESET)\n"

clean:
	@$(RM) -Rf $(OBJ_DIR)
	@printf "$(YELLOW)Object files: $(RED)Deleted!$(RESET)\n"

fclean: clean
	@$(RM) -f $(NAME)
	@printf "$(YELLOW)$(NAME): $(RED)Deleted!$(RESET)\n"

re: fclean all

.PHONY: all re clean fclean