#include "pushswap.h"

void	last_to_first_n();

void	first_to_last_n();

void	put_on_top_of_n();

void	swap_the_top_of_n();

void sort(s_node *stack_a, s_node *stack_b)
{
	print_stacks(stack_a, stack_b);
}

void	errors_handler(int argc, char *argv[])
{
	isfewarg_handler(argc, argv);
	isnumber_handler(argc, argv);
	isbigger_handler(argc, argv);
	isduplic_handler(argc, argv);
}

int main(int argc, char *argv[])
{
	s_node *stack_a;
	s_node *stack_b;

	errors_handler(argc, argv);
	stack_a = init_stack();
	stack_b = init_stack();
	populate(stack_a, argc, argv);
	sort(stack_a, stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
}
