# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amatthys <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/18 17:40:49 by amatthys          #+#    #+#              #
#    Updated: 2018/06/25 13:26:41 by amatthys    ###    #+. /#+    ###.fr      #
#                                                                              #
# **************************************************************************** #
RELATIVE = .

SRC_CHECK = checker.c
SRC_PUSHS = push_swap.c

SRC_PATH = src
SRC_NAME = check_file.c create_tab.c ope1.c ope2.c ope3.c \
		   print_op.c sort_3.c sort_tab.c split.c find_median.c

SRC_ALL = $(addprefix $(SRC_PATH)/, $(SRC_NAME))
SRC_CHE = $(addprefix $(SRC_PATH)/, $(SRC_CHECK))
SRC_PUSH = $(addprefix $(SRC_PATH)/, $(SRC_PUSHS))

LIB = ./libft/libft.a

OBJ_ALL = $(SRC_ALL:.c=.o)
OBJ_CHE = $(SRC_CHE:.c=.o)
OBJ_PUSH = $(SRC_PUSH:.c=.o)

INCLUDES_PATH = includes

NAME = $(NAME1) $(NAME2)

NAME1 = push_swap
NAME2 = checker

CC = gcc
CFLAGS = -Wall -Werror -Wextra
CPPFLAGS = -I $(INCLUDES_PATH)

.PHONY: clean fclean all re

all : $(NAME)

$(LIB):
		make -C libft/

$(NAME1): $(OBJ_PUSH) $(OBJ_ALL) $(LIB)
		gcc -o $(NAME1) $(OBJ_PUSH) $(OBJ_ALL) -L libft -l ft

$(NAME2): $(OBJ_CHE) $(OBJ_ALL) $(LIB)
		gcc -o $(NAME2) $(OBJ_CHE) $(OBJ_ALL) -L libft -l ft

%.o: $(SRC_PUSH)%.c $(SRC_CHE)%.c $(SRC_ALL)%.c
		gcc -I $(HEADERS) $(FLAGS) -c $(SRC_PUSH) $(SRC_CHE) $(SRC_ALL)

clean:
		rm -rf $(OBJ_ALL) $(OBJ_CHE) $(OBJ_PUSH)
		make clean -C libft/

fclean: clean
		rm -rf $(NAME1) $(NAME2)
		make fclean -C libft/

re : fclean all
