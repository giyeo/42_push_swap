NAME := push_swap
SRC :=	./commands/push.c ./commands/reverse.c ./commands/rotate.c ./commands/swap.c \
		./handlers/handle_error.c ./handlers/handle_init_stack.c \
		./libft/atoi.c ./libft/itoa.c \
		./utils/utils.c ./utils/utils_llists.c ./utils/f_long_atoi.c \
		push_swap.c ./sort/sorting.c ./commands/print_command.c ./handlers/handle_index.c \
		./sort/sort_up_to_five.c ./sort/sort_up_to_n.c

OBJS := $(SRC:.c=.o)

NAME_BONUS := checker
SRC_BONUS := ./commands/push.c ./commands/reverse.c ./commands/rotate.c ./commands/swap.c \
		./handlers/handle_error.c ./handlers/handle_init_stack.c \
		./libft/atoi.c ./libft/itoa.c \
		./utils/utils.c ./utils/utils_llists.c ./utils/f_long_atoi.c \
		./sort/sorting.c ./commands/print_command.c ./handlers/handle_index.c \
		./sort/sort_up_to_five.c ./sort/sort_up_to_n.c \
		./bonus/get_next_line.c ./bonus/get_next_line_utils.c ./bonus/main.c \
		./bonus/commands_checker/push.c ./bonus/commands_checker/swap.c ./bonus/commands_checker/reverse.c \
		./bonus/commands_checker/rotate.c

OBJS_BONUS := $(SRC_BONUS:.c=.o)

FLAG := -fsanitize=address

CFLAG := -Wall -Wextra

all: $(NAME)

bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJS_BONUS)
	gcc $(OBJS_BONUS) -o $(NAME_BONUS) $(CFLAG) $(FLAG)

$(NAME): $(OBJS)
	gcc $(OBJS) -o $(NAME) $(CFLAG) $(FLAG)

%.o: %.c
	gcc $(CFLAG) -c $< -o $@

.PHONY: clean fclean re all

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME_BONUS)

re: fclean all