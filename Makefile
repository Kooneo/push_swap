CC = cc
NAME = push_swap
CHECKER = checker
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
CFLAGS = -Wall -Werror -Wextra

SRC_FILES = push_stack.c \
			rotate_stack.c \
			rrotate_stack.c \
			swap_stack.c \
			stack.c \
			push_swap_utils.c \
			helpers.c \
			push_swap_utils_2.c \
			args_check.c

PUSH_SWAP_FILES = push_swap.c \
					push_swap_algo.c \
					push_back.c \
					sort_three.c \
					sort_four.c \
					sort_five.c 
CHECKER_FILES =	checker_bonus.c

OBJ_FILES = $(SRC_FILES:.c=.o) $(PUSH_SWAP_FILES:.c=.o)
BONUS_OBJ_FILES = $(SRC_FILES:.c=.o) $(CHECKER_FILES:.c=.o)

all: $(NAME)

bonus: $(CHECKER)

$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) -o $(NAME)

$(CHECKER): $(BONUS_OBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJ_FILES) $(LIBFT) -o $(CHECKER)

$(LIBFT):
	make -C $(LIBFT_DIR) 
	make -C $(LIBFT_DIR) bonus

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_FILES) $(BONUS_OBJ_FILES)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) $(CHECKER)
	make -C $(LIBFT_DIR) fclean

re: fclean all

leaks:
	sudo leaks --atExit  --  ./push_swap "66 0 31 87 16 29 20 15 48 81 47 53 52 9 12 1 23"

.PHONY: all clean fclean re leaks bonus
.SECONDARY: $(OBJ_FILES) $(BONUS_OBJ_FILES)