# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jboeve <jboeve@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2022/10/17 12:05:02 by jboeve        #+#    #+#                  #
#    Updated: 2023/04/17 11:42:15 by jboeve        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft/build/libft.a

CFLAGS = -Wall -Wextra -Werror
# CFLAGS += -g -fsanitize=address
# CFLAGS = -g

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


TEST_DIR = tests
TESTS = test_sort_small_2.c \
		test_sort_small_3.c \
		test_sort_small_4.c \
		test_sort_small_5.c \
		test_sort_small_6.c \
		test_ft_atol.c \
		test_apply_offset.c \
		test_create_stack_a.c

TESTS_UTILS = test_push_swap.c
TESTS_UTILS := $(addprefix $(TEST_DIR)/, $(TESTS_UTILS))
TESTS := $(addprefix $(TEST_DIR)/, $(TESTS))
TEST_INC = -I/Users/jboeve/homebrew/include -L/Users/jboeve/homebrew/lib
TEST_BIN_DIR = bin
TEST_BIN_DIR := $(addprefix $(TEST_DIR)/, $(TEST_BIN_DIR))
TEST_BINS = $(patsubst $(TEST_DIR)/%.c, $(TEST_DIR)/bin/%, $(TESTS))

ifdef TEST_BUILD
CFLAGS += -DBUILD_TESTER
endif

.PHONY: make_libft clean fclean re run compile_commands dfclean dre

all: make_libft $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(OBJS) $(LIBFT) $(CFLAGS) $(INC) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

make_libft:
	$(MAKE) -C libft

clean:
	rm -rf $(OBJ_DIR)
	rm -rf $(TEST_BIN_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean dfclean all

run: all
	# python3 tests/test_return_value.py
	# ./$(NAME) 3 1 2 5 7 9 4 33 -2147483648 2147483647 
	./$(NAME)

mem:
	memdetect/memdetect.sh . $(CFLAGS) $(INC) $(TEST_INC) --exclude push_swap_visualizer --exclude tests

compile_commands: dfclean fclean
	$(MAKE) | compiledb

dfclean:
	$(MAKE) -C libft fclean
dre:
	$(MAKE) -C libft re

$(TEST_BIN_DIR)/%: $(TEST_DIR)/%.c
	@mkdir -p $(TEST_BIN_DIR)
	$(CC) $(CFLAGS) $(INC) $(TEST_INC) $< $(OBJS) $(TESTS_UTILS) $(LIBFT) -o $@ -lcriterion 

.PHONY: build_test
build_test: $(LIBFT) $(OBJS) $(TEST_BINS)
	# @for test in $(TEST_BINS) ; do ./$$test -j4; done
	# ./tests/bin/test_sort_small_2
	# ./tests/bin/test_sort_small_3
	# ./tests/bin/test_sort_small_4
	# ./tests/bin/test_sort_small_5
	# ./tests/bin/test_sort_small_6
	# ./tests/bin/test_create_stack_a
	# ./tests/bin/test_ft_atol

test:
	$(MAKE) clean
	$(MAKE) build_test TEST_BUILD=1

