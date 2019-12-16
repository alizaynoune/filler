# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alzaynou <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/27 22:53:55 by alzaynou          #+#    #+#              #
#    Updated: 2019/12/09 18:47:57 by alzaynou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = nextlib.a
FLAGS = -Wall -Werror -Wextra
PATH_N = ./
PATH_L = ../libft/
OBJ_P = objs/
INCLUDS = -I $(OBJ_P) -I ./
SRC_N = get_next_line.c
SRC_L = ft_atoi.c		\
		ft_bzero.c		\
		ft_isalnum.c	\
		ft_isalpha.c	\
		ft_isascii.c	\
		ft_isdigit.c	\
		ft_isprint.c	\
		ft_itoa.c		\
		ft_lstadd.c		\
		ft_lstdel.c		\
		ft_lstdelone.c	\
		ft_lstiter.c	\
		ft_lstmap.c		\
		ft_lstnew.c		\
		ft_memalloc.c	\
		ft_memccpy.c	\
		ft_memchr.c		\
		ft_memcmp.c		\
		ft_memcpy.c		\
		ft_memdel.c		\
		ft_memmove.c	\
		ft_memset.c		\
		ft_putchar.c	\
		ft_putchar_fd.c	\
		ft_putendl.c	\
		ft_putendl_fd.c	\
		ft_putnbr.c		\
		ft_putnbr_fd.c	\
		ft_putstr.c		\
		ft_putstr_fd.c	\
		ft_strcat.c		\
		ft_strchr.c		\
		ft_strclr.c		\
		ft_strcmp.c		\
		ft_strcpy.c		\
		ft_strdel.c		\
		ft_strdup.c		\
		ft_strequ.c		\
		ft_striter.c	\
		ft_striteri.c	\
		ft_strjoin.c	\
		ft_strlcat.c	\
		ft_strlen.c		\
		ft_strmap.c		\
		ft_strmapi.c	\
		ft_strncat.c	\
		ft_strncmp.c	\
		ft_strncpy.c	\
		ft_strnequ.c	\
		ft_strnew.c		\
		ft_strnstr.c	\
		ft_strrchr.c	\
		ft_strsplit.c	\
		ft_strstr.c		\
		ft_strsub.c		\
		ft_strtrim.c	\
		ft_tolower.c	\
		ft_toupper.c

OBJS = $(addprefix $(OBJ_P), $(SRC_L:.c=.o))
OBJS := $(OBJS) $(addprefix $(OBJ_P), $(SRC_N:.c=.o))
all: $(NAME)
$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo "\x1B[96mLibrary File \x1B[90;0m[\x1B[34;1m next_line $(notdir $@) \x1B[90;0m] \x1B[32mCreated.\x1B[39;0m"
$(OBJ_P)%.o: $(PATH_L)%.c
	@mkdir -p $(OBJ_P)
	@gcc -c $(FLAGS) $< -o $@ $(INCLUDS)
	@echo "\x1B[96mObject File \x1B[90;0m[\x1B[34;1m next_line $(notdir $@) \x1B[90;0m] \x1B[32mCreated.\x1B[39;0m"
$(OBJ_P)%.o: $(PATH_N)%.c
	@mkdir -p $(OBJ_P)
	@gcc -c $(FLAGS) $< -o $@ $(INCLUDS)
	@echo "\x1B[96mObject File \x1B[90;0m[\x1B[34;1m next_line $(notdir $@) \x1B[90;0m] \x1B[32mCreated.\x1B[39;0m"
clean:
	@/bin/rm -rf $(OBJ_P)
	@echo "\x1B[96mObjects path \x1B[90;0m[\x1B[34;1m next_line $(OBJ_P) \x1B[90;0m] \x1B[31mDeleted.\x1B[39;0m"
fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\x1B[96mLibrary File \x1B[90;0m[\x1B[34;1m next_line $(NAME) \x1B[90;0m] \x1B[31mDeleted.\x1B[39;0m"
re: fclean all
.PHONY: fclean clean re all
