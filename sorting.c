#include "pushswap.h"

int	stack_length(s_node *stack)
{
	int counter;

	counter = 0;
	while (stack->next)
	{
		stack = stack->next;
		counter++;
	}
	return (counter);
}

void sort(s_node *stack_a, s_node *stack_b)
{
	int len = stack_length(stack_a);

	print_stacks(stack_a, stack_b);
	if(more_than_one(stack_a))
		return ;
	if(len == 2)
		if (stack_a->next->value > stack_a->next->next->value)
			sa(stack_a);
	print_stacks(stack_a, stack_b);
}