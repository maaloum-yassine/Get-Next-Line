# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ymaaloum <ymaaloum@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/06 04:51:25 by ymaaloum          #+#    #+#              #
#    Updated: 2024/06/11 15:40:26 by ymaaloum         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC				=	cc
CCFLAGS			=	-Wall -Wextra -Werror
NAME			=	getnextline
NAME_BONUS		=	getnextline_bonus

SRC			=	./mandatory/get_next_line.c \
				./mandatory/get_next_line_utils.c \
				./mandatory/main.c

SRC_BONUS		=	./bonus/get_next_line_bonus.c \
				./bonus/get_next_line_utils_bonus.c \
				./bonus/main_bonus.c

RESET			=	\033[1;97m
GREEN			=	\033[1;32m
RED			=	\033[1;31m

OBJ_DIR			=	obj/
OBJ			=	$(patsubst ./mandatory/%.c,$(OBJ_DIR)%.o,$(SRC))
OBJ_BONUS		=	$(patsubst ./bonus/%.c,$(OBJ_DIR)%.o,$(SRC_BONUS))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@echo "$(GREEN)$(OBJ_DIR) : Created ! [^_^]$(RESET)"
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ)
	$(CC) $(CCFLAGS) $(OBJ) -o $(NAME)
	@echo "$(GREEN)$(NAME) : Created ! [^_^]$(RESET)"

$(OBJ_DIR)%.o: ./mandatory/%.c
	$(CC) $(CCFLAGS) -c $< -o $@

bonus: $(OBJ_DIR) $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_BONUS)
	@$(CC) $(CCFLAGS) $(OBJ_BONUS) -o $(NAME_BONUS)
	@echo "$(GREEN)$(NAME_BONUS) : Created ! [^_^]$(RESET)"

$(OBJ_DIR)%.o: ./bonus/%.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@echo "$(RED)$(NAME) : obj directory deleted ! [^_^]$(RESET)"

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "$(RED)$(NAME) and $(NAME_BONUS) : obj directory and executable files deleted ! [^_^]$(RESET)"

re: fclean all
