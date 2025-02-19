CC = cc
NAME = push_swap
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
CFLAGS =  -fsanitize=address -g3 

SRC_FILES = push_swap.c \
			push_stack.c \
			rotate_stack.c \
			rrotate_stack.c \
			swap_stack.c \
			stack.c \
			push_swap_utils.c \
			helpers.c \
			args_check.c

OBJ_FILES = $(SRC_FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ_FILES) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJ_FILES) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR) 
	make -C $(LIBFT_DIR) bonus

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: server_bonus client_bonus

clean:
	rm -f $(OBJ_FILES)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

leaks:
	sudo leaks --atExit  --  ./push_swap "66 0 31 87 16 29 20 15 48 81 47 53 52 9 12 1 23"

.PHONY: all clean fclean re leaks