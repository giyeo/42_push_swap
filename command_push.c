#include "pushswap.h"

void	pa(s_node *stack_a, s_node *stack_b)
{
	if(more_than_one(stack_a))
		return ;
	s_node *node = (s_node*)malloc(sizeof(s_node));

	s_node *to_free = stack_a->next;

	if(stack_b->next == NULL)
	{
		stack_b->next = node;
		stack_b->next->value = stack_a->next->value;
		stack_b->next->previous = stack_b;
		stack_b->next->next = NULL;
	}
	else
	{
		node->value = stack_a->next->value;
		node->next = stack_b->next;
		stack_b->next = node;
		node->previous = stack_b;
		node->next->previous = node;
	}
	if(stack_a->next->next == NULL)
		stack_a->next = NULL;
	else
	{
		stack_a->next = stack_a->next->next;
		stack_a->next->previous = stack_a;
	}
	free(to_free);
}

void	pb(s_node *stack_a, s_node *stack_b)
{
	if(more_than_one(stack_b))
		return ;
	s_node *node = (s_node*)malloc(sizeof(s_node));

	s_node *to_free = stack_b->next;

	if(stack_a->next == NULL)
	{
		stack_a->next = node;
		stack_a->next->value = stack_b->next->value;
		stack_a->next->previous = stack_a;
		stack_a->next->next = NULL;
	}
	else
	{
		node->value = stack_b->next->value;
		node->next = stack_a->next;
		stack_a->next = node;
		node->previous = stack_a;
		node->next->previous = node;
	}
	if(stack_b->next->next == NULL)
		stack_b->next = NULL;
	else
	{
		stack_b->next = stack_b->next->next;
		stack_b->next->previous = stack_b;
	}
	free(to_free);
}