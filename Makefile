# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jboeve <jboeve@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/17 12:05:02 by jboeve        #+#    #+#                  #
#    Updated: 2023/03/16 23:03:54 by joppe         ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft/build/libft.a

CFLAGS = -Wall -Wextra -Werror

INC = -Ilibft/include -Iinclude 

SRC_DIR = src
SRCS = main.c \
	   stack.c \
	   stack_utils.c \
	   operatons.c \
	   utils.c \
	   parser.c \
	   moves.c \
	   sort.c \
	   radix.c

SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))

HEADER_DIR = include
HEADERS = push_swap.h
HEADERS := $(addprefix $(HEADER_DIR)/, $(HEADERS))

OBJ_DIR = obj
OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))


all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) $(CFLAGS) $(INC) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

.PHONY: $(LIBFT)
$(LIBFT):
	$(MAKE) -C libft

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(TEST_BIN_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean dfclean all

run: all
	# python3 tests/test_return_value.py
	./$(NAME) 3 1 2 5 7 9 4 33

compile_commands: dfclean fclean
	$(MAKE) | compiledb

dfclean:
	$(MAKE) -C libft fclean
dre:
	$(MAKE) -C libft re
