NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c main.c validations.c sort.c operations_single.c \
	   operations_multi.c utils/sort_utils.c utils/stack_utils.c utils/args_utils.c \
	   utils/ft_error.c find.c modes.c

OBJS = $(SRCS:.c=.o)

LIBFT_DIR = Libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)
	make bonus -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

