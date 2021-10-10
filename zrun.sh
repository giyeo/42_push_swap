gcc -o pushswap pushswap.c handle_error.c utils.c handle_init_stack.c f_itoa.c \
zprint_stacks.c f_long_atoi.c command_swap.c command_push.c utils_llists.c \
command_rotate.c command_reverse.c sorting.c -fsanitize=address