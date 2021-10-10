#include "pushswap.h"

/*The last becomes the first!*/

void	rra(s_node *stack)
{
	s_node *start = stack;
	s_node *last;
	s_node *temp;
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
	last->previous->next = NULL;
	stack->next = last;
	last->previous = stack;
	last->next->previous = last;
}

void	rrb(s_node *stack)
{
	s_node *start = stack;
	s_node *last;
	s_node *temp;
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
	last->previous->next = NULL;
	stack->next = last;
	last->previous = stack;
	last->next->previous = last;
}

void	rrr(s_node *stack_a, s_node *stack_b)
{
	rra(stack_a);
	rrb(stack_b);
}