#include "pushswap.h"

void sa(s_node *stack)
{
	int value1;

	if(stack->next)
		if(stack->next->next)
		{
			value1 = stack->next->value;
			stack->next->value = stack->next->next->value;
			stack->next->next->value = value1;
		}
}

void sb(s_node *stack)
{
	int value1;

	if(stack->next)
		if(stack->next->next)
		{
			value1 = stack->next->value;
			stack->next->value = stack->next->next->value;
			stack->next->next->value = value1;
		}
}

void ss(s_node *stack_a, s_node *stack_b)
{
	sa(stack_a);
	sb(stack_b);
}