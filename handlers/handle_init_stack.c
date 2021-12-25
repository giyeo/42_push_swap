#include "../pushswap.h"

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
#include <stdio.h>

void	delete_from_array(int *array)
{
	int i;

	i = 0;
	while(array[i++]);
}

void	index_it(s_node *stack, char *argv[])
{
	int n = 1;
	int i = 1;
	int *array;
	while(argv[n])
	 	argv[n++];
	array = (int *)malloc(sizeof(int) * (n - 1));
	while(n--)
	{
		printf("[%d]", i);
		printf("{%d}\n", ft_atoi(argv[i]));
		array[i-1] = ft_atoi(argv[i++]);
	}
	free(array);
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