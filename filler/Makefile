# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 21:54:28 by alzaynou          #+#    #+#              #
#    Updated: 2019/12/12 17:43:49 by alzaynou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = alzaynou.filler
FLAGS = -Wall -Werror -Wextra
INCLD = ./includes
OBJ_P = objs/
SRC_P = ./srcs/
LIB = next_line/nextlib.a
VISU = visu

SRC_V = visual/main.c
SRC_F = filler.c	\
		fighter.c	\
		tools.c		\
		tools2.c	\
		maps.c		\
		ft_free.c	\
		maps2.c

OBJS = $(addprefix $(OBJ_P), $(SRC_F:.c=.o))
all: $(NAME) $(VISU)
$(VISU):
	gcc $(FLAG) $(SRC_V) -I $(INCLD) $(LIB) -o $(VISU)
$(NAME): $(OBJS)
	@make -C next_line/
	@gcc $(FLAGS) $(OBJS) $(LIB) -o $(NAME)
	@echo "\x1B[96mBinary File \x1B[90;0m[\x1B[34;1m $(notdir $@) \x1B[90;0m] \x1B[32mCreated.\x1B[39;0m"
$(OBJ_P)%.o: $(SRC_P)%.c
	@mkdir -p $(OBJ_P)
	@gcc -c $(FLAGS) $< -o $@ -I $(INCLD)
	@echo "\x1B[96mObject File \x1B[90;0m[\x1B[34;1m $(notdir $@) \x1B[90;0m] \x1B[32mCreated.\x1B[39;0m"
clean:
	@/bin/rm -rf $(OBJ_P)
	@make clean -C next_line/
	@echo "\x1B[96mObjects path \x1B[90;0m[\x1B[34;1m $(OBJ_P) \x1B[90;0m] \x1B[31mDeleted.\x1B[39;0m"
fclean: clean
	@/bin/rm -f $(NAME)
	@/bin/rm -f $(LIB)
	@/bin/rm -f $(VISU)
	@echo "\x1B[96mLibrary File \x1B[90;0m[\x1B[34;1m $(LIB) \x1B[90;0m] \x1B[31mDeleted.\x1B[39;0m"
	@echo "\x1B[96mBinary File \x1B[90;0m[\x1B[34;1m $(NAME) \x1B[90;0m] \x1B[31mDeleted.\x1B[39;0m"
re: fclean all
.PHONY: fclean clean re all vissu
