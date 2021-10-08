#include "pushswap.h"

s_node *init_stack()
{
	s_node *stack = (s_node*)malloc(sizeof(s_node));
	stack->next = NULL;
	stack->previous = NULL;
	return (stack);
}

void populate(s_node *stack, int size, char *argv[])
{
	int i = 0;

	stack->next = (s_node*)malloc(sizeof(s_node));
	stack->next->previous = stack;
	stack->previous = NULL;
	stack = stack->next;
	while(i < size - 2)
	{
		stack->next = (s_node*)malloc(sizeof(s_node));
		stack->next->previous = stack;
		stack->value = atoi(argv[i++ + 1]);
		stack = stack->next;
	}
	stack->value = atoi(argv[i + 1]);
	stack->next = NULL;
}

void	free_stack(s_node *stack)
{
	while(stack->next)
		stack = stack->next;
	while(stack->previous)
	{
		stack = stack->previous;
		free(stack->next);
	}
	free(stack);
}