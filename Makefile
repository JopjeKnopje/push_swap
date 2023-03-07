# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jboeve <jboeve@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/17 12:05:02 by jboeve        #+#    #+#                  #
#    Updated: 2023/03/07 11:38:26 by jboeve        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft/build/libft.a

# CFLAGS = -Wall -Wextra -Werror
CFLAGS += -g -fsanitize=address
CFLAGS += -DBUILD_TESTER

INC = -Ilibft/include -Iinclude 

SRC_DIR = src
SRCS = main.c stack.c operatons.c utils.c parser.c moves.c sort.c
SRCS := $(addprefix $(SRC_DIR)/, $(SRCS))

HEADER_DIR = include
HEADERS = push_swap.h
HEADERS := $(addprefix $(HEADER_DIR)/, $(HEADERS))

OBJ_DIR = obj
OBJS = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRCS))


TEST_DIR = tests
TESTS = test_sort_3.c test_sort_5.c
TESTS_UTILS = test_push_swap.c
TESTS_UTILS := $(addprefix $(TEST_DIR)/, $(TESTS_UTILS))
TESTS := $(addprefix $(TEST_DIR)/, $(TESTS))
TEST_INC = -I/Users/jboeve/homebrew/include -L/Users/jboeve/homebrew/lib
TEST_BIN_DIR = bin
TEST_BIN_DIR := $(addprefix $(TEST_DIR)/, $(TEST_BIN_DIR))
TEST_BINS = $(patsubst $(TEST_DIR)/%.c, $(TEST_DIR)/bin/%, $(TESTS))



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
	@# ./$(NAME) 1 4 2 5 -3 6 8 9 7
	@# ./$(NAME) 87 -487 781 -100 101 0 1
	# ./$(NAME) 1 5 2 3 4
	# ./$(NAME) 4 5 1 2 3 
	./$(NAME) 1 2 5 3 4
	@# python3 generator.py | wc -l


compile_commands: dfclean fclean
	$(MAKE) | compiledb

dfclean:
	$(MAKE) -C libft fclean
dre:
	$(MAKE) -C libft re

$(TEST_BIN_DIR)/%: $(TEST_DIR)/%.c
	@mkdir -p $(TEST_BIN_DIR)
	$(CC) $(CFLAGS) $(INC) $(TEST_INC) $< $(OBJS) $(TESTS_UTILS) $(LIBFT) -o $@ -lcriterion 

test: $(LIBFT) $(OBJS) $(TEST_BINS)
	@for test in $(TEST_BINS) ; do ./$$test -j 1 ; done
