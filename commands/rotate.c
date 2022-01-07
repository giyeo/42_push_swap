#include "../pushswap.h"

void	ra(s_node *stack)
{
	s_node *start = stack;
	s_node *last;
	int counter = 0;

	if(more_than_one(stack))
		return ;
	while (stack->next)
	{
		stack = stack->next;
		counter++;
	}
	last = stack;
	stack = start;
	if (counter == 2)
	{
		sa(stack);
		return ;
	}
	last->next = stack->next; 
	stack->next = stack->next->next;
	last->next->next = NULL;
	last->next->previous = last;
	stack->next->previous = stack;
	print_command("ra");
}

void	rb(s_node *stack)
{
	s_node *start = stack;
	s_node *last;
	int counter = 0;

	if(more_than_one(stack))
		return ;
	while (stack->next)
	{
		stack = stack->next;
		counter++;
	}
	last = stack;
	stack = start;
	if (counter == 2)
	{
		sb(stack);
		return ;
	}
	last->next = stack->next; 
	stack->next = stack->next->next;
	last->next->next = NULL;
	last->next->previous = last;
	stack->next->previous = stack;
	print_command("rb");
}

void	rr(s_node *stack_a, s_node *stack_b)
{
	ra(stack_a);
	rb(stack_b);
}