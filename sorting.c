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

s_node	*last_node(s_node *stack)
{
	while(stack->next)
		stack = stack->next;
	return (stack);
}

void	push_to_b(s_node *stack_a, s_node *stack_b, int times)
{
	int i;

	i = 0;
	if (times == 0)
		return ;
	while(i++ < times)
		pa(stack_a, stack_b);
}

void	push_to_a(s_node *stack_a, s_node *stack_b)
{
	while(stack_b->next)
		pb(stack_a, stack_b);
}

void sort(s_node *stack_a, s_node *stack_b)
{
	int len = stack_length(stack_a);
	s_node *last_a = last_node(stack_a);

	print_stacks(stack_a, stack_b);

	if(more_than_one(stack_a))
		return ;
	if(len == 2)
		if (FIRST_NODE_A->value > SECOND_NODE_A->value)
			sa(stack_a);

	int run = 1;
	int counter = 0;
	s_node *node;
	while(run)
	{
		if (stack_a->next)
			node = stack_a->next;
		else
			node = stack_a;
		run = 0;
		counter = 0;
		while(node->next)
		{
			if(node->value > node->next->value)
			{
				push_to_b(stack_a, stack_b, counter);
				run = 1;
				sa(stack_a);
			}
			node = node->next;
			counter++;
		}
		push_to_a(stack_a, stack_b);
	}


	print_stacks(stack_a, stack_b);
}