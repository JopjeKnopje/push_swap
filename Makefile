# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jboeve <jboeve@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/17 12:05:02 by jboeve        #+#    #+#                  #
#    Updated: 2023/01/26 18:06:50 by joppe         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = app

LIBFT = libft/build/libft.a

CFLAGS = -Wall -Wextra -Werror
# CFLAGS += -g -fsanitize=address

INC = -Ilibft/include
# INC = -Ilibft -I/usr/include/bsd

SRC_DIR = src
SRCS = main.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ_DIR = obj
OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) $(CFLAGS) $(INC) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

.PHONY: $(LIBFT)
$(LIBFT):
	$(MAKE) -C libft bonus

clean:
	rm -fr $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean dfclean all

run: all
	./$(NAME)

compile_commands: dfclean fclean
	compiledb -- make

dfclean:
	$(MAKE) -C libft fclean
dre:
	$(MAKE) -C libft re


