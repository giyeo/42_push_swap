NAME := push_swap
SRC :=	./commands/push.c ./commands/reverse.c ./commands/rotate.c ./commands/swap.c \
		./handlers/handle_error.c ./handlers/handle_init_stack.c \
		./libft/atoi.c ./libft/itoa.c \
		./utils/utils.c ./utils/utils_llists.c ./utils/f_long_atoi.c \
		pushswap.c sorting.c yprint_stacks.c indexator.c

OBJS := $(SRC:.c=.o)

FLAG := -fsanitize=address

CFLAG := -Wall -Wextra

all: $(NAME)

bonus: all

$(NAME): $(OBJS)
	gcc $(OBJS) -o $(NAME) $(CFLAG) $(FLAG)

%.o: %.c
	gcc $(CFLAG) -c $< -o $@

.PHONY: clean fclean re all

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all